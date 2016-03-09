#pragma once

#include "Map.h"

class Pathfinder
{
public:
	std::vector<Point> findPath(const Map& map, const Point& start, const Point& goal);
	std::vector<Point> reconstructPath(Node endNode);

};
