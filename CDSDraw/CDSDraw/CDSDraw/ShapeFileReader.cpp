#define _CRTDBG_MAP_ALLOC

#include "stdafx.h"

#include "ShapeFileReader.h"

#include "Shape.h"
#include "ShapeCircle.h"
#include "ShapeEllipse.h"
#include "ShapeLine.h"
#include "ShapeRectangle.h"
#include "ShapeSquare.h"

#include <string>
#include <vector>

using namespace std;

vector<string> ShapeFileReader::ParseShapes(string source)
{
	int index = 0;

	const string delimiter = "|";

	vector<string> shapes;
	size_t position = 0;

	while ((position = source.find(delimiter)) != string::npos)
	{
		shapes.push_back(source.substr(0, position));
		source.erase(0, (position + delimiter.length()));

		index++;
	}

	return shapes;
}

string ShapeFileReader::ParseShapeType(string source)
{
	const string delimiter = ";";

	string shapeType;
	size_t position = source.find(delimiter);

	shapeType = source.substr(0, position);

	return shapeType;
}

vector<string> ShapeFileReader::ParseShapeParameters(string source)
{
	const string delimiter = ";";

	string pSource = source.substr(0, source.length());
	vector<string> shapeParameters;
	size_t position = 0;
	int index = 0;

	while ((position = pSource.find(delimiter)) != string::npos)
	{
		if (index != 0)
			shapeParameters.push_back(pSource.substr(0, position));
		
		pSource.erase(0, (position + delimiter.length()));

		index++;
	}

	return shapeParameters;
}

vector<Shape*> ShapeFileReader::ReadFileSource(string fileSource)
{
	//Take care of the BOM
	fileSource.erase(0, 3);

	//Start parsing the retrieved file source
	vector<Shape*> shapeStack = vector<Shape*>();
	vector<string> shapes = ParseShapes(fileSource);

	vector<vector<string>> parameters = vector<vector<string>>();
	vector<string> types = vector<string>();

	for (vector<string>::const_iterator it = shapes.begin(); it != shapes.end(); ++it)
	{
		parameters.push_back(ParseShapeParameters(*it));
		types.push_back(ParseShapeType(*it));
	}

	int type_index = 0;
	for (vector<string>::const_iterator it = types.begin(); it != types.end(); ++it)
	{
		string shapeType = *it;
		Shape* shape;

		for (vector < vector < string >> ::size_type i = type_index; i < parameters.size(); i++)
		{
			CPoint from = CPoint(stoi(parameters[i][0]), stoi(parameters[i][1]));
			CPoint to = CPoint(stoi(parameters[i][2]), stoi(parameters[i][3]));

			if (shapeType == "c")
				shapeStack.push_back(new ShapeCircle(from, to));
			else if (shapeType == "e")
				shapeStack.push_back(new ShapeEllipse(from, to));
			else if (shapeType == "l")
				shapeStack.push_back(new ShapeLine(from, to));
			else if (shapeType == "r")
				shapeStack.push_back(new ShapeRectangle(from, to));
			else if (shapeType == "s")
				shapeStack.push_back(new ShapeSquare(from, to));

			break;
		}

		type_index++;
	}
		
	return shapeStack;
}