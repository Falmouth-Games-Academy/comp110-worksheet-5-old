#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "Point.h"

double EuclideanDistance(Node currentNode, Node nextNode) //Change names
{ //Calculates the euclidean distance between two nodes

	double processX = pow((nextNode.getX() - currentNode.getX()), 2);
	double processY = pow(nextNode.getY() - currentNode.getY(),2);
	double distance = sqrt(processX + processY);
	return distance;
}

std::vector<Point> Pathfinder::reconstructPath(Node goalNode)
{
	std::vector<Point> path;
	Node currentNode = goalNode; //Not sure if right
	Point currentPoint(goalNode.getX(), goalNode.getY());
	

	while (true)
	{
		path.push_back(currentPoint);
		//currentNode = currentNode.cameFrom ??
	}//End while 

	return path;
}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal, int tileSize)
{

	Node startNode(start);
	Node goalNode(goal);
	//startNode.cameFrom = NULL;

	enum neighbourDirections { up, down, left, right, null };  //options for node.cameFrom

	std::vector<Node> closedSet;
	std::vector<Node> openSet;
	openSet.push_back(startNode);

	startNode.g = 0;
	startNode.h = EuclideanDistance(startNode, goalNode);
	

	while (openSet.size() != 0)
	{
		double currentX, currentY, score;
		double lowestScore = maxDistance;
		
		for (Node node : openSet)
		{// Goes though all nodes in openset finds the one with the lowest g + h value
			score = node.g + node.h;

			if (score < lowestScore)
			{
				lowestScore = score;
				currentX = node.getX();
				currentY = node.getY();
			}//end if
		}//End for loop


		Point current(currentX, currentY);
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




