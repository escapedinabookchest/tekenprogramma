#ifndef SHAPELINE_H
#define SHAPELINE_H

#include "Shape.h"
#include "stdafx.h"

#include <string>

using namespace std;

/**
 *	The class ShapeSquare represents a drawable Line instance of base type Shape.
 */
class ShapeLine : public Shape
{
public:
	ShapeLine(CPoint from, CPoint to);
	~ShapeLine();

	/**
	 * The method Draw uses the two points 'from' and 'to' to draw and add the shape 
	 * to the instance of the CDC inside the parameter.
	 */
	void Draw(CDC* pDC);

	/**
	 * The method IsOn checks if a partical point is inside the instance of the line. 
	 */
	bool IsOn(CPoint point) const;
	
	/**
	 * The method ToString writes a shorthand for the type of shape and coordinates 
	 * of the shape to a string (for output to file).
	 */
	string ToString();
};

#endif