#ifndef SHAPEFILEREADER_H
#define SHAPEFILEREADER_H

#include "Shape.h"
#include <string>
#include <vector>

using namespace std;

/**
* The class ShapeFileReader is a helper class for reading a .dscr file.
*/
class ShapeFileReader
{
public:
	/**
	 * The method ReadFileSource Reads the source of a .dscr file and returns a list of shapes retrieved from the source.
	 */
	static vector<Shape*> ReadFileSource(string fileSource);

private:
	/**
	 * The method ParseShapes parses all the shapes from a textfile to a string-based source and put them inside a vector.
	 */
	static vector<string> ParseShapes(string source);

	/**
	 * The method ParseShapeType parses the shape-type in a string-based source.
	 */
	static string ParseShapeType(string source);

	/**
	 * The moethod ParseShapeType parses the shape-parameters in a string-based source.
	 */
	static vector<string> ParseShapeParameters(string source);
};

#endif