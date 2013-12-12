#include "stdafx.h"

#include "Shape.h"
#include "ShapeSquare.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapeSquare::ShapeSquare(CPoint from, CPoint to)
	: Shape(from, to)
{
	diagonal = 0;
}

ShapeSquare::~ShapeSquare() {}

void ShapeSquare::Draw(CDC* pDC)
{
	diagonal = (int) sqrt((double)
		(to.x - from.x) * (to.x - from.x) +
		(to.y - from.y) * (to.y - from.y));

	CRect square(from.x, from.y,
				 (from.x + diagonal), (from.y + diagonal));

	pDC->Rectangle(square);
}

bool ShapeSquare::IsOn(CPoint point) const 
{
	CRect square(from.x, from.y,
				 (from.x + diagonal), (from.y + diagonal));

	if(square.PtInRect(point))
		return true;

	return false;
}

string ShapeSquare::ToString()
{
	stringstream string_stream;
	string_stream << "s;" << from.x << ";" << from.y << ";" << to.x << ";" << to.y << ";|";

	return string_stream.str();
}