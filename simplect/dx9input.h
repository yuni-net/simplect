#pragma once

#include "includes.h"

namespace sim
{


#if 0
	class dx9key
	{
	public:
		dx9key();

		bool init(LPDIRECTINPUT8 & diinterface, HWND windle);

		void update();

		static bool pushing(unsigned char key);

		static bool freeing(unsigned char key);

		static bool pushed(unsigned char key);
		static bool clicked(unsigned char key);

		void release();
		~dx9key();

	private:
		LPDIRECTINPUTDEVICE8 device;
		static BYTE keystate[2][256];
		static bool active;
		HWND Windle;
	};

#endif




	class dx9input
	{
	public:
		dx9input();

		bool init();

		static LPDIRECTINPUT8 & GetInterface();

		~dx9input();

	private:
		static LPDIRECTINPUT8 diinterface;
	};

}