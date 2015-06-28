#include "image.h"
#include <math.h>
#include "includes.h"
#include "diffuse.h"

namespace sim
{
	int round(float val)
	{
		if (val < 0.0f)
		{
			return static_cast<int>(val - 0.555555555555f);
		}
		else
		{
			return static_cast<int>(val + 0.555555555555f);
		}
	}
}

bool sim::image::draw(const float basex, const float basey) const
{
	if (pImageData == NULL) return false;

	top4 xy;

	float fCX = cx()*magni();
	float fCY = cy()*magni();

	xy.lt.x(-fCX);
	xy.lt.y(-fCY);

	xy.rt.x(width() - fCX);
	xy.rt.y(-fCY);

	xy.rb.x(width() - fCX);
	xy.rb.y(height() - fCY);

	xy.lb.x(-fCX);
	xy.lb.y(height() - fCY);

	Compute4dot(xy.lt, xy.rt, xy.rb, xy.lb, basex, basey);

	top4 uv;
	Compute_uv(uv);

	int nRed = round(255.0f * bright_r());
	if (nRed < 0){ nRed = 0; }
	if (nRed > 255){ nRed = 255; }

	int nGreen = round(255.0f * bright_g());
	if (nGreen < 0){ nGreen = 0; }
	if (nGreen > 255){ nGreen = 255; }

	int nBlue = round(255.0f * bright_b());
	if (nBlue < 0){ nBlue = 0; }
	if (nBlue > 255){ nBlue = 255; }

	int nAlpha = round(255.0f * alpha());
	if (nAlpha < 0){ nAlpha = 0; }
	if (nAlpha > 255){ nAlpha = 255; }

	diffuse rgba;
	rgba.red = static_cast<unsigned char>(nRed);
	rgba.green = static_cast<unsigned char>(nGreen);
	rgba.blue = static_cast<unsigned char>(nBlue);
	rgba.alpha = static_cast<unsigned char>(nAlpha);

	return pImageData->draw(xy, uv, rgba, basex, basey);
}


bool sim::image::draw() const
{

	return draw(0.0f, 0.0f);

}

bool sim::image::draw_center(const float basex, const float basey) const
{
	return draw(basex + width() / 2.0f, basey + height() / 2.0f);
}

bool sim::image::draw_center() const
{
	return draw_center(0.0f, 0.0f);
}