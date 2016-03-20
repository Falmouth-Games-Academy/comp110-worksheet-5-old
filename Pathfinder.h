#pragma once

#include "Map.h"
#include "Node.h"

struct CompareNodeScore
{
	bool operator()(const std::shared_ptr<Node>& left, const std::shared_ptr<Node>& right)
	{
		return left->g + left->h > right->g + right->h;
	}
};

class Pathfinder
{
public:
	std::vector<Point> findPath(const Map& map, const Point& start, const Point& goal);
	double euclideanDistance(const Point& a, const Point& b);

	std::vector<std::vector<std::shared_ptr<Node>>> nodes;

	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, CompareNodeScore> openSet;

private:
	std::vector<Point> reconstructPath(std::shared_ptr<Node> goalNode);
	std::shared_ptr<Node> getNode(int x, int y);
	std::vector<std::shared_ptr<Node>> getNeighbours(std::shared_ptr<Node> node);
	bool isInOpenSet(std::shared_ptr<Node> node);
	void updateOpenSet();
	void removeOpenSetNode(std::shared_ptr<Node> node);
};
