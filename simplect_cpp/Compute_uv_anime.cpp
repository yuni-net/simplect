#include "anime.h"



/* @override */ void sim::anime::Compute_uv(top4 & uv) const
{
	int nXNum = pImageData->width() / pieceWidth;
	int nXNo = cnt.now() % nXNum;
	int nYNo = cnt.now() / nXNum;
	float fBegX = static_cast<float>(pieceWidth * nXNo) / pImageData->width();
	float fBegY = static_cast<float>(pieceHeight * nYNo) / pImageData->height();
	float fEndX = static_cast<float>(pieceWidth * nXNo + pieceWidth) / pImageData->width();
	float fEndY = static_cast<float>(pieceHeight * nYNo + pieceHeight) / pImageData->height();

	uv.lt.x(fBegX);
	uv.lt.y(fBegY);

	uv.rt.x(fEndX);
	uv.rt.y(fBegY);

	uv.lb.x(fBegX);
	uv.lb.y(fEndY);

	uv.rb.x(fEndX);
	uv.rb.y(fEndY);
}

#if 0

void ComputeUV(const int nTextureWidth, const int nTextureHeight,
               const int nPieceWidth, const int nPieceHeight,
               const int nFrameNum_x, const int nFrameNum_y,
               const int nAnimeNo)
{
	int nFrameNo_x = nAnimeNo % nFrameNum_x;	// �����牽�Ԗڂ̃R�}���g�������߂�
	int nFrameNo_y = nAnimeNo / nFrameNum_x;	// �ォ�牽�Ԗڂ̃R�}���g�������߂�

	// ���[��U���W
	float fBegX = static_cast<float>(nPieceWidth * nFrameNo_x) / nTextureWidth;

	// �㑤��V���W
	float fBegY = static_cast<float>(nPieceHeight * nFrameNo_y) / nTextureHeight;

	// �E����U���W
	float fEndX = static_cast<float>(nPieceWidth * nFrameNo_x + nPieceWidth) / nTextureWidth;

	// ������V���W
	float fEndY = static_cast<float>(nPieceHeight * nFrameNo_y + nPieceHeight) / nTextureHeight;

	D3DXVECTOR2 uv_left_top  = D3DXVECTOR2(fBegX, fBegY);	// ����uv���W
	D3DXVECTOR2 uv_right_top = D3DXVECTOR2(fEndX, fBegY);	// �E��uv���W
	D3DXVECTOR2 uv_left_bot  = D3DXVECTOR2(fBegX, fEndY);	// ����uv���W
	D3DXVECTOR2 uv_right_bot = D3DXVECTOR2(fEndX, fEndY);	// �E��uv���W
}

#endif