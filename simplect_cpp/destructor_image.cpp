#include "image.h"
#include "includes.h"

sim::image::~image()
{
	release();
}
