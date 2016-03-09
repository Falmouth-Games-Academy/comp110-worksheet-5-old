#include "stdafx.h"
#include "Node.h"

//constructor

Node::Node(Point point)
{
	int newX = point.getX();
	int newY = point.getY();
	setX(newX);
	setY(newY);
}


Node::~Node()
{
}
