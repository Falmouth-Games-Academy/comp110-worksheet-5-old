#pragma once
#include "Point.h"

class Node

{
public:
	Node(Point point);
	~Node();

	int getX() { return nodeX; }
	int getY() { return nodeY; }

	int setX(int newX) { nodeX = newX;  }
	int setY(int newY) { nodeX = newY; }

	

	double g, h;

private:
	int nodeX, nodeY;
};

