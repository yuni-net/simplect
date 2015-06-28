#include "matrix.h"


void sim::matrix::x(float fValue)
{
	matrix_(3, 0) = fValue;
}
void sim::matrix::y(float fValue)
{
	matrix_(3, 1) = fValue;
}
void sim::matrix::z(float fValue)
{
	matrix_(3, 2) = fValue;
}
float  sim::matrix::x() const
{
	return matrix_(3, 0);
}
float  sim::matrix::y() const
{
	return matrix_(3, 1);
}
float  sim::matrix::z() const
{
	return matrix_(3, 2);
}

