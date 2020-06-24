#pragma once
#ifndef LEFTLSHAPE_H
#define LEFTLSHAPE_H
#include"tetrispiece.h"
class LeftLshape :public TetrisPiece
{
	FourBlocks State[stick_rotations];
public:
	LeftLshape();
	void rotateAntiClock(int x, int y);
	virtual FourBlocks *getFptr();
	virtual void setStateCords(int x, int y);
	int getValid();
};
#endif

