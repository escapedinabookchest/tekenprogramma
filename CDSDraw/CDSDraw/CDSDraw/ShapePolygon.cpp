#include "stdafx.h"

#include "Shape.h"
#include "ShapePolygon.h"

#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

ShapePolygon::ShapePolygon(CPoint* points, int count, CString text, COLORREF edges, COLORREF background, int thickness, int style)
	: Shape(from, to, text, edges, background, thickness, style) 
{
	this->points = points;
	this->count = count;
}

ShapePolygon::~ShapePolygon() {}

void ShapePolygon::Draw(CDC* pDC)
{
	CPen penBlue(style, thickness, edges);
	CPen* pOldPen = pDC->SelectObject(&penBlue);

	CBrush brushRed(background);
	CBrush* pOldBrush = pDC->SelectObject(&brushRed);

	pDC->Polygon(points, count);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->TextOutW(from.x, from.y, text);
}

bool ShapePolygon::IsOn(CPoint point) const 
{
	CRect rectangle(from.x, from.y, to.x, to.y);

	if(rectangle.PtInRect(point))
		return true;

	return false;
}

string ShapePolygon::ToString()
{
	stringstream string_stream;
	string_stream << "r;" << from.x << ";" << from.y << ";" << to.x << ";" << to.y << ";|";

	return string_stream.str();
}

int ShapePolygon::GetCount() const
{
	return this->count;
}
	
CPoint* ShapePolygon::GetPoints() const
{
	return this->points;
}

void ShapePolygon::SetPoints(CPoint* points)
{
	this->points = points;
}