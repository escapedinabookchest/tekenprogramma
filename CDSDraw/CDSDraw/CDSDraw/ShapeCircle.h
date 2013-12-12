#ifndef SHAPECIRCLE_H
#define SHAPECIRCLE_H

#include "Shape.h"
#include "stdafx.h"

#include <string>

using namespace std;

/**
 *	The class ShapeCircle represents a drawable Circle instance of base type Shape.
 */
class ShapeCircle : public Shape
{
private:
	int radius; // is used to calculate the area of the circle.

public:
	ShapeCircle(CPoint from, CPoint to);
	~ShapeCircle();

	/**
	 * The method Draw uses the two points 'from' and 'to' to draw and add the shape 
	 * to the instance of the CDC inside the parameter.
	 */
	void Draw(CDC* pDC);

	/**
	 * The method IsOn checks if a partical point is inside the instance of the circle. 
	 */
	bool IsOn(CPoint point) const;
	
	/**
	 * The method ToString writes a shorthand for the type of shape and coordinates 
	 * of the shape to a string (for output to file).
	 */
	string ToString();
};

#endif