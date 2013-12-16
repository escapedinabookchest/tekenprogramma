#define _CRTDBG_MAP_ALLOC

#include "stdafx.h"

#include "Shape.h"
#include "ShapeRectangle.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapeRectangle::ShapeRectangle(CPoint from, CPoint to, CString text, COLORREF edges, COLORREF background, int thickness, int style)
	: Shape(from, to, text, edges, background, thickness, style) {}

ShapeRectangle::~ShapeRectangle() {}

void ShapeRectangle::Draw(CDC* pDC)
{
	CPen penBlue(style, thickness, edges);
	CPen* pOldPen = pDC->SelectObject(&penBlue);

	CBrush brushRed(background);
	CBrush* pOldBrush = pDC->SelectObject(&brushRed);

	pDC->Rectangle(from.x, from.y, to.x, to.y);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->TextOutW(from.x, from.y, text);
}

bool ShapeRectangle::IsOn(CPoint point) const 
{
	CRect rectangle(from.x, from.y, to.x, to.y);

	if(rectangle.PtInRect(point))
		return true;

	return false;
}

string ShapeRectangle::ToString()
{
	stringstream string_stream;
	string_stream << "r;" << from.x << ";" << from.y << ";" << to.x << ";" << to.y << ";|";

	return string_stream.str();
}