#include <plate.h>
#include <window.h>

void sim::plate::DrawWithoutCreatePolygon(const DWORD FVF_2D)
{
	sim::window::GetDevice()->SetFVF(FVF_2D);
	sim::window::GetDevice()->SetStreamSource(0, vertbuff, 0, sizeof(vertex2D));
	sim::window::GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}