
// ChildView.cpp : implementation of the CChildView class
//


#include "stdafx.h"

#include "CDSDraw.h"
#include "ChildView.h"

#include "Shape.h"
#include "ShapeCircle.h"
#include "ShapeEllipse.h"
#include "ShapeLine.h"
#include "ShapeRectangle.h"
#include "ShapeSquare.h"

#include "ShapeFileReader.h"

#include <string>


#ifdef _DEBUG
#ifndef _DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )  
#define new DEBUG_NEW
#endif


// CChildView

// Static field initializations
int CChildView::shapeIndex = -1;

vector<Shape*>* CChildView::ShapesStack = new vector<Shape*>();
CChildView* CChildView::view;

// CChildView constructor
CChildView::CChildView()
{
	StartPoint.x = -1;
	EndPoint.x = -1;
	SelectedShapeIndex = -1;
}

// CChildView destructor
CChildView::~CChildView()
{
	for (vector<Shape*>::const_iterator it = ShapesStack->begin(); it < ShapesStack->end(); ++it)
	{
		Shape* s = *it;

		delete s;
	}

	delete CurrentShape;
	delete SelectedShape;
	delete ShapesStack;
	delete view;
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// CChildView message handlers
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// Redraw all shapes
	CDC* pDC = GetDC();
	view = this;
	CWnd::SetFocus();
	

	CPen solidPen;
	solidPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&solidPen);

	for (vector<Shape*>::const_iterator it = ShapesStack->begin(); it != ShapesStack->end(); ++it)
	{
		Shape* shape = *it;
		shape->Draw(pDC);
	}

	pDC->SelectObject(oldPen);

	ReleaseDC(pDC);
}


// CChildView IO Event Handlers

// Opens a previous saved CRDS file
void CChildView::LoadShapes(string fileSource)
{
	vector<Shape*> loadedShapes = ShapeFileReader::ReadFileSource(fileSource);

	ShapesStack->clear();
	ShapesStack->assign(loadedShapes.begin(), loadedShapes.end());

	view->OnPaint();
}

// Saves the current view to a CRDS file
string CChildView::SaveShapes()
{
	// The source we write to the file over the stream contains the 
	// byte order mark (BOM) for UTF-8 by default.
	string source = "\xef\xbb\xbf";

	for (vector<Shape*>::const_iterator it = ShapesStack->begin(); it != ShapesStack->end(); ++it)
	{
		Shape* shape = *it;
		source.append(shape->ToString());

		delete shape;
	}

	return source;
}

// CChildView Mouse Event Handlers

// Triggers wether the left mouse button is pressed down
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	StartPoint = point;

	if (shapeIndex == -1)
	{
		for (size_t i = 0; i < ShapesStack->size(); ++i)
		{
			if(ShapesStack->at(i)->IsOn(point)) {
				SelectedShape = ShapesStack->at(i);

				SelectedShape->SetIsSelected(true);
				view->OnPaint();

				SelectedShapeIndex = (int)i;
				break;
			}
		}

		return;
	}

	switch (shapeIndex)
	{
		case 1:
			CurrentShape = new ShapeEllipse(StartPoint, point);
			break;
		case 2:
			CurrentShape = new ShapeLine(StartPoint, point);
			break;
		case 3:
			CurrentShape = new ShapeRectangle(StartPoint, point);
			break;
		case 4:
			CurrentShape = new ShapeSquare(StartPoint, point);
			break;
		case 0:
		default:
			CurrentShape = new ShapeCircle(StartPoint, point);
			break;
	}

	CWnd::OnLButtonDown(nFlags, point);
}

// Triggers wether the left mouse button is being released
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (shapeIndex == -1)
		return;

	CDC* pDC = GetDC();

	CurrentShape->SetFrom(StartPoint);
	CurrentShape->SetTo(EndPoint);
	CurrentShape->SetEdges(RGB(75, 91, 117));
	CurrentShape->SetBackground(RGB(153, 167, 193));
	CurrentShape->SetThickness(3);
	CurrentShape->SetStyle(PS_SOLID);
	//CurrentShape->SetText(L"SAY WHAT SAY WHAT");
	CurrentShape->Draw(pDC);

	Shape* shape = CurrentShape;
	ShapesStack->push_back(shape);

	CurrentShape = NULL;

	ReleaseDC(pDC);

	StartPoint.x = -1;
	EndPoint.x = -1;

	CWnd::OnLButtonUp(nFlags, point);
}

void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	if(SelectedShapeIndex != -1) 
	{
		ShapesStack->erase(ShapesStack->begin() + SelectedShapeIndex);
		SelectedShape = NULL;
		SelectedShapeIndex = -1;

		view->InvalidateRect(NULL, true);
		view->GetParent()->PostMessage(WM_PAINT);
		view->OnPaint();
	}
}

// Triggers wether the mouse moves
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (shapeIndex == -1)
		return;

	if (StartPoint.x != -1)
	{
		CDC* pDC = GetDC();

		CPen dotPen;
		dotPen.CreatePen(PS_DOT, 1, RGB(0, 0, 0));
		CPen* oldPen = pDC->SelectObject(&dotPen);

		pDC->SetROP2(R2_NOTXORPEN);

		if (EndPoint.x != -1)
		{
			CurrentShape->SetFrom(StartPoint);
			CurrentShape->SetTo(EndPoint);

			CurrentShape->Draw(pDC);
		}

		CurrentShape->SetFrom(StartPoint);
		CurrentShape->SetTo(point);
		CurrentShape->SetEdges(RGB(75, 91, 117));
		CurrentShape->SetBackground(RGB(153, 167, 193));
		CurrentShape->SetThickness(3);
		CurrentShape->SetStyle(PS_SOLID);

		CurrentShape->Draw(pDC);

		pDC->SelectObject(oldPen);

		ReleaseDC(pDC);
		EndPoint = point;
	}

	CWnd::OnMouseMove(nFlags, point);
}

#endif  // _DEBUG
