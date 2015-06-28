#pragma once

#include "includes.h"
#include "window.h"
#include "dx9input.h"
#include "sound_manager.h"

namespace sim
{
	class manager
	{
	public:
		manager();
		void VertiSync(bool flag);
		void title(const std::string &);
		bool init();
		bool clear();
		void update();
		~manager();

		// Don't use these function. this function is used by system
		static LPDIRECT3D9 & Get_d3d();
		static LPDIRECTINPUT8 & GetDX9InputInterface();
		static sound_manager & get_sound_manager();

	private:
		static LPDIRECT3D9 d3d;
		static sound_manager soundm;
		sim::window mainwin;
		dx9input dxinput;
		bool VertiSyncFlag;
	};
}