#pragma once


namespace sim
{

	class coor
	{
	public:
		void x(float v);
		void y(float v);
		float x();
		float y();

	private:
		float fX;
		float fY;
	};

}

