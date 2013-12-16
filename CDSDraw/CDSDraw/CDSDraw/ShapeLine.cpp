#include "stdafx.h"

#include "Shape.h"
#include "ShapeLine.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapeLine::ShapeLine(CPoint from, CPoint to, CString text, COLORREF edges, COLORREF background, int thickness, int style)
	: Shape(from, to, text, edges, background, thickness, style) {}

ShapeLine::~ShapeLine() {}

void ShapeLine::Draw(CDC* pDC)
{
	CPen penBlue(style, thickness, edges);
	CPen* pOldPen = pDC->SelectObject(&penBlue);

	CBrush brushRed(background);
	CBrush* pOldBrush = pDC->SelectObject(&brushRed);

	pDC->MoveTo(from);
	pDC->LineTo(to);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->TextOutW(from.x, from.y, text);
}

bool ShapeLine::IsOn(CPoint point) const 
{
	float slope, interception;
	float px, py;
	float left, top, right, bottom;
	float dx, dy;

	dx = (to.x - from.x);
	dy = (to.y - from.y);

	slope = (dy / dx);
	interception = (from.y - slope * from.x);

	if (from.x < to.x)
	{
		left = from.x;
		right = to.x;
	}
	else
	{
		left = to.x;
		right = from.x;
	}

	if (from.y < to.y)
	{
		top = from.y;
		bottom = to.y;
	}
	else
	{
		top = to.y;
		bottom = from.y;
	}

	if ((slope * point.x + interception > (point.y - 0.01)) && (slope * point.x + interception < (point.y + 0.01)))
	{
		if (point.x >= left && point.x <= right && point.y >= top && point.y <= bottom)
			return true;

		return false;
	}

	return false;
}

string ShapeLine::ToString()
{
	stringstream string_stream;
	string_stream << "l;" << from.x << ";" << from.y << ";" << to.x << ";" << to.y << ";|";

	return string_stream.str();
}