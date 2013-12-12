#ifndef SHAPEELLIPSE_H
#define SHAPEELLIPSE_H

#include "Shape.h"
#include "stdafx.h"

#include <string>

using namespace std;

/**
 *	The class ShapeEllipse represents a drawable Ellipse instance of base type Shape.
 */
class ShapeEllipse : public Shape
{
public:
	ShapeEllipse(CPoint from, CPoint to);
	~ShapeEllipse();

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
};

#endif