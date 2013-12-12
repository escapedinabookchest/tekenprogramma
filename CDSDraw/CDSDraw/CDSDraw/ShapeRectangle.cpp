#include "stdafx.h"

#include "Shape.h"
#include "ShapeRectangle.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapeRectangle::ShapeRectangle(CPoint from, CPoint to)
	: Shape(from, to) {}

ShapeRectangle::~ShapeRectangle() {}

void ShapeRectangle::Draw(CDC* pDC)
{
	pDC->Rectangle(from.x, from.y, to.x, to.y);
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