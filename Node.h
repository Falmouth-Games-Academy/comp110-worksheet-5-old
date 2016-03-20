#pragma once
#include "Point.h"

class Node
{
public:
	Node(const Point& point);
	~Node();

	Point nodePoint;
	double g = 0, h = 0;
	std::shared_ptr<Node> cameFrom;

	bool closed = false;
};

