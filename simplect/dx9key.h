#pragma once

#include "includes.h"

namespace sim
{

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

		static int pushing_num();
		static int freeing_num();
		static int pushed_num();
		static int clicked_num();

		void release();
		~dx9key();

	private:
		LPDIRECTINPUTDEVICE8 device;
		static BYTE keystate[2][256];
		static bool active;
		static int pushing_num_;
		static int freeing_num_;
		static int pushed_num_;
		static int clicked_num_;
		HWND Windle;

		static int compute_pushing_num();
		static int compute_freeing_num();
		static int compute_pushed_num();
		static int compute_clicked_num();

	};
}