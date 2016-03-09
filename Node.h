#pragma once
#include "Point.h"

class Node

{
public:
	Node(Point point);
	~Node();

	double g = 0;
	double h = 0;

	int getX() { return nodeX; }
	int getY() { return nodeY; }

	int setX(int newX) { return nodeX = newX; }
	int setY(int newY) { return nodeX = newY; }

	std::string cameFrom;


private:
	int nodeX, nodeY;
};
