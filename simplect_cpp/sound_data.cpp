#include "sound_data.h"
#include "sound_manager.h"
#include "manager.h"
#include "saferelease.h"

namespace sim
{

	bool sound_data::load(uint uID)
	{
		this->uID = uID;

		sound_manager & soundm = manager::get_sound_manager();
		const char * path = soundm.get_path(uID);

		// WAVEファイルを開く
		if (wav_data.load(path) == false)
		{
			if (fw::iffile(path))
			{
				fw::popup("failed to load Wave File");
			}
			else
			{
				fw::popup("Not Found Wave File");
			}

			return false;
		}

		// WAVEFORMATEX構造体を設定
		wfe.wFormatTag = wav_data.wFormatTag();
		wfe.nChannels = wav_data.nChannels();
		wfe.nSamplesPerSec = wav_data.nSamplesPerSec();
		wfe.nAvgBytesPerSec = wav_data.nAvgBytesPerSec();
		wfe.nBlockAlign = wav_data.nBlockAlign();
		wfe.wBitsPerSample = wav_data.wBitsPerSample();
		wfe.cbSize = wav_data.cbSize();

		// DSBUFFERDESC構造体を設定
		ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
		dsbdesc.dwSize = sizeof(DSBUFFERDESC);
		dsbdesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS |
			DSBCAPS_LOCDEFER | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY;
		dsbdesc.dwBufferBytes = wav_data.size();
		dsbdesc.guid3DAlgorithm = DS3DALG_DEFAULT;
		dsbdesc.lpwfxFormat = &wfe;



		return true;
	}

	uint sound_data::getID() const
	{
		return uID;
	}


	bool sound_data::create_buffer(IDirectSoundBuffer8 * & secondarysb) const
	{
		HRESULT hr;

		sound_manager & soundm = manager::get_sound_manager();

		// バッファを作る
		LPDIRECTSOUNDBUFFER pDSB;
		hr = soundm.get_interface()->CreateSoundBuffer(&dsbdesc, &pDSB, NULL);
		if (FAILED(hr))
		{
			fw::popup("failed to secondary buffer");
			return false;
		}
		hr = pDSB->QueryInterface(IID_IDirectSoundBuffer8, reinterpret_cast<LPVOID *>(&secondarysb));
		saferelease(pDSB);
		if (FAILED(hr))
		{
			fw::popup("IDirectSoundBuffer8インターフェイスの取得に失敗");
			return false;
		}

		// セカンダリ・バッファにWaveデータを書き込む
		LPVOID lpvPtr1; 	// 最初のブロックのポインタ
		DWORD dwBytes1; 	// 最初のブロックのサイズ
		LPVOID lpvPtr2; 	// ２番目のブロックのポインタ
		DWORD dwBytes2; 	// ２番目のブロックのサイズ

		hr = secondarysb->Lock(0, wav_data.size(), &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);

		// DSERR_BUFFERLOSTが返された場合，Restoreメソッドを使ってバッファを復元する
		if (DSERR_BUFFERLOST == hr)
		{
			secondarysb->Restore();
			hr = secondarysb->Lock(0, wav_data.size(), &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);
		}
		if (FAILED(hr))
		{
			fw::popup("failed to lock secondary buffer");
			return false;
		}

		// ロック成功

		// ここで，バッファに書き込む
		// バッファにデータをコピーする
		memcpy(lpvPtr1, wav_data.data(), dwBytes1);
		if (0 != dwBytes2) memcpy(lpvPtr2, fw::pointer_cast<const char *>(wav_data.data()) + dwBytes1, dwBytes2);

		// 書き込みが終わったらすぐにUnlockする．
		hr = secondarysb->Unlock(lpvPtr1, dwBytes1, lpvPtr2, dwBytes2);
		if (FAILED(hr)) return false;

		return true;
	}




	sound_data::sound_data()
	{
		construct();
	}
	sound_data::sound_data(uint uID)
	{
		construct();
		load(uID);
	}


	void sound_data::construct()
	{
		// Nothing
	}

}