#include "stdafx.h"
#include "Pathfinder.h"

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// TODO: implement the A* algorithm to find a path from start to goal

	std::vector<Point> closedSet;
	std::vector<Point> openSet = {start};


	std::vector<Point> result;
	return result;
}


std::vector<Point> Pathfinder::reconstructPath(const Point& goalNode)
{

}


int EuclideanDistance(Point currentNode, Point nextNode) //Change names
{
	double processX = (nextNode.getX - currentNode.getX) * 2;
	double processY = (nextNode.getY - currentNode.getY) * 2;
	double distance = sqrt(processX + processY);
	return distance;
}

