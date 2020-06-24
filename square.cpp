#include "stdafx.h"
#include "square.h"

square::square()
{
	valid = 0;
	State[0] = FourBlocks(0, -1, 1, -1, 1, 0, 0, 1, 1);
	//currentState = 0;
	fptr = &State[currentState];
}

void square::rotateAntiClock(int x, int y)
{
	currentState = 0;
	State[currentState].setFourBlocks(x, y, x + 1, y, x, y + 1, x + 1, y + 1, y + 1);
	fptr = &State[currentState];
}

FourBlocks * square::getFptr()
{
	return fptr;
}

void square::setStateCords(int x, int y)
{
	valid = 2;
	currentState = 0;
	State[currentState].setFourBlocks(x, y, x + 1, y, x, y + 1, x + 1, y + 1, y + 1);
	fptr = &State[currentState];
}

int square::getValid()
{
	return valid;
}

