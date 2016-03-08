#pragma once

#include "Map.h"
#include "Node.h"

class Pathfinder
{
public:
	std::vector<Point> findPath(const Map& map, const Point& start, const Point& goal, int tileSize);
	std::vector<Point> Pathfinder::reconstructPath(Node goalNode);

};
