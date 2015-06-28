#pragma once

#include "includes.h"
#include "saferelease.h"
#include "dx9key.h"
#include "dx9joypad.h"
#include "sound_manager.h"

namespace sim
{
	class window
	{
	public:
		window();
		static fw::window & win();
		bool create(bool VertiSyncFlag);	// If this returned false, you can't use this miendow.
		bool clear();
		void update();
		static int cursor_x();
		static int cursor_y();
		~window();

		// Don't use this function. this function is used by system
		static LPDIRECT3DDEVICE9 & GetDevice();

	private:
		static fw::window Win;
		D3DPRESENT_PARAMETERS prepara;
		static LPDIRECT3DDEVICE9 device;
		dx9key dxkey;
		dx9joypad dxjoypad;

		bool CreateDevice(bool VertiSyncFlag);
		bool SetViewPort();
		void ReleaseResources();
		void ResetResources();
		bool RestoreDevice();
		void SetParameter();
	};
}