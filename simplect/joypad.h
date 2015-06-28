#pragma once

#include "includes.h"
#include "dx9joypad.h"

namespace sim
{

	namespace joypad
	{
	
		LONG x();
		LONG y();

		bool pushedL();
		bool pushedR();
		bool clickedL();
		bool clickedR();
		bool pushedT();
		bool pushedB();
		bool clickedT();
		bool clickedB();

		bool pushing(unsigned long num);
		bool freeing(unsigned long num);

		bool pushed(unsigned long num);
		bool clicked(unsigned long num);
	

		unsigned long pushing_buttons();
		unsigned long freeing_buttons();

		unsigned long pushed_buttons();
		unsigned long clicked_buttons();
	
	}

}