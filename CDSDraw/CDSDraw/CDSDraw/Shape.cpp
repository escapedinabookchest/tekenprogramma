#include "stdafx.h"
#include "Shape.h"
#include <Windows.h>

Shape::Shape(CPoint from, CPoint to, CString text, COLORREF edges, COLORREF background, int thickness, int style)
{
	this->from = from;
	this->to = to;
	this->text = text;
	this->edges = edges;
	this->background = background;
	this->thickness = thickness;
	this->style = style;
}

Shape::~Shape() {}

CPoint Shape::GetFrom() const
{
	return this->from;
}

void Shape::SetFrom(CPoint from)
{
	this->from = from;
}

CPoint Shape::GetTo() const 
{
	return this->to;
}
	
void Shape::SetTo(CPoint to)
{
	this->to = to;
}

CString Shape::GetText() const 
{
	return this->text;
}

void Shape::SetText(CString text)
{
	this->text = text;
}

COLORREF Shape::GetEdges() const
{
	return this->edges;
}

void Shape::SetEdges(COLORREF edges)
{
	this->edges = edges;
}

COLORREF Shape::GetBackground() const 
{
	return this->background;
}

void Shape::SetBackground(COLORREF background)
{
	this->background = background;
}

int Shape::GetThickness() const
{
	return this->thickness;
}

void Shape::SetThickness(int thickness)
{
	this->thickness = thickness;
}

int Shape::GetStyle() const
{
	return this->style;
}

void Shape::SetStyle(int style)
{
	this->style = style;
}

bool Shape::IsSelected() const
{
	return this->isSelected;
}

void Shape::SetIsSelected(bool isSelected)
{
	this->isSelected = isSelected;
}
	