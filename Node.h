#pragma once
#include "Point.h"

class Node

{
public:
	Node(Point point);
	Node(int x, int y);
	~Node();

	Point nodePoint;

	int getX() { return nodeX; }
	int getY() { return nodeY; }

	int setX(int newX) { return nodeX = newX;  }
	int setY(int newY) { return nodeY = newY; }
	
	double g = 0, h = 0;

	std::shared_ptr<Node> cameFrom;

private:
	int nodeX = 0, nodeY = 0;
};

