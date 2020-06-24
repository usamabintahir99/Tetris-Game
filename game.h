#pragma once
#ifndef GAME_H
#define GAME_H
#include"tetrispiece.h"
#include"square.h"
#include"Stick.h"
#include"Tshape.h"
#include"LeftLshape.h"
#include"RightLshape.h"
#include"RightStair.h"
#include"LeftStair.h"
class Game
{
private:
	int** board;
	int rows, cols;
	TetrisPiece* piecePtr;
	TetrisPiece *shape[7];
	int currentRow;
	int currentCol;
	bool isGameOver;
public:
	Game();
	bool returngameover();
	void setPiecePtr();
	void selectNextPiece();
	void rotatePiece(int x, int y);
	void setgameover(bool flag);
	void clearCompleteRows();
	COLORREF getCellColor(int col, int row); //returns color of cell(c,r)
	void setCellColor(int c, int r, int val); //set index value of color at cell(c,r)
	TetrisPiece *getPiecePtr();
	int ** getBoard();
	//int getValid();
	~Game();
};
#endif // !GAME_H

