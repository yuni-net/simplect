#include <window.h>

namespace sim
{
	namespace cursor
	{
		int x()
		{
			return sim::window::cursor_x();
		}
		int y()
		{
			return sim::window::cursor_y();
		}
	}
}