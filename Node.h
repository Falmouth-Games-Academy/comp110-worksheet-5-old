#pragma once
#include "Point.h"
#include "Pathfinder.h"

class Node
{

public:
	Node(const Point& point);
	~Node();

	//start point of mouse
	Point startPoint;
	//Point cameFrom;
	//Point goalPoint;

	int getX() const { return xPos; }
	int getY() const { return yPos; }

	//total distance already travelled
	int getGValue() const { return g; }

	//EuclideanDistance 
	int getHValue() const { return h; }

	//Lowest is current priority
	int getFValue() const { return f; }

	struct ComparePriority;

	std::string name;
	//Point getPriority();

	//start position of path
	//int startXPos;
	//int startXPos;

	//goal position of path
	//int GoalXPos;
	//int GoalYPos;

private:
	//current position of node
	int xPos;
	int yPos;

	//total distance to current
	int g;

	//Euclidean Distance
	int h;

	//GValue + HValue
	int f;
};