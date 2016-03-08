#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "Point.h"

double EuclideanDistance(Node currentNode, Node nextNode) //Change names
{ //Calculates the euclidean distance between two nodes

	double processX = (nextNode.getX() - currentNode.getX()) * 2;
	double processY = (nextNode.getY() - currentNode.getY()) * 2;
	double distance = sqrt(processX + processY);
	return distance;
}

std::vector<Point> Pathfinder::reconstructPath(Node goalNode)
{
	std::vector<Point> path;

	return path;
}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal, int tileSize)
{
	// TODO: implement the A* algorithm to find a path from start to goal

	Node startNode(start);
	Node goalNode(goal);

	enum neighbourDirections { up, down, left, right };

	std::vector<Node> closedSet;
	std::vector<Node> openSet;
	openSet.push_back(startNode);

	startNode.g = 0;
	startNode.h = EuclideanDistance(startNode, goalNode);

	while (openSet.size() != 0)
	{
		Point current(start.getX(), start.getY());
		Node currentNode(current);

		if (currentNode.getX() == goalNode.getX() && currentNode.getY() == goalNode.getY())
		{
				return reconstructPath(goalNode);
			
		}//End  Xif
	}//End while 

	//remove currentNode from openset
	//add current node to closed set

	//for 

		std::vector<Point> result;
		return result;
	
}




