#include "anime.h"

bool sim::anime::image_data(const sim::image_data & target, uint pieceWidth, uint pieceHeight, uint enableNum)
{
	sim::image::image_data(target);
	animeset(pieceWidth, pieceHeight, enableNum);

	return true;
}
