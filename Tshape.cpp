#include "stdafx.h"
#include "Tshape.h"

Tshape::Tshape()
{
	State[0] = FourBlocks(0, 0, 1, 0, 2, 0, 1, 1, 1);
	State[1] = FourBlocks();
	State[2] = FourBlocks();
	State[3] = FourBlocks();
	fptr = &State[currentState];
}

void Tshape::rotateAntiClock(int x, int y)
{
	
	if (currentState >= 3)
	{
		currentState = 0;
	}
	else
	{
		currentState++;
	}

	/*if (currentState == 0)
	{
		valid = 4;
		State[currentState].setFourBlocks(x, y, x + 1, y, x + 2, y, x + 3, y, y);
	}
	else if (currentState == 1)
	{
		valid = 0;
		State[currentState].setFourBlocks(x, y + 3, x, y + 2, x, y + 1, x, y, y + 3);
	}

	fptr = &State[currentState];
*/
	setStateCords(x, y);
}

FourBlocks * Tshape::getFptr()
{
	return fptr;
}

void Tshape::setStateCords(int x, int y)
{
	if (currentState == 0)
	{
		valid = 3;
		State[currentState].setFourBlocks(x, y, x + 1, y, x + 2, y, x + 1, y + 1, y + 1);
	}
	else if (currentState == 1)
	{
		valid = 2;
		State[currentState].setFourBlocks(x, y, x, y + 1, x+1, y + 1, x, y+2, y + 2);
	}
	else if (currentState == 2)
	{
		valid = 3;
		State[currentState].setFourBlocks(x, y, x+1, y, x+1, y-1, x+2, y, y);
	}
	else if (currentState == 3)
	{
		valid = 1;
		State[currentState].setFourBlocks(x, y, x+1, y - 1, x+1, y, x+1, y + 1, y + 1);
	}

	fptr = &State[currentState];
}

int Tshape::getValid()
{
	return valid;
}
