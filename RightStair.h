#pragma once
#ifndef RIGHTSTAIR_H
#define RIGHTSTAIR_H
#include"tetrispiece.h"
class RightStair :public TetrisPiece
{
	FourBlocks State[stick_rotations];
public:
	RightStair();
	void rotateAntiClock(int x, int y);
	virtual FourBlocks *getFptr();
	virtual void setStateCords(int x, int y);
	int getValid();
};
#endif

