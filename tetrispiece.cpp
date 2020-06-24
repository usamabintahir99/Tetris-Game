#include "stdafx.h"
#include "tetrispiece.h"

TetrisPiece::TetrisPiece() :rotations(0)
{
	setColor();
	fptr = nullptr;
	currentState = 0;
}

void TetrisPiece::setColor()
{
	srand(time(NULL));
	colorIndex= (rand() % 4) + 1;
	color = colorArray[colorIndex];
}

void TetrisPiece::setFptr(FourBlocks * fptr)
{
	this->fptr = fptr;
}

void TetrisPiece::setCurrentState(int state)
{
	currentState = state;
}

COLORREF TetrisPiece::getColor()
{
	return color;
}

int TetrisPiece::getColorIndex()
{
	return colorIndex;
}

int TetrisPiece::getCurrentState()
{
	return currentState;
}

