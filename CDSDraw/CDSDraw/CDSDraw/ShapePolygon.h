#ifndef SHAPEELLIPSE_H
#define SHAPEELLIPSE_H

#include "Shape.h"
#include "stdafx.h"

#include <string>

using namespace std;

/**
 *	The class ShapeEllipse represents a drawable Ellipse instance of base type Shape.
 */
class ShapePolygon : public Shape
{
private:
	CPoint* points;
	int count;

public:
	ShapePolygon(
		CPoint* points,
		int count,
		CString text = _T(""), 
		COLORREF edges = RGB(0, 0, 0), 
		COLORREF background = RGB(255, 255, 255),
		int thickness = 1,
		int style = PS_SOLID
	);

	~ShapePolygon();

	/**
	 * The method Draw uses the two points 'from' and 'to' to draw and add the shape 
	 * to the instance of the CDC inside the parameter.
	 */
	void Draw(CDC* pDC);

	/**
	 * The method IsOn checks if a partical point is inside the instance of the ellipse. 
	 */
	bool IsOn(CPoint point) const;

	/**
	 * The method ToString writes a shorthand for the type of shape and coordinates 
	 * of the shape to a string (for output to file).
	 */
	string ToString();

	int GetCount() const;
	
	CPoint* GetPoints() const;
	void SetPoints(CPoint* points);
};

#endif