#pragma once
#ifndef FOURBLOCKS_H
#define FOURBLOCKS_H
#include"point.h"
class FourBlocks
{
	Point blockPts[4];
	int maxima;
	int cords[9];
public:
	FourBlocks(int x0=0, int y0=0, int x1=0, int y1=0, int x2=0, int y2=0, int x3=0, int y3=0, int maxima=0);
	void setFourBlocks(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, int maxima);
	int *getFourBlocks();
};

#endif // !FOURBLOCKS_H

