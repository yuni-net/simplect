#include "anime.h"

static const int c_nResistor = 4;	// �A�j���[�V�������x�}���l�B�傫���قǃA�j���[�V�������x���Ȃ�

void sim::anime::animeset(uint pieceWidth, uint pieceHeight, uint enableNum)
{
	this->pieceWidth = pieceWidth;
	this->pieceHeight = pieceHeight;
	cx(pieceWidth / 2.0f);
	cy(pieceHeight / 2.0f);
	cnt.config(enableNum, c_nResistor);
	cnt.set(0);
}