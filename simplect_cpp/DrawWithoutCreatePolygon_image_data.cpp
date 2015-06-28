#include "image.h"
#include "includes.h"


#include "window.h"

void sim::image_data::DrawWithoutCreatePolygon() const
{
	sim::window::GetDevice()->SetFVF(FVF_2D);
	sim::window::GetDevice()->SetStreamSource(0, vertbuff, 0, sizeof(vertex2D));
	sim::window::GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}

