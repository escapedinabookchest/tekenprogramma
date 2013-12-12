#ifndef SHAPE_H
#define SHAPE_H

#include "stdafx.h"
#include <string>

using namespace std;

/**
 * The abstract class Shape represents the base class with all basic functionality for all 
 * shapes supported by the program.
 */
class Shape
{
public:
	bool isSelected;

	CPoint from;
	CPoint to;

	/**
	 * The constructor uses the two points inside the parameters to draw the supported shape.
	 */
	Shape(CPoint from, CPoint to);
	~Shape();

	/**
	 * The method Draw uses the two points 'from' and 'to' to draw and add the shape 
	 * to the instance of the CDC inside the parameter.
	 */
	virtual void Draw(CDC* pDC) = 0;

	/**
	 * The method IsOn checks if a partical point is inside the instance of a supported shape. 
	 */
	virtual bool IsOn(CPoint point) const = 0;
	
	/**
	 * The method ToString writes a shorthand for the type of shape and coordinates 
	 * of the shape to a string (for output to file).
	 */
	virtual string ToString() = 0;
};

#endif