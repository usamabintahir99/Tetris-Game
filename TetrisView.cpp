
// TetrisView.cpp : implementation of the CTetrisView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Tetris.h"
#endif

#include "TetrisDoc.h"
#include "TetrisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTetrisView

IMPLEMENT_DYNCREATE(CTetrisView, CView)

BEGIN_MESSAGE_MAP(CTetrisView, CView)
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CTetrisView construction/destruction

CTetrisView::CTetrisView()
{
	// TODO: add construction code here

}

CTetrisView::~CTetrisView()
{
}

void CTetrisView::ResizeWindow()
{
	//  First get a pointer to the document
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//  Get the size of the client area and the window
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	//  Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	//  Change the window size based on the size of the game board
	rcWindow.right = rcWindow.left + 30 * 15 + nWidthDiff;
	rcWindow.bottom = rcWindow.top + 30 * 20 + nHeightDiff;
	//  The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);
}

BOOL CTetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTetrisView drawing

int **board;
int* coordinates;
int X = 6, Y = 0, maxima = 0,fixMaxima=0;
bool flag = false;
int delay = 500;
bool check = true;
bool checkxinc = false;
bool checkxdec = false;
void CTetrisView::OnDraw(CDC* pDC)
{
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	CRect rcClient;
	GetClientRect(&rcClient);
	pDC->FillSolidRect(&rcClient, RGB(0,0,0));
	
	for (int row = 0; row <20; row++)
	{
		for (int col = 0; col < 15; col++)
		{
			//  Get the color for this board space
			//clr = pDoc->GetBoardSpace(row, col);
			//  Calculate the size and position of this space
			CRect rcBlock;
			rcBlock.top = row * 30;
			rcBlock.left = col * 30;
			rcBlock.right = rcBlock.left + 30;
			rcBlock.bottom = rcBlock.top + 30;
			//  Fill in the block with the correct color
			pDC->FillSolidRect(&rcBlock, RGB(255,255,255));
			//  Draw the block outline
			pDC->Rectangle(&rcBlock);
		}
	}

	board = pDoc->getBoard();
	pDoc->clearCompleteRows();
	

	if (pDoc->returngameover() == false)
	{
		for (int j = 0; j < 20; j++)
		{
			if (board[j][0] == -1 || board[j][0] != 0)
			{
				pDoc->setgameover(true);
				KillTimer(1);
				//system("pause");
			}
		}
	}
	for (int row = 0; row < 20; row++)
	{
		for (int col = 0; col < 15; col++)
		{
			if (board[row][col] > 0)
			{
				//int colorIndex = board[row][col];
				//pDoc->getPiecePtr()->getColorIndex();
				pDC->FillSolidRect(col*30,row*30,30,30, colorArray[board[row][col]]);
			}
		}
	}
	pDoc->getPiecePtr()->setStateCords(X,Y);
	coordinates = pDoc->getPiecePtr()->getFptr()->getFourBlocks();
	maxima = coordinates[8];

	/*if (flag == true)
	{
		fixMaxima = maxima;
		flag = false;
	}*/

	COLORREF pieceClr = pDoc->getPiecePtr()->getColor();
	int clrIndex = pDoc->getPiecePtr()->getColorIndex();
	for (int i = 0; i < 7; i += 2)
	{
		pDC->FillSolidRect(coordinates[i] * 30, coordinates[i + 1] * 30, 30, 30, pieceClr);
	}

	for (int x = 0; x < 7; x += 2)
	{
		if (maxima ==19 || board[coordinates[x + 1]][coordinates[x]] == -1)
		{
			for (int i = 0; i < 7; i += 2)
			{
				board[coordinates[i + 1]][coordinates[i]] = clrIndex;
			}

			for (int i = 0, j = 1; i <= 6; i += 2, j += 2)
			{
				if (board[coordinates[j] - 1][coordinates[i]] == 0)
				{
					board[coordinates[j] - 1][coordinates[i]] = -1;
				}

			}
			//X = 0;
			srand(time(NULL));
			int random = (rand() % 11);
			X = random;
			Y = -1;
			pDoc->selectNextPiece();
			pDoc->getPiecePtr()->setCurrentState(0);
			SetTimer(1, delay, NULL);
		}
		else
		{
			SetTimer(1, delay, NULL);
		}
	}

	// TODO: add draw code for native data here
}


// CTetrisView diagnostics

#ifdef _DEBUG
void CTetrisView::AssertValid() const
{
	CView::AssertValid();
}

void CTetrisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

void CTetrisView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	ResizeWindow();
}

CTetrisDoc* CTetrisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTetrisDoc)));
	return (CTetrisDoc*)m_pDocument;
}
#endif //_DEBUG


// CTetrisView message handlers


void CTetrisView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
		Y++;
	CRect rect;
	GetClientRect(&rect);
	RedrawWindow(rect,0,RDW_ERASE|RDW_INVALIDATE);
	CView::OnTimer(nIDEvent);
}


void CTetrisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	
	//MessageBox("Key press", "Test", MB_OK);
	//PreTranslateInput();
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	int valid=pDoc->getPiecePtr()->getValid();

	if (nChar == VK_RIGHT)
	{
		if (X < 15 - valid)
			X++;

	}
	else if(nChar == VK_LEFT)
	{
		if (X > 0)
		X--;	
	}
	else if (nChar == VK_DOWN)
	{
		delay = 100;
	}
	else if (nChar == VK_UP)
	{
		pDoc->rotatePiece(X, Y);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CTetrisView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (nChar == VK_DOWN)
	{
		delay = 500;
	}
	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

