#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"



double Pathfinder::euclideanDistance(const Point& a, const Point& b)
{
	double xDistance = a.getX() - b.getX();
	double yDistance = a.getY() - b.getY();
	return sqrt(xDistance*xDistance + yDistance*yDistance);
}

std::vector<Point> Pathfinder::reconstructPath(std::shared_ptr<Node> goalNode)
{
	std::vector<Point> result;
	return result;
}


std::shared_ptr<Node> Pathfinder::getNode(int x, int y)
{
	std::shared_ptr<Node> node = nodes[x][y];
	if (!node)
	{
		node = std::make_shared<Node>(x, y);
		nodes[x][y] = node;
	}
	return node;
}

std::vector<std::shared_ptr<Node>> Pathfinder::getNeighbours(std::shared_ptr<Node> node)
{
	std::vector<std::shared_ptr<Node>> neighbours;
	neighbours.push_back(getNode(node->getX() - 1, node->getY()));
	neighbours.push_back(getNode(node->getX() + 1, node->getY()));
	neighbours.push_back(getNode(node->getX(), node->getY() + 1));
	neighbours.push_back(getNode(node->getX(), node->getY() - 1));

	return neighbours;
}


std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// Initialise vector to the size of the map and each element to nullptr
	nodes.clear();
	for (int x = 0; x < map.getWidth(); x++)
	{
		nodes.push_back(std::vector<std::shared_ptr<Node>>(map.getHeight(), nullptr));
	}

	std::shared_ptr<Node> goalNode = std::make_shared<Node>(goal);

	// Add the start node to the open set
	std::shared_ptr<Node> startNode = std::make_shared<Node>(start);
	openSet.push(startNode);
	startNode->g = 0;
	startNode->h = euclideanDistance(startNode->nodePoint, goalNode->nodePoint);
	startNode->cameFrom = nullptr;

	std::shared_ptr<Node> currentNode;

	while (!openSet.empty())
	{
		currentNode = openSet.top();
		if (currentNode == goalNode)
		{
			return reconstructPath(goalNode);
		}

		currentNode->closed = true;
		openSet.pop();

		for each (std::shared_ptr<Node> neighbourNode in getNeighbours(currentNode))
		{

		}
	}


	std::vector<Point> result;
	return result;
	
}


