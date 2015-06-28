#include "image.h"


void sim::image::Compute_uv(top4 & uv) const
{
	uv.lt.x(0.0f);
	uv.lt.y(0.0f);

	uv.rt.x(1.0f);
	uv.rt.y(0.0f);

	uv.lb.x(0.0f);
	uv.lb.y(1.0f);

	uv.rb.x(1.0f);
	uv.rb.y(1.0f);
}

