#include "stdafx.h"
#include "game.h"

Game::Game()
{
	rows = 20;
	cols = 15;
	board = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = 0;
		}
	}
	isGameOver = false;
	shape[0] = { new square()};
	shape[1] = { new Stick()};
	shape[2] = { new Tshape() };
	shape[3] = new LeftLshape();
	shape[4] = new RightLshape();
	shape[5] = new RightStair();
	shape[6] = new LeftStair();
	setPiecePtr();
}
bool Game::returngameover()
{
	return isGameOver;
}
void Game::setPiecePtr()
{
	//setColor();
	srand(time(NULL));
	int index = (rand() % 7 + 0);
	piecePtr = shape[index];
	piecePtr->setColor();
}

void Game::selectNextPiece()
{
	if (piecePtr)
	{
		piecePtr = nullptr;
	}
	setPiecePtr();
}

void Game::rotatePiece(int x, int y)
{
	piecePtr->rotateAntiClock(x,y);
}

void Game::setgameover(bool flag)
{
	isGameOver = flag;
}

void Game::clearCompleteRows()
{
	int count = 0;

	for (int i = 0; i < 20; i++)
	{
		count = 0;

		for (int j = 0; j < 15; j++)
		{
			if (board[i][j] > 0)
			{
				count++;
			}
			if (count == 15)
			{
				for (int col = 0; col < 15; col++)
				{
					board[i][col] = 0;
				}

				for (int x = i; x > 0; x--)
				{
					for (int y = 0; y < 15; y++)
					{
						board[x][y] = board[x - 1][y];
					}
				}
			}
		}
	}
}

COLORREF Game::getCellColor(int col, int row)
{
	int index = board[col][row];
	return colorArray[index];
}

void Game::setCellColor(int r, int c, int val)
{
	board[c][r] = val;
}

TetrisPiece * Game::getPiecePtr()
{
	return piecePtr;
}

int ** Game::getBoard()
{
	return board;
}



Game::~Game()
{
	/*for (int i = 0; i < 7; i++)
	{
		if (shape[i] !=nullptr)
		{
			delete shape[i];
			shape[i] = nullptr;
		}
	}*/
	delete []shape;

	for (int i = 0; i < 20; i++)
	{
			delete[] board[i];
	}
	delete[] board;
	board = nullptr;
}
