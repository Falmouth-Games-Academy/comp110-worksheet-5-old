#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"

//EuclideanDistance
double EuclideanDistance(Node currentNode, Node nextNode)
{
	double processX = pow((nextNode.getX() - currentNode.getX()), 2);
	double processY = pow((nextNode.getY() - currentNode.getY()), 2);
	double distance = sqrt(processX + processY);
	return distance;
}

//reconstructor 
std::vector<Point> Pathfinder::reconstructPath(Node goalNode)
{

}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// A* algorithm to find a path from start to goal
	//StartNode and goal node
	Node startNode(start);
	Node goalNode(goal);

	//Closed set and open set
	std::vector<int> closed;
	closed.push_back(x);

	std::vector<Node> open;
	open.push_back(start);

	//Where it starts
	startNode.g = 0;
	//distance to travel
	startNode.h = EuclideanDistance(startNode, goalNode);

	//Came From
	std::vector<std::string> directions{ "above", "below","left","right" };
	startNode.cameFrom = "nothing";

	//goes through open set to find smallest g + h
	while (open.size() > 0);
	{
		double minScore;
		double smallestScore = maxDistance;
		int i = 0;

		for (Node node : open)
		{
			minScore = node.g + node.h;
			if (minScore < smallestScore)
			{
				smallestScore = minScore;
			}
		}


	}
	std::vector<Point> result;
	return result;
}
	

