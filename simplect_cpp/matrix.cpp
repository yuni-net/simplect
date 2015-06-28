#include "matrix.h"
#include "assert.h"



sim::matrix::matrix()
{
	matrix_(0, 0) = 0.0f;
	matrix_(0, 1) = 0.0f;
	matrix_(0, 2) = 0.0f;
	matrix_(0, 3) = 0.0f;

	matrix_(1, 0) = 0.0f;
	matrix_(1, 1) = 0.0f;
	matrix_(1, 2) = 0.0f;
	matrix_(1, 3) = 0.0f;

	matrix_(2, 0) = 0.0f;
	matrix_(2, 1) = 0.0f;
	matrix_(2, 2) = 0.0f;
	matrix_(2, 3) = 0.0f;

	matrix_(3, 0) = 0.0f;
	matrix_(3, 1) = 0.0f;
	matrix_(3, 2) = 0.0f;
	matrix_(3, 3) = 1.0f;
}
sim::matrix::matrix(
	float _00, float _01, float _02,
	float _10, float _11, float _12,
	float _20, float _21, float _22 )
{
	matrix_(0, 0) = _00;
	matrix_(0, 1) = _01;
	matrix_(0, 2) = _02;
	matrix_(0, 3) = 0.0f;

	matrix_(1, 0) = _10;
	matrix_(1, 1) = _11;
	matrix_(1, 2) = _12;
	matrix_(1, 3) = 0.0f;

	matrix_(2, 0) = _20;
	matrix_(2, 1) = _21;
	matrix_(2, 2) = _22;
	matrix_(2, 3) = 0.0f;

	matrix_(3, 0) = 0.0f;
	matrix_(3, 1) = 0.0f;
	matrix_(3, 2) = 0.0f;
	matrix_(3, 3) = 1.0f;
}
sim::matrix::matrix(const matrix & mat)
{
	matrix_ = mat.matrix_;
}
sim::matrix & sim::matrix::operator=(const matrix & mat)
{
	matrix_ = mat.matrix_;
	return *this;
}
float sim::matrix::operator()(unsigned int y, unsigned int x)
{
	assert(x<=3 && y<=3);
	return matrix_(y, x);
}
sim::matrix sim::matrix::operator*(const matrix & mat) const
{
	D3DXMATRIX result9 = matrix_ * mat.matrix_;

	matrix result(
		result9(0, 0), result9(0, 1), result9(0, 2),
		result9(1, 0), result9(1, 1), result9(1, 2),
		result9(2, 0), result9(2, 1), result9(2, 2) );

	result.x(result9(3, 0));
	result.y(result9(3, 1));
	result.z(result9(3, 2));

	return result;
}
sim::matrix & sim::matrix::operator*=(const matrix & mat)
{
	matrix_ *= mat.matrix_;
	return *this;
}

