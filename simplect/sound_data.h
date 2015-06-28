#ifndef biringal3D_sound_data_h_
#define biringal3D_sound_data_h_

#include "includes.h"
#include "manager.h"

namespace sim
{
	class sound_data
	{
	public:
		sound_data();
		sound_data(uint uID);

		bool load(uint uID);
		uint getID() const;



		bool create_buffer(IDirectSoundBuffer8 * & secondarysb) const;
	private:
		uint uID;

		fw::wav wav_data;
		WAVEFORMATEX wfe;
		DSBUFFERDESC dsbdesc;

		void construct();
	};
}

#endif