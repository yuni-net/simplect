#include "image.h"

float sim::image::x(float f32Value)
{
	return f32X = f32Value;
}
float sim::image::x() const
{
	return f32X;
}
float sim::image::y(float f32Value)
{
	return f32Y = f32Value;
}
float sim::image::y() const
{
	return f32Y;
}
float sim::image::magni(float f32Value)
{
	return f32Magni = f32Value;
}
float sim::image::magni() const
{
	return f32Magni;
}
float sim::image::degree(float f32Value)
{
	return radian(f32Value*3.14159265f/180.0f);
}
float sim::image::degree() const
{
	return radian()*180.0f / 3.14159265f;
}
float sim::image::radian(float f32Value)
{
	return f32Radian = f32Value;
}
float sim::image::radian() const
{
	return f32Radian;
}
float sim::image::sincos(float fSin, float fCos)
{
	const float c_f32Pi = 3.14159265f;
	const float c_f32_2pi = 2.0f * c_f32Pi;

	if (fCos < 0.000000001f)
	{
		radian(c_f32_2pi - asin(fSin));
	}
	else
	{
		radian(asin(fSin));
	}

	return radian();
}
float sim::image::sin() const
{
	return ::sin(radian());
}
float sim::image::cos() const
{
	return ::cos(radian());
}
float sim::image::cx(float f32Value)
{
	return f32CX = f32Value;
}
float sim::image::cx() const
{
	return f32CX;
}
float sim::image::cy(float f32Value)
{
	return f32CY = f32Value;
}
float sim::image::cy() const
{
	return f32CY;
}

namespace sim
{

	float image::bright_r(float val)
	{
		return r_ = val;
	}
	float image::bright_r() const
	{
		return r_;
	}
	float image::bright_g(float val)
	{
		return g_ = val;
	}
	float image::bright_g() const
	{
		return g_;
	}
	float image::bright_b(float val)
	{
		return b_ = val;
	}
	float image::bright_b() const
	{
		return b_;
	}
	float image::alpha(float val)
	{
		return a_ = val;
	}
	float image::alpha() const
	{
		return a_;
	}

	void  image::rgba(float r, float g, float b, float a)
	{
		bright_r(r);
		bright_g(g);
		bright_b(b);
		alpha(a);
	}

}