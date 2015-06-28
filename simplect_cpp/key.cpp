#include <dx9input.h>
#include <dx9key.h>

namespace sim
{
	namespace key
	{
		bool pushing(unsigned char key)
		{
			return ::sim::dx9key::pushing(key);
		}

		bool freeing(unsigned char key)
		{
			return ::sim::dx9key::freeing(key);
		}


		bool pushed(unsigned char key)
		{
			return ::sim::dx9key::pushed(key);
		}

		bool clicked(unsigned char key)
		{
			return ::sim::dx9key::clicked(key);
		}

		int pushing_num()
		{
			return ::sim::dx9key::pushing_num();
		}
		int freeing_num()
		{
			return ::sim::dx9key::freeing_num();
		}
		int pushed_num()
		{
			return ::sim::dx9key::pushed_num();
		}
		int clicked_num()
		{
			return ::sim::dx9key::clicked_num();
		}
	}
}