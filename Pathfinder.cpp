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
	std::vector<Point> path;

	auto currentNode = goalNode;
	while (currentNode)
	{
		path.emplace(path.begin(), currentNode->nodePoint);
		currentNode = currentNode->cameFrom;
	}
	
	return path;
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

std::shared_ptr<Node> Pathfinder::getNode(Point point)
{
	return getNode(point.getX(), point.getY());
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


bool Pathfinder::isInOpenSet(std::shared_ptr<Node> node)
{
	// Make a copy of the openSet
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, CompareNodeScore> openSetTemp = openSet;

	while (!openSetTemp.empty())
	{
		// Return true if the top one matches, otherwise it gets removed
		if (openSetTemp.top() == node)
		{
			return true;
		}

		openSetTemp.pop();
	}

	return false;
}


// This is for removing a node from the priority queue before its g or h changes
void Pathfinder::removeOpenSetNode(std::shared_ptr<Node> node)
{
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, CompareNodeScore> openSetTemp = openSet;

	while (isInOpenSet(node))
	{
		// Remove elements from openSet and add them to temporary set until the specified node is removed
		openSetTemp.push(openSet.top());
		openSet.pop();
	}

	while (!openSetTemp.empty())
	{
		// Put all of the nodes back into openSet except for the specified node
		if (node != openSetTemp.top())
		{
			openSet.push(openSetTemp.top());
			openSetTemp.pop();
		}
		else
		{
			openSetTemp.pop();
		}
	}
}


std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// Initialise vector to the size of the map and each element to nullptr
	nodes.clear();
	for (int x = 0; x < map.getWidth(); x++)
	{
		nodes.push_back(std::vector<std::shared_ptr<Node>>(map.getHeight(), nullptr));
	}

	std::shared_ptr<Node> goalNode = getNode(goal);
	std::shared_ptr<Node> startNode = getNode(start);
	startNode->g = 0;
	startNode->h = euclideanDistance(startNode->nodePoint, goalNode->nodePoint);
	startNode->cameFrom = nullptr;
	// Add the start node to the open set
	openSet.push(startNode);

	std::shared_ptr<Node> currentNode;

	while (!openSet.empty())
	{
		// The node with the lowest g+h score
		currentNode = openSet.top();

		if (currentNode == goalNode)
		{
			// A path to the goal has been found
			return reconstructPath(goalNode);
		}

		// Add current node to closed set and remove from open set
		currentNode->closed = true;
		openSet.pop();

		for each (std::shared_ptr<Node> neighbourNode in getNeighbours(currentNode))
		{
			if (!map.isWall(neighbourNode->getX(), neighbourNode->getY()) && !neighbourNode->closed)
			{
				// Current g plus the distance fr5om this node to the neighbour
				int gTentative = currentNode->g + euclideanDistance(currentNode->nodePoint, neighbourNode->nodePoint);

				if (!isInOpenSet(neighbourNode) || gTentative < neighbourNode->g)
				{
					// Remove from priority queue before g+h score changes
					if (isInOpenSet(neighbourNode))
					{
						removeOpenSetNode(neighbourNode);
					}
					
					neighbourNode->g = gTentative;
					neighbourNode->h = euclideanDistance(neighbourNode->nodePoint, goalNode->nodePoint);
					neighbourNode->cameFrom = currentNode;

					// Add node into (or back into) the priority queue
					openSet.push(neighbourNode);
				}
			}
		}
	}

	// If it gets here, a path was not found
	throw PathfinderError();
}


