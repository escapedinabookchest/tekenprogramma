#include "stdafx.h"

#include "Shape.h"
#include "ShapeEllipse.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapeEllipse::ShapeEllipse(CPoint from, CPoint to)
	: Shape(from, to) { }

ShapeEllipse::~ShapeEllipse() {}

void ShapeEllipse::Draw(CDC* pDC)
{
	pDC->Ellipse(from.x, from.y, to.x, to.y);
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