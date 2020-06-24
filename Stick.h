#pragma once
#ifndef STICK_H
#define STICK_H
#include"tetrispiece.h"
class Stick:public TetrisPiece
{
	FourBlocks State[stick_rotations];
public:
	Stick();
	void rotateAntiClock(int x, int y);
	virtual FourBlocks *getFptr();
	virtual void setStateCords(int x, int y);
	int getValid();
};
#endif // !STICK_H
