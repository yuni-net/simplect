#pragma once

namespace sim
{
	namespace key
	{
		bool pushing(unsigned char key);
		bool freeing(unsigned char key);

		bool pushed(unsigned char key);
		bool clicked(unsigned char key);

		int pushing_num();
		int freeing_num();
		int pushed_num();
		int clicked_num();
	}
}