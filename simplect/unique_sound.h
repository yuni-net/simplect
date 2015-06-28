#ifndef biringal3D_unique_sound_h_
#define biringal3D_unique_sound_h_

#include "includes.h"
#include "sound_data.h"

namespace sim
{
	class unique_sound
	{
	public:
		unique_sound();
		unique_sound(uint uID);
		unique_sound(const sound_data & soundd);

		bool load(uint uID);
		bool set_sound_data(const sound_data & soundd);

		void replay();	// �Đ����J�n����B���ɍĐ����Ȃ�ŏ�����Đ�������
		void reloop();	// ���[�v�Đ����J�n����B���ɍĐ����Ȃ�ŏ�����Đ�������
	//	void play();	// �Đ�����Ă����Ԃɂ���B�܂���ɍĐ����Ȃ牽�����Ȃ�
	//	void loop();	// ���[�v�Đ�����Ă����Ԃɂ���B�܂���ɍĐ����Ȃ牽�����Ȃ�
		void stop();
		void replay(bool bLoopFlag);



		~unique_sound();
	private:
		const sound_data * pSoundData;
		bool ownership;

		IDirectSoundBuffer8 * secondarysb;
		DWORD BaseFreq;

		void construct();
		void release();
	};
}

#endif