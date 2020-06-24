#pragma once
#ifndef TETRISPIECE_H
#define TETRISPIECE_H
#include"fourblocks.h"
#include"global.h"
class TetrisPiece
{
protected:
	COLORREF color; //color of the TetrisPiece
	int colorIndex; //index to select value for ‘color’ from global const colorArray[5]
	const int rotations; //total distinct rotations possible for a peice
	FourBlocks* fptr; //fptr is a pointer that will be inherited in derived classes of
					  //TetrisPiece and will be made to point a fourBlocks structure
					  //as will be discussed later.
	int currentState; //current state of the TetrisPiece. It will be used in setting fptr
	int valid;

public:
	TetrisPiece();
	void setColor();
	void setFptr(FourBlocks *fptr);
	virtual void setCurrentState(int state);
	COLORREF getColor();
	int getColorIndex();
	virtual int getCurrentState();
	virtual FourBlocks *getFptr()=0;
	virtual void rotateAntiClock(int x, int y) = 0;
	virtual void setStateCords(int x,int y) = 0;
	virtual int getValid() = 0;
};

#endif // !TETRISPIECE_H
