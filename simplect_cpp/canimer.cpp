#include <canimer.h>
#include "assert.h"

sim::canimer::canimer()
{
	counter = 0;
	nFrame = 1;
}
void sim::canimer::config(int frame, int resistor)
{
	this->nFrame = abs(frame) * abs(resistor);
	assert(this->nFrame > 0);
	this->nResistor = abs(resistor);

	counter %= this->nFrame;
}
void sim::canimer::frame(int v)
{
	config(v, nResistor);
}
void sim::canimer::resistor(int v)
{
	config(nFrame, v);
}
void sim::canimer::set(int No)
{
	if (No < 0)
	{
		No %= nFrame;
		No = nFrame + No;
	}
	counter = No%nFrame;
}
void sim::canimer::move(int num)
{
	set(counter + num);
}
int sim::canimer::now() const
{
	return counter / nResistor;
}
int sim::canimer::nowNo() const
{
	return counter;
}
int sim::canimer::maxNo() const
{
	return nFrame - 1;
}
