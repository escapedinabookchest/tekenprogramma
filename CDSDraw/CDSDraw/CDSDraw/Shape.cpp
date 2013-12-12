#include "stdafx.h"
#include "Shape.h"
#include <Windows.h>

Shape::Shape(CPoint from, CPoint to)
{
	this->from = from;
	this->to = to;
}

Shape::~Shape() {}