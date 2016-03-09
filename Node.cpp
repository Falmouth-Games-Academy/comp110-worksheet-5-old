#include "stdafx.h"
#include "Node.h"


Node::Node(Point point)
{
	// gets X and Y values from the given Point and sets them as the X and Y values for the Node
	int newX = point.getX();
	int newY = point.getY();
	setX(newX);
	setY(newY);
}


Node::~Node()
{
}
