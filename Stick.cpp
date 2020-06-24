#include "stdafx.h"
#include "Stick.h"

Stick::Stick()
{
	State[0] = FourBlocks(0, 0, 1, 0, 2, 0, 3, 0, 0);
	State[1] = FourBlocks(1, -1, 1, 0, 1, 1, 1, 2, 2);
	fptr = &State[currentState];
}

void Stick::rotateAntiClock(int x, int y)
{
	if (currentState >= 1)
	{
		currentState = 0;
	}
	else
	{
		currentState++;
	}

	if (currentState == 0)
	{
		valid = 4;
		State[currentState].setFourBlocks(x, y, x+1, y , x + 2, y , x + 3, y , y);
	}
	else if (currentState == 1)
	{
		valid = 1;
		State[currentState].setFourBlocks(x, y + 3, x, y + 2, x, y + 1, x, y, y + 3);
	}

	fptr = &State[currentState];

}

FourBlocks * Stick::getFptr()
{
	return fptr;
}

void Stick::setStateCords(int x, int y)
{
	if (currentState == 0)
	{
		valid = 4;
		State[currentState].setFourBlocks(x, y, x+1, y , x + 2, y , x + 3, y , y);
	}
	else if (currentState == 1)
	{
		valid = 1;
		State[currentState].setFourBlocks(x, y+3, x, y+2, x, y+1, x, y, y+3);
	}

	fptr = &State[currentState];
}

int Stick::getValid()
{
	return valid;
}
