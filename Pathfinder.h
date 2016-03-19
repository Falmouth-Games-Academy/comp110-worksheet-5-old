#pragma once

#include "Map.h"
#include "Node.h"

class Pathfinder
{
public:
	std::vector<Point> findPath(const Map& map, const Point& start, const Point& goal, int tileSize);
	std::vector<std::shared_ptr<Node>> neighbourNodes;
	std::vector<Point> Pathfinder::reconstructPath(std::shared_ptr<Node> goalNode);

	int maxDistance = 100;

};
