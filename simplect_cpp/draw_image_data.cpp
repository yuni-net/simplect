#include "image_data.h"
#include "image.h"



#include "window.h"

bool sim::image_data::draw(const top4 & xy, const top4 & uv, const diffuse & rgba, const float basex, const float basey) const
{
	if (CreateRectanglePolygon(xy, uv, rgba, basex, basey) == false) return false;
	sim::window::GetDevice()->SetTexture(0, texture);
	DrawWithoutCreatePolygon();

	return true;
}

bool sim::image_data::draw(const top4 & xy, const top4 & uv, const diffuse & rgba) const
{
	return draw(xy, uv, rgba, 0.0f, 0.0f);
}
