#ifndef SHAPERECTANGLE_H
#define SHAPERECTANGLE_H

#include "Shape.h"
#include "stdafx.h"

#include <string>

using namespace std;

/**
 *	The class ShapeRectangle represents a drawable Rectangle instance of base type Shape.
 */
class ShapeRectangle : public Shape
{
public:
	ShapeRectangle(CPoint from, CPoint to);
	~ShapeRectangle();

	/**
	 * The method Draw uses the two points 'from' and 'to' to draw and add the shape 
	 * to the instance of the CDC inside the parameter.
	 */
	void Draw(CDC* pDC);

	/**
	 * The method IsOn checks if a partical point is inside the instance of the rectangle.
	 */
	bool IsOn(CPoint point) const;
	
	/**
	 * The method ToString writes a shorthand for the type of shape and coordinates 
	 * of the shape to a string (for output to file).
	 */
	string ToString();
};

#endif