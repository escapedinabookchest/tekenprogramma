
// ChildView.h : interface of the CChildView class
//

#include "Shape.h";

#include <vector>

#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
private:
	CPoint StartPoint;
	CPoint EndPoint;

	Shape* CurrentShape;
	Shape* SelectedShape;
	int SelectedShapeIndex;
	
	static vector<Shape*>* ShapesStack;
	static CChildView* view;

public:
	static int shapeIndex;

// Operations
public:

	static void LoadShapes(string fileSource);
	static string SaveShapes();

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

