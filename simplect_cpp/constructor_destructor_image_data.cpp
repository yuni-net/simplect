#include "image_data.h"



#include "window.h"

sim::image_data::image_data()
{
	const int PolygonNum = 4;
	FVF_2D = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;
	texture = NULL;
	vertbuff = NULL;
	sim::window::GetDevice()->CreateVertexBuffer(sizeof(vertex2D)* PolygonNum, D3DUSAGE_WRITEONLY, FVF_2D, D3DPOOL_MANAGED, &vertbuff, NULL);
}

sim::image_data::~image_data()
{
	saferelease(texture);
	saferelease(vertbuff);
}

