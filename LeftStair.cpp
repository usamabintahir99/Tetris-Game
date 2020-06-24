#include "stdafx.h"
#include "LeftStair.h"

LeftStair::LeftStair()
{
	State[0] = FourBlocks();
	State[1] = FourBlocks();
	State[2] = FourBlocks();
	State[3] = FourBlocks();
	fptr = &State[currentState];
}

void LeftStair::rotateAntiClock(int x, int y)
{

	if (currentState >= 1)
	{
		currentState = 0;
	}
	else
	{
		currentState++;
	}

	setStateCords(x, y);
}

FourBlocks * LeftStair::getFptr()
{
	return fptr;
}

void LeftStair::setStateCords(int x, int y)
{
	if (currentState == 0)
	{
		valid = 3;
		State[currentState].setFourBlocks(x, y, x + 1, y, x + 1, y + 1, x + 2, y + 1, y + 1);
	}
	else if (currentState == 1)
	{
		valid = 1;
		State[currentState].setFourBlocks(x, y, x - 1, y + 1, x, y + 1, x - 1, y + 2, y + 2);
	}

	fptr = &State[currentState];
}

int LeftStair::getValid()
{
	return valid;
}
