#include "stdafx.h"

#include "Shape.h"
#include "ShapeCircle.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapeCircle::ShapeCircle(CPoint from, CPoint to)
	: Shape(from, to)
{
	radius = 0;
}

ShapeCircle::~ShapeCircle() {}

void ShapeCircle::Draw(CDC* pDC)
{
	radius = (int) sqrt((double)
		(to.x - from.x) * (to.x - from.x) + 
		(to.y - from.y) * (to.y - from.y));

	CRect circle((from.x - radius), (from.y - radius),
			     (from.x + radius), (from.y + radius));

	pDC->Ellipse(circle);
}

bool ShapeCircle::IsOn(CPoint point) const 
{
	CRect circle((from.x - radius), (from.y - radius),
			     (from.x + radius), (from.y + radius));

	if(circle.PtInRect(point))
		return true;

	return false;
}

string ShapeCircle::ToString()
{
	stringstream string_stream;
	string_stream << "c;" << from.x << ";" << from.y << ";" << to.x << ";" << to.y << ";|";

	return string_stream.str();
}