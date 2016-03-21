#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "Point.h"

double EuclideanDistance(std::shared_ptr<Node> currentNode, std::shared_ptr<Node> nextNode) //Change names
{ //Calculates the euclidean distance between two nodes

  //Squares the difference between the values of each node's X and Y values
	double processX = pow((nextNode->getX() - currentNode->getX()), 2);
	double processY = pow(nextNode->getY() - currentNode->getY(), 2);

	double distance = sqrt(processX + processY);
	return distance;
}


std::vector<Point> Pathfinder::reconstructPath(std::shared_ptr<Node> goalNode)
{
	std::vector<Point> path;
	std::shared_ptr<Node> currentNode = goalNode;

	while (currentNode->cameFrom != nullptr)
	{
	path.push_back(currentNode->nodePoint);
	currentNode = currentNode->cameFrom;
	}//End while 

	return path;
} 

std::shared_ptr<Node> Pathfinder::createNode(Point point)
{
	auto node = std::make_shared<Node>(point);
	return node;
}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal, int tileSize)
{ // main function in Pathfinder.cpp contains a majority of the A* algorithm 

		
	auto startNode = createNode(start);
	auto goalNode = createNode(goal);

	startNode->cameFrom = nullptr;

	std::vector<std::shared_ptr<Node>> closedSet;
	std::vector<std::shared_ptr<Node>> openSet;
	openSet.push_back(startNode);

	startNode->g = 0;
	startNode->h = EuclideanDistance(startNode, goalNode);

	
	while (openSet.size() != 0)
	{
		// score will be node.g + node.h
		double score;
		// A number that is larger than the distance between the startNode and goalNode
		double lowestScore = maxDistance;

		
		for (std::shared_ptr<Node> node : openSet)
		{// Goes though all nodes in openSet to find the one with the lowest g + h value
			score = node->g + node->h;
			if (score < lowestScore)
			{
				lowestScore = score;
			}//end if
		}//End for loop

		 // i is used to record what position the required node is at in the openSet
		int i = 0;
		for (std::shared_ptr<Node> node : openSet)
		{
			if ((node->g + node->h) == score)
			{
				break;
			} //End if
			i++;
		} //End for loop

		std::shared_ptr<Node> currentNode = openSet[i];

		if (openSet[i]->h == 0)
		{
			return reconstructPath(goalNode);

		}//End  if

		 // move node from openSet to closedSet
		closedSet.push_back(openSet[i]);
		openSet.erase(openSet.begin() + i);

		std::vector<std::shared_ptr<Node>> neighbourNodes;

		//// TODO : GET NEIGHBOUR NODES /////

		

		//double gtentative;
		/*
		for (std::shared_ptr<Node> neighbourNode : neighbourNodes)
		{
		//TODO: check if node not a wall
		for (std::shared_ptr<Node> i : closedSet)
		{
		if (i->getX() != currentNode->getX() && i->getY() != currentNode->getY()) //TODO make function that will compare two node's X & Y values
		{
		gtentative = currentNode->g + EuclideanDistance(currentNode, neighbourNode);

		for (std::shared_ptr<Node> openNode : openSet)
		{
		if ((neighbourNode->getX() != openNode->getX() && neighbourNode->getY() != openNode->getY()) || gtentative < neighbourNode->g)
		{
		neighbourNode->g = gtentative;
		neighbourNode->h = EuclideanDistance(neighbourNode, goalNode);
		//neighbourNode->cameFrom = currentNode;
		//TODO: check if node is in openSet before adding
		openSet.push_back(neighbourNode);
		} // End if

		}// End of for open nodes
		}// End of if
		}// For i in closedSet


		}// End for node

		*/
	}//End while 
	

	std::vector<Point> result;
	return result;

}