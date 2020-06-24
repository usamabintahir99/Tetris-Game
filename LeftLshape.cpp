#include "stdafx.h"
#include "LeftLshape.h"

LeftLshape::LeftLshape()
{
	State[0] = FourBlocks();
	State[1] = FourBlocks();
	State[2] = FourBlocks();
	State[3] = FourBlocks();
	fptr = &State[currentState];
}

void LeftLshape::rotateAntiClock(int x, int y)
{

	if (currentState >= 3)
	{
		currentState = 0;
	}
	else
	{
		currentState++;
	}

	setStateCords(x, y);
}

FourBlocks * LeftLshape::getFptr()
{
	return fptr;
}

void LeftLshape::setStateCords(int x, int y)
{
	if (currentState == 0)
	{
		valid = 3;
		State[currentState].setFourBlocks(x, y, x, y + 1, x + 1, y + 1, x + 2, y + 1, y + 1);
	}
	else if (currentState == 1)
	{
		valid = 2;
		State[currentState].setFourBlocks(x+1, y-1, x+1, y, x+1, y + 1, x, y + 1, y + 1);
	}
	else if (currentState == 2)
	{
		valid = 3;
		State[currentState].setFourBlocks(x, y, x + 1, y, x + 2, y, x + 2, y + 1, y + 1);
	}
	else if (currentState == 3)
	{
		valid = 2;
		State[currentState].setFourBlocks(x, y, x + 1, y, x, y + 1, x, y + 2, y + 2);
	}

	fptr = &State[currentState];
}

int LeftLshape::getValid()
{
	return valid;
}
