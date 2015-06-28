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

		void replay();	// 再生を開始する。既に再生中なら最初から再生し直す
		void reloop();	// ループ再生を開始する。既に再生中なら最初から再生し直す
	//	void play();	// 再生されている状態にする。つまり既に再生中なら何もしない
	//	void loop();	// ループ再生されている状態にする。つまり既に再生中なら何もしない
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