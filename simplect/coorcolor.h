#pragma once

#include "color.h"
#include "coor.h"

namespace sim
{

	class coorcolor
	{
	public:
		sim::coor & coor();
		sim::color & color();

	private:
		sim::coor mycoor;
		sim::color mycolor;
	};

}



