#include "image.h"


void sim::image::image_data(const sim::image_data & target)
{
	release();
	pImageData = &target;
	magni(1.0f);
	radian(0.0f);
	cx(width() / 2.0f);
	cy(height() / 2.0f);
}