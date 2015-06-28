#include "unique_sound.h"
#include "manager.h"
#include "saferelease.h"

namespace sim
{
	void unique_sound::construct()
	{
		pSoundData = 0;	// NULL
		ownership = false;
		secondarysb = nullptr;
	}

	unique_sound::unique_sound()
	{
		construct();
	}
	unique_sound::unique_sound(uint uID)
	{
		construct();
		load(uID);
	}
	unique_sound::unique_sound(const sound_data & soundd)
	{
		construct();
		set_sound_data(soundd);
	}

	bool unique_sound::load(uint uID)
	{
		sound_data * pSoundData = new sound_data();
		bool bResult = pSoundData->load(uID);
		set_sound_data(*pSoundData);
		ownership = true;

		return bResult;
	}
	bool unique_sound::set_sound_data(const sound_data & soundd)
	{
		bool bResult = true;
		release();

		pSoundData = &soundd;
		ownership = false;


		bResult = pSoundData->create_buffer(secondarysb);
		secondarysb->GetFrequency(&BaseFreq);

		return bResult;
	}

	void unique_sound::replay()	// �Đ����J�n����B���ɍĐ����Ȃ�ŏ�����Đ�������
	{
		replay(false);
	}
	void unique_sound::reloop()	// ���[�v�Đ����J�n����B���ɍĐ����Ȃ�ŏ�����Đ�������
	{
		replay(true);
	}
	void unique_sound::stop()
	{
		secondarysb->Stop();
		secondarysb->SetCurrentPosition(0);
	}
	void unique_sound::replay(bool bLoopFlag)
	{
		DWORD dwFlag = NULL;
		if (bLoopFlag) dwFlag = DSBPLAY_LOOPING;

		stop();
		HRESULT result = secondarysb->Play(NULL, 0, dwFlag);

		if (result == DSERR_BUFFERLOST)	// �o�b�t�@���X�g�̏ꍇ�̓Z�J���_���o�b�t�@���쐬������
		{
			secondarysb->Restore();
			pSoundData->create_buffer(secondarysb);
			secondarysb->GetFrequency(&BaseFreq);
		}
	}


	void unique_sound::release()
	{
		if (ownership)
		{
			if(pSoundData)
			{
				delete pSoundData;
			}
		}

		pSoundData = 0;	// NULL

		saferelease(secondarysb);
	}

	unique_sound::~unique_sound()
	{
		release();
	}

}