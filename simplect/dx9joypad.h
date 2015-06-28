#pragma once

#include <includes.h>
#include <dx9input.h>

const int ButtonNum = 32;

namespace sim
{
	class dx9joypad
	{
	public:
		dx9joypad();
		bool init(LPDIRECTINPUT8 & diinterface, HWND windle);
		void update();

		static LONG x(){ return X; }
		static LONG y(){ return Y; }
		static LONG oldx(){ return OldX; }
		static LONG oldy(){ return OldY; }
		static unsigned long ActiveButtons(){ return buttons[active]; }
		static unsigned long UnActiveButtons(){ return buttons[!active]; }

		~dx9joypad();

	private:
		static LONG X;
		static LONG Y;
		static LONG OldX;
		static LONG OldY;
		static unsigned long buttons[2];
		static bool active;

		static LPDIRECTINPUTDEVICE8 device;
		static DIDEVCAPS devcap;

		static LPDIRECTINPUTDEVICE8 & GetDevice(){ return device; }
		static DIDEVCAPS & GetDevCap(){ return devcap; }

		static BOOL __stdcall EnumJoyCallback(LPCDIDEVICEINSTANCE devins, LPVOID context);

		static BOOL CALLBACK EnumAxesCallback(LPCDIDEVICEOBJECTINSTANCE lpddoi, LPVOID pvRef);
	};
}