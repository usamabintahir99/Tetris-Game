#pragma once
#ifndef LEFTSTAIR_H
#define LEFTSTAIR_H
#include"tetrispiece.h"
class LeftStair :public TetrisPiece
{
	FourBlocks State[stick_rotations];
public:
	LeftStair();
	void rotateAntiClock(int x, int y);
	virtual FourBlocks *getFptr();
	virtual void setStateCords(int x, int y);
	int getValid();
};
#endif

