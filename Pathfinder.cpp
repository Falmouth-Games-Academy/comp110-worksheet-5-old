#pragma once
#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "EuclideanDistance.h"

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal)
{
	// TODO: implement the A* algorithm to find a path from start to goal
	
	//Start node from Node
	Node startNode(start);

	//Goal node from Node
	Node goalNode(goal);
	
	//if dir==4
	const int dir = 4;
	static int x[dir] = { 1, 0, -1, 0 };
	static int y[dir] = { 0, 1, 0, -1 };
	
	//closedSet is empty
	std::vector<Node> closedSet;

	//openSet has startNode in
	std::priority_queue<Node, std::vector<Node>, ComparePriority> openSet;
	openSet.push(startNode);

	//startNode.g is set 0
	startNode.g = 0;

	//Euclidean Distance startNode goalNode
	startNode.h = EuclideanDistance(startNode, goalNode);

	//cameFrom
	startNode.cameFrom = nullptr;

	//while
	while (!openSet.empty())
	{
		//getFValue
		Node currentNode(openSet.top());

		if currentNode = goalNode
		{
			return ReconstructPath(goalNode);
		}
		//remove currentNode from openSet
		openSet.pop();
		closedSet.push_back(currentNode);

		static int i;
		for (i = 0; i < dir; i++)
		{
			nextXPos = currentXPos + x[i];
			nextYPos = currentYPos + y[i];
			const Point& neighbourNode = (nextXPos, nextYPos);
			Map* map;
			if(!neighbourNode = map.isWall)
		}
	}
	//end



	std::vector<Point> result;
	return result;
}
