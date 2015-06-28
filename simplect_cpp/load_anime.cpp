#include "anime.h"


bool sim::anime::load(const char * path, uint pieceWidth, uint pieceHeight, uint enableNum)
{
	bool result = sim::image::load(path);
	animeset(pieceWidth, pieceHeight, enableNum);

	return result;
}





bool sim::anime::load(const std::string & path, uint pieceWidth, uint pieceHeight, uint enableNum)
{
	return load(path.c_str(), pieceWidth, pieceHeight, enableNum);
}
