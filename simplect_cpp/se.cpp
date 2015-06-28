#include "se.h"

namespace sim
{
	// nMaxMoment�ŁA�����ɍĐ��ł���se�̍ő吔��ݒ肷��B
	// ���̐��l���傫���قǃ������͑���������B
	// �ȗ������ꍇ�̓f�t�H���g�l(16)���g�p�����B
	se::se()
	{
		construct();
	}
	se::se(uint uID)
	{
		construct();
		load(uID);
	}
	se::se(uint uID, int nMaxMoment)
	{
		construct();
		load(uID, nMaxMoment);
	}
	se::se(const sound_data & soundd)
	{
		construct();
		set_sound_data(soundd);
	}
	se::se(const sound_data & soundd, int nMaxMoment)
	{
		construct();
		set_sound_data(soundd, nMaxMoment);
	}

	bool se::load(uint uID)
	{
		return load(uID, 16);
	}
	bool se::load(uint uID, int nMaxMoment)
	{
		bool bResult = true;

		sound_data * pSoundData = new sound_data();
		bResult = pSoundData->load(uID);
		if (bResult == false) return false;

		bResult = set_sound_data(*pSoundData, nMaxMoment);

		bOwnerShip = true;

		return bResult;
	}
	bool se::set_sound_data(const sound_data & soundd)
	{
		return set_sound_data(soundd, 16);
	}
	bool se::set_sound_data(const sound_data & soundd, int nMaxMoment)
	{
		bool bResult = true;


		release();
		pSoundData = &soundd;

		se_list.setsize(nMaxMoment);

		for(uint uIndex=0;uIndex<se_list.size();++uIndex)
		{
			if (se_list[uIndex].set_sound_data(soundd) == false)
			{
				bResult = false;
			}
		}

		return bResult;
	}

	// �V�����Đ����J�n����B
	// ���ɍĐ�����Ă�����̂ɉe����^���邱�Ƃ͂Ȃ��A�t�ɉe�����󂯂邱�Ƃ��Ȃ��B
	// �����������ɍĐ��ł���se�̍ő吔�𒴂����ꍇ�A�ł��Â����̂̍Đ����~������A�V�����Đ����J�n����B
	void se::play()
	{
		se_list[nNextIndex].replay();
		++nNextIndex;
		nNextIndex %= se_list.size();
	}





	void se::construct()
	{
		nNextIndex = 0;
		pSoundData = nullptr;
		bOwnerShip = false;
	}

	void se::release()
	{
		if (bOwnerShip)
		{
			if (pSoundData)
			{
				delete pSoundData;
			}
		}

		pSoundData = nullptr;
		bOwnerShip = false;
	}

	se::~se()
	{
		release();
	}

}