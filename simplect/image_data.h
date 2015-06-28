#ifndef biringal2D_image_data_h_
#define biringal2D_image_data_h_

#include "includes.h"
#include "saferelease.h"
//#include "window.h"
//#include "plate.h"

#include "matrix.h"
#include "top4.h"
#include "diffuse.h"

namespace sim
{
	class image;

	class image_data
	{
	public:

		bool load(const char * path);
		bool load(const std::string & path);
		uint width() const;
		uint height() const;
		bool draw(const top4 & xy, const top4 & uv, const diffuse & rgba) const;
		bool draw(const top4 & xy, const top4 & uv, const diffuse & rgba, const float basex, const float basey) const;




		image_data();
		~image_data();


	protected:

		uint Width;
		uint Height;



		struct vertex2D
		{
			D3DXVECTOR3 vtx;
			float rhw;
			D3DCOLOR diffuse;
			D3DXVECTOR2 tex;
		};

		LPDIRECT3DTEXTURE9 texture;
		IDirect3DVertexBuffer9 * vertbuff;
		DWORD FVF_2D;

		bool CreateRectanglePolygon(const top4 & xy, const top4 & uv, const diffuse & rgba, const float basex, const float basey) const;
		void DrawWithoutCreatePolygon() const;
	};

}


#endif