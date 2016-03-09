#include "stdafx.h"
#include "EuclideanDistance.h"
#include "Node.h"
#include "Map.h"
#include "PathfindingApp.h"


EuclideanDistance::EuclideanDistance(const Node& currentNode, const Node& nextNode)
	: currentPoint(currentNode),
	nextPoint(nextNode),
	currentXPos(currentPoint.getX()), currentYPos(currentPoint.getY()),
	nextXPos(nextPoint.getX()), nextYPos(nextPoint.getY())
{
	double dx = nextXPos - currentXPos;
	double dy = nextYPos - currentYPos;
	double dx_sqr = pow(dx, 2);
	double dy_sqr = pow(dy, 2);

	double distance = (sqrt((dx_sqr) + (dy_sqr)));
	/*
	double distance(double currentXPos, double currentYPos, double nextXPos, double nextYPos);
	{
		double dx = nextXPos - currentXPos;
		double dy = nextYPos - currentYPos;

		d = (double(sqrt(pow(dx), 2) + pow(dy), 2));
	}
	*/
}


EuclideanDistance::~EuclideanDistance()
{
}