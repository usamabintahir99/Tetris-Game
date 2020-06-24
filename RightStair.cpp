#include "stdafx.h"
#include "RightStair.h"

RightStair::RightStair()
{
	State[0] = FourBlocks();
	State[1] = FourBlocks();
	State[2] = FourBlocks();
	State[3] = FourBlocks();
	fptr = &State[currentState];
}

void RightStair::rotateAntiClock(int x, int y)
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

FourBlocks * RightStair::getFptr()
{
	return fptr;
}

void RightStair::setStateCords(int x, int y)
{
	if (currentState == 0)
	{
		valid = 3;
		State[currentState].setFourBlocks(x, y+1, x + 1, y+1, x + 1, y, x+2, y, y + 1);
	}
	else if (currentState == 1)
	{
		valid = 2;
		State[currentState].setFourBlocks(x, y, x, y + 1, x + 1, y + 1, x + 1, y + 2, y + 2);
	}
	
	fptr = &State[currentState];
}

int RightStair::getValid()
{
	return valid;
}
