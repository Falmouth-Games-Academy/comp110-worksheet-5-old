#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"


double Pathfinder::euclideanDistance(const Point& a, const Point& b)
{
	double xDistance = a.getX() - b.getX();
	double yDistance = a.getY() - b.getY();
	return sqrt(xDistance*xDistance + yDistance*yDistance);
}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// TODO: implement the A* algorithm to find a path from start to goal
	std::shared_ptr<Node> startNode = std::make_shared<Node>(start);
	std::shared_ptr<Node> goalNode = std::make_shared<Node>(goal);
	startNode->g = 0;
	startNode->h = euclideanDistance(startNode->nodePoint, goalNode->nodePoint);

	std::vector<Point> result;
	return result;
}
