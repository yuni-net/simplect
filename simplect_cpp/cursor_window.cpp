#include <window.h>

int sim::window::cursor_x()
{
	POINT point;
	GetCursorPos(&point);
	ScreenToClient(win().myhandle(), &point);

	return point.x;
}

int sim::window::cursor_y()
{
	POINT point;
	GetCursorPos(&point);
	ScreenToClient(win().myhandle(), &point);

	return point.y;
}