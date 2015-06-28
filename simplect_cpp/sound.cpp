#include "sound.h"
#include "dx9sound.h"
#include "saferelease.h"

namespace sim
{
	sound::sound()
	{
		construct();
	}
	sound::sound(const char * path)
	{
		construct();
		load(path);
	}
	sound::sound(const std::string & path)
	{
		construct();
		load(path);
	}

	bool sound::load(const char * path)
	{
		::sim::sound_data * soundd = new ::sim::sound_data(path);
		owner_ship = true;
		return this->sound_data(*soundd);
	}
	bool sound::load(const std::string & path)
	{
		return load(path.c_str());
	}

	bool sound::sound_data(const ::sim::sound_data & soundd)
	{
		release();
		this->soundd = &soundd;

		return soundd.create_secondarysb(secondarysb, BaseFreq);
	}


	void sound::play()
	{
		HRESULT result = secondarysb->Play(NULL, 0, NULL);
		if (result == DSERR_BUFFERLOST)
		{
			secondarysb->Restore();
			load(WaveFilePath);
		}
	}
	void sound::play(bool LoopFlag)
	{
		DWORD flag = NULL;
		if (LoopFlag) flag = DSBPLAY_LOOPING;
		secondarysb->Play(NULL, 0, flag);
	}

	void sound::loop()
	{
		play(true);
	}

	void sound::stop()
	{
		pause();
		reset();
	}
	void sound::pause()
	{
		secondarysb->Stop();
	}

	void sound::reset()
	{
		secondarysb->SetCurrentPosition(0);
	}

	void sound::replay()
	{
		reset();
		play();
	}
	void sound::reloop()
	{
		reset();
		loop();
	}
	void sound::replay(bool LoopFlag)
	{
		reset();
		play(LoopFlag);
	}

	void sound::volume(LONG vol)
	{
		secondarysb->SetVolume(vol);
	}
	LONG sound::volume()
	{
		LONG vol;
		secondarysb->GetVolume(&vol);
		return vol;
	}

	void sound::freq(float mag)
	{
		freq_magni = mag;
		DWORD Freq = DWORD(BaseFreq*mag);
		DSCAPS cap;
		SoundParent::GetInterface()->GetCaps(&cap);
		if (Freq < cap.dwMinSecondarySampleRate) Freq = cap.dwMinSecondarySampleRate;
		if (Freq > cap.dwMaxSecondarySampleRate) Freq = cap.dwMinSecondarySampleRate;
		secondarysb->SetFrequency(Freq);
	}
	float sound::freq()
	{
		return freq_magni;
	}

	uint sound::position()
	{
		DWORD dwPosition;
		secondarysb->GetCurrentPosition(&dwPosition, nullptr);
		return static_cast<uint>(dwPosition);
	}
	void sound::position(uint value)
	{
		secondarysb->SetCurrentPosition(value);
	}

	sound::~sound()
	{
		stop();
		saferelease(secondarysb);
		release();
	}

	void sound::construct()
	{
		soundd = nullptr;
		owner_ship = false;
	}

	void sound::release()
	{
		if (owner_ship)
		{
			delete this->soundd;
		}

		soundd = nullptr;
		owner_ship = false;
	}
}