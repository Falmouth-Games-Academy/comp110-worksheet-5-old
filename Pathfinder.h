#pragma once

#include "Map.h"

class Pathfinder
{
public:
	std::vector<Point> findPath(const Map& map, const Point& start, const Point& goal);
	double euclideanDistance(const Point& a, const Point& b);

};
