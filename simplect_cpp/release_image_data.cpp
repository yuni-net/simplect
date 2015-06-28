#include "image.h"

void sim::image::release()
{
	if (ownership == true)
	{
		delete pImageData;
	}

	pImageData = NULL;
	ownership = false;
}