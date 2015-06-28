#include <plate.h>
#include <saferelease.h>

sim::plate::plate()
{
	vertbuff = NULL;
}

sim::plate::~plate()
{
	saferelease(vertbuff);
}