#include "stdafx.h"

#include "Shape.h"
#include "ShapeEllipse.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapeEllipse::ShapeEllipse(CPoint from, CPoint to, CString text, COLORREF edges, COLORREF background, int thickness, int style)
	: Shape(from, to, text, edges, background, thickness, style) {}

ShapeEllipse::~ShapeEllipse() {}

void ShapeEllipse::Draw(CDC* pDC)
{
	CPen penBlue(style, thickness, edges);
	CPen* pOldPen = pDC->SelectObject(&penBlue);

	CBrush brushRed(background);
	CBrush* pOldBrush = pDC->SelectObject(&brushRed);

	pDC->Ellipse(from.x, from.y, to.x, to.y);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->TextOutW(from.x, from.y, text);
}

bool ShapeEllipse::IsOn(CPoint point) const 
{
	int radius = (int) sqrt((double)
		(to.x - from.x) * (to.x - from.x) +
		(to.y - from.y) * (to.y - from.y));

	CRect ellipse((from.x - radius), (from.y - radius),
				  (from.x + radius), (from.y + radius));

	if (ellipse.PtInRect(point))
		return true;

	return false;
}

string ShapeEllipse::ToString()
{
	stringstream string_stream;
	string_stream << "e;" << from.x << ";" << from.y << ";" << to.x << ";" << to.y << ";|";

	return string_stream.str();
}