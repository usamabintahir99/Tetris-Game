#include "stdafx.h"
#include "fourblocks.h"

FourBlocks::FourBlocks(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int maxima)
{
	blockPts[0].set(x0, y0);
	blockPts[1].set(x1, y1);
	blockPts[2].set(x2, y2);
	blockPts[3].set(x3, y3);
	this->maxima = maxima;
}

void FourBlocks::setFourBlocks(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int maxima)
{
	blockPts[0].set(x0, y0);
	blockPts[1].set(x1, y1);
	blockPts[2].set(x2, y2);
	blockPts[3].set(x3, y3);
	this->maxima = maxima;
}

int * FourBlocks::getFourBlocks()
{
	cords[0] = blockPts[0].getX();
	cords[1] = blockPts[0].getY();
	cords[2] = blockPts[1].getX();
	cords[3] = blockPts[1].getY();
	cords[4] = blockPts[2].getX();
	cords[5] = blockPts[2].getY();
	cords[6] = blockPts[3].getX();
	cords[7] = blockPts[3].getY();
	cords[8] = maxima;
	return cords;
}
