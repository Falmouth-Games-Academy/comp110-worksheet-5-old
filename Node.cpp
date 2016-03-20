#include "stdafx.h"
#include "Node.h"


Node::Node(const Point& point)
	:nodePoint(point)
{
}


Node::Node(int x, int y)
	: nodePoint(Point(x, y))
{
}


Node::~Node()
{
}
