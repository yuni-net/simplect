#include <plate.h>
#include <window.h>

bool sim::plate::draw()
{
	const DWORD FVF_2D = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;

	if(CreateRectanglePolygon(FVF_2D)==false) return false;
	DrawWithoutCreatePolygon(FVF_2D);

	return true;
}


