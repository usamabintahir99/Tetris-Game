#pragma once
#ifndef RIGHTLSHAPE_H
#define RIGHTLSHAPE_H
#include"tetrispiece.h"
class RightLshape :public TetrisPiece
{
	FourBlocks State[stick_rotations];
public:
	RightLshape();
	void rotateAntiClock(int x, int y);
	virtual FourBlocks *getFptr();
	virtual void setStateCords(int x, int y);
	int getValid();
};
#endif

