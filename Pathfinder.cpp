#include "stdafx.h"
#include "Pathfinder.h"
#include "PathfindingApp.h"
#include "Node.h"

/* Works out the distance to the goal from the current point */
double EuclideanDistance(Node currentNode, Node nextNode)
{
	double start = currentNode.getX() - currentNode.getY();
	double next = nextNode.getX() - nextNode.getY();
	double distance = sqrt(start + next);
	return distance;

}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// TODO: implement the A* algorithm to find a path from start to goal
	
	Node startNode(start);
	Node endNode(goal);

	std::vector<std::string> Walls{ "up", "down", "left", "right" };
	startNode.cameFrom = "NA";

	// Closed Set
	std::vector<Node> closedSet;

	//Open Set
	std::vector<Node> OpenSet;

	//OpenSet.push_back(startNode);
	startNode.g = 0;
	startNode.h = EuclideanDistance(startNode, endNode);

	while (OpenSet.size() != 0)
	{
		double nodeScore;
		double lowestScore;


		for (Node node : OpenSet)
		{
			nodeScore = node.g + node.h;

		}

	}

	std::vector<Point> result;

	return result;
}
