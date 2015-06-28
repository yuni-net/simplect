#include <joypad.h>

namespace sim
{
	namespace joypad
	{

		LONG x(){ return dx9joypad::x(); }
		LONG y(){ return dx9joypad::y(); }

		bool pushedL()
		{
			if(x() >= 0) return false;
			if(dx9joypad::oldx() < 0) return false;

			return true;
		}
		bool pushedR()
		{
			if(x() <= 0) return false;
			if(dx9joypad::oldx() > 0) return false;

			return true;
		}
		bool clickedL()
		{
			if(x()!=0) return false;
			if(dx9joypad::oldx()>=0) return false;

			return true;
		}
		bool clickedR()
		{
			if(x()!=0) return false;
			if(dx9joypad::oldx()<=0) return false;

			return true;
		}

		bool pushedT()
		{
			if(y() >= 0) return false;
			if(dx9joypad::oldy() < 0) return false;

			return true;
		}
		bool pushedB()
		{
			if(y() <= 0) return false;
			if(dx9joypad::oldy() > 0) return false;

			return true;
		}
		bool clickedT()
		{
			if(y()!=0) return false;
			if(dx9joypad::oldy()>=0) return false;

			return true;
		}
		bool clickedB()
		{
			if(y()!=0) return false;
			if(dx9joypad::oldy()<=0) return false;

			return true;
		}


		bool pushing(const unsigned long num)
		{
			return (dx9joypad::ActiveButtons() & num) != 0;
		}
		bool freeing(const unsigned long num)
		{
			return (dx9joypad::ActiveButtons() & num) == 0;
		}

		bool pushed(const unsigned long num)
		{
			if((dx9joypad::ActiveButtons() & num) == 0) return false;
			if((dx9joypad::UnActiveButtons() & num) != 0) return false;

			return true;
		}
		bool clicked(const unsigned long num)
		{
			if( (dx9joypad::ActiveButtons() & num) != 0) return false;
			if( (dx9joypad::UnActiveButtons() & num) == 0) return false;

			return true;
		}


		unsigned long pushing_buttons()
		{
			return dx9joypad::ActiveButtons();
		}
		unsigned long freeing_buttons()
		{
			return ~dx9joypad::ActiveButtons();
		}

		unsigned long pushed_buttons()
		{
			return dx9joypad::ActiveButtons()^dx9joypad::UnActiveButtons() & dx9joypad::ActiveButtons();
		}
		unsigned long clicked_buttons()
		{
			return dx9joypad::ActiveButtons()^dx9joypad::UnActiveButtons() & (~dx9joypad::ActiveButtons() );
		}
	}
}