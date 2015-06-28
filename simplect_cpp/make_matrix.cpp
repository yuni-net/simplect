#include "matrix.h"


sim::matrix sim::matrix::make_trans(float fVX, float fVY, float fVZ)
{
	matrix mat(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f);

	mat.x(fVX);
	mat.y(fVY);

	return mat;
}
sim::matrix sim::matrix::make_scale(float fMagniX, float fMagniY, float fMagniZ)
{
	D3DXMATRIX mat;
	D3DXMatrixScaling(&mat, fMagniX, fMagniY, fMagniZ);
	return matrix(
		mat(0, 0), mat(0, 1), mat(0, 2),
		mat(1, 0), mat(1, 1), mat(1, 2),
		mat(2, 0), mat(2, 1), mat(2, 2));
}
sim::matrix sim::matrix::make_rotate(float fRadian)
{
	return sim::matrix::make_rotate(::sin(fRadian), ::cos(fRadian));
}
sim::matrix sim::matrix::make_rotate(float fSin, float fCos)
{
	return matrix(
		fCos, fSin, 0.0f,
		-fSin, fCos, 0.0f,
		0.0f, 0.0f, 0.0f);
}
sim::matrix sim::matrix::make_affine(const matrix & scale, const matrix & rotate, const matrix & trans)
{
	return scale*rotate*trans;
}

