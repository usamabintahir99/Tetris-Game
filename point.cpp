#include "stdafx.h"
#include "point.h"

void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}
