#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include"tetrispiece.h"
class square:public TetrisPiece
{
	FourBlocks State[square_rotations];

public:
	square();
	void rotateAntiClock(int x, int y);
	//virtual int getCurrentState();
	virtual FourBlocks *getFptr();
	virtual void setStateCords(int x, int y);
	int getValid();
};
#endif 

