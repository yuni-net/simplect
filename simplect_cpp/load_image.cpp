#include "image.h"
#include "includes.h"




bool sim::image::load(const char * path)
{
	release();
	sim::image_data * pNewImageData = new sim::image_data();
	bool result = pNewImageData->load(path);
	pImageData = pNewImageData;
	ownership = true;
	cx(width() / 2.0f);
	cy(height() / 2.0f);
	return result;
}


bool sim::image::load(const std::string & path)
{
	return load(path.c_str());
}



