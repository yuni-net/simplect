#include "image.h"
#include "includes.h"
#include "saferelease.h"


namespace sim
{


	void image::construct()
	{
		pImageData = NULL;
		ownership = false;
		x(0.0f);
		y(0.0f);
		magni(1.0f);
		radian(0.0f);
		cx(0.0f);
		cy(0.0f);
		rgba(1.0f, 1.0f, 1.0f, 1.0f);
	}


	image::image()
	{
		construct();
	}

	image::image(const char * path)
	{
		construct();
		load(path);
	}

	image::image(const std::string & path)
	{
		construct();
		load(path);
	}

}