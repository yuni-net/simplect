#include <color.h>

void sim::color::r(unsigned char v)
{
	ucR = v;
}
void sim::color::g(unsigned char v)
{
	ucG = v;
}
void sim::color::b(unsigned char v)
{
	ucB = v;
}
void sim::color::a(unsigned char v)
{
	ucA = v;
}
unsigned char sim::color::r()
{
	return ucR;
}
unsigned char sim::color::g()
{
	return ucG;
}
unsigned char sim::color::b()
{
	return ucB;
}
unsigned char sim::color::a()
{
	return ucA;
}
