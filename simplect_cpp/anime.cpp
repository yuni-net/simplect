#include "anime.h"


namespace sim
{
	anime::anime(){ /* Nothing */ }
	anime::anime(const char * path, uint pieceWidth, uint pieceHeight, uint enableNum){ load(path, pieceWidth, pieceHeight, enableNum); }
	anime::anime(const std::string & path, uint pieceWidth, uint pieceHeight, uint enableNum){ load(path, pieceWidth, pieceHeight, enableNum); }
}


void sim::anime::animation()
{
	cnt.move(1);
}
void sim::anime::animation_once()
{
	int pre = cnt.now();
	cnt.move(1);
	if (cnt.now() < pre)
	{
		cnt.move(-1);
	}
}

void sim::anime::resistor(int v)
{
	cnt.resistor(v);
}
void sim::anime::replay()
{
	cnt.set(0);
}
bool sim::anime::ifFinalFrame()
{
	return cnt.nowNo() >= cnt.maxNo();
}

void sim::anime::set(int nNo)
{
	cnt.set(nNo);
}
int sim::anime::maxNo()
{
	return cnt.maxNo();
}
