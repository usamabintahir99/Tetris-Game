
// TetrisDoc.h : interface of the CTetrisDoc class
//


#pragma once
#include"game.h"

class CTetrisDoc : public CDocument
{
protected: // create from serialization only
	CTetrisDoc();
	DECLARE_DYNCREATE(CTetrisDoc)

// Attributes
public:

// Operations
public:
	bool returngameover();
	COLORREF getCellColor(int col, int row);
	void setPiecePtr();
	void selectNextPiece();
	void rotatePiece(int x , int y);
	void setCellColor(int c, int r, int val);
	TetrisPiece *getPiecePtr();
	int ** getBoard();
	void clearCompleteRows();
	void setgameover(bool flag);

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
protected:
	Game game;
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTetrisDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
