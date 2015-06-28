#include "includes.h"
#include "image.h"


float sim::image::width() const
{
	return base_width()*magni();
}

float sim::image::height() const
{
	return base_height()*magni();
}

uint sim::image::base_width() const
{
	if (pImageData == NULL) return 0;
	return pImageData->width();
}

uint sim::image::base_height() const
{
	if (pImageData == NULL) return 0;
	return pImageData->height();
}

