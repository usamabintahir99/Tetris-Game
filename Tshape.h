#pragma once
#ifndef TSHAPE_H
#define TSHAPE_H
#include"tetrispiece.h"
class Tshape :public TetrisPiece
{
	FourBlocks State[stick_rotations];
public:
	Tshape();
	void rotateAntiClock(int x, int y);
	virtual FourBlocks *getFptr();
	virtual void setStateCords(int x, int y);
	int getValid();
};
#endif

