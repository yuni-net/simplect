#include "image.h"

void sim::image::Compute4dot(sim::matrix & lt, sim::matrix & rt, sim::matrix & rb, sim::matrix & lb, float basex, float basey) const
{
	sim::matrix affine = sim::matrix::make_affine(
		sim::matrix::make_scale(magni(), magni(), 1.0f),
		sim::matrix::make_rotate(sin(), cos()),
		sim::matrix::make_trans(basex + x() + cx(), basey + y() + cy(), 0.0f));

	lt *= affine;
	rt *= affine;
	rb *= affine;
	lb *= affine;

}