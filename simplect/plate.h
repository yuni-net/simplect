#pragma once

#include "coorcolor.h"
#include "includes.h"

namespace sim
{

	class plate
	{
	public:
		plate();

		coorcolor & top_left();
		coorcolor & top_right();
		coorcolor & bot_left();
		coorcolor & bot_right();

		virtual bool draw();

		~plate();


	protected:
		bool CreateRectanglePolygon(const DWORD FVF_2D);
		void DrawWithoutCreatePolygon(const DWORD FVF_2D);

	private:

		struct vertex2D
		{
			D3DXVECTOR3 vtx;
			float rhw;
			D3DCOLOR diffuse;
		};

		coorcolor my_top_left;
		coorcolor my_top_right;
		coorcolor my_bot_left;
		coorcolor my_bot_right;

		IDirect3DVertexBuffer9 * vertbuff;

	};

}


