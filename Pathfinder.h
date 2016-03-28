#pragma once

#include "Map.h"
#include "Node.h"

class Pathfinder
{
public:
	std::vector<Point> findPath(const Map& map, const Point& start, const Point& goal, int tileSize);
	std::vector<std::shared_ptr<Node>> neighbourNodes;
	std::vector<Point> reconstructPath(std::shared_ptr<Node> goalNode);
	
	std::shared_ptr<Node> createNode(int x, int y);
	std::vector<std::shared_ptr<Node>> getNeighbourNodes(std::shared_ptr<Node> currentNode);
	bool checkForNodeInVector(std::shared_ptr<Node> node, std::vector<std::shared_ptr<Node>> nodeSet);

	int maxDistance = 1000;

};
