#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "Point.h"

double euclideanDistance(std::shared_ptr<Node> currentNode, std::shared_ptr<Node> nextNode)
{ //Calculates the euclidean distance between two nodes

  //Squares the difference between the values of each node's X and Y values
	double processX = pow(nextNode->getX() - currentNode->getX(), 2);
	double processY = pow(nextNode->getY() - currentNode->getY(), 2);

	double distance = sqrt(processX + processY);
	return distance;
}

std::shared_ptr<Node> Pathfinder::createNode(int x, int y)
{
	auto node = std::make_shared<Node>(x, y);
	return node;
}


std::vector<std::shared_ptr<Node>> Pathfinder::getNeighbourNodes(std::shared_ptr<Node> currentNode)
{// Creates a vecotr of four nodes surrounding the current node
	std::vector<std::shared_ptr<Node>> neighbourNodes;
	neighbourNodes.push_back(std::make_shared<Node>(currentNode->getX(), currentNode->getY()+1));  //up node
	neighbourNodes.push_back(std::make_shared<Node>(currentNode->getX(), currentNode->getY()-1));  //down node
	neighbourNodes.push_back(std::make_shared<Node>(currentNode->getX()-1, currentNode->getY()));  //left node
	neighbourNodes.push_back(std::make_shared<Node>(currentNode->getX()+1, currentNode->getY()));  //right node
	return neighbourNodes;
}

bool Pathfinder::checkForNodeInVector(std::shared_ptr<Node> node, std::vector<std::shared_ptr<Node>> nodeSet)
{//Checks a vector to see if the given node is in it
	for (std::shared_ptr<Node> i : nodeSet)
	{
		if (i->getX() == node->getX() && i->getY() == node->getY())
		return true;
	}//end for i
	return false;
}

std::vector<Point> Pathfinder::reconstructPath(std::shared_ptr<Node> goalNode)
{
	std::vector<Point> path;
	
	for (auto currentNode = goalNode; currentNode; currentNode = currentNode->cameFrom)
	{
		int testv = currentNode->nodePoint.getX();  //TEST LINE
		int test2 = currentNode->getX(); //TEST LINE
		path.insert(path.begin(), currentNode->nodePoint);
	}

	return path;
} 

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal, int tileSize)
{ // main function in Pathfinder.cpp contains a majority of the A* algorithm 

	auto startNode = createNode(start.getX(), start.getY());
	auto goalNode = createNode(goal.getX(), goal.getY()); 
	
	startNode->g = 0;
	startNode->h = euclideanDistance(startNode, goalNode);
	startNode->cameFrom = nullptr;

	std::vector<std::shared_ptr<Node>> closedSet;
	std::vector<std::shared_ptr<Node>> openSet;
	openSet.push_back(startNode);
		
	while (openSet.size() != 0)
	{
		
		double score; // score will be node.g + node.h
		double lowestScore = maxDistance; // A number that is larger than the distance between the startNode and goalNode 

		
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
		{// Finds the position of the node with the lowest score in the openSet
			if ((node->g + node->h) == score)
			{
				break;
			} //End if
			i++;
		} //End for loop

		auto currentNode = openSet[i];

		if (openSet[i]->h == 0)
		{
			return reconstructPath(goalNode);

		}//End  if

		 // move node from openSet to closedSet
		closedSet.push_back(openSet[i]);
		openSet.erase(openSet.begin() + i);

		auto neighbourNodes = getNeighbourNodes(currentNode);  //Creates a list of neighbour nodes 
		
		double gtentative;
		bool inClosedSet;
		bool inOpenSet;

		for (std::shared_ptr<Node> node : neighbourNodes)
		{
			inClosedSet = checkForNodeInVector(node, closedSet);
			bool nodeIsWall = map.isWall(node->nodePoint.getX(), node->nodePoint.getY());
			if (inClosedSet == false && nodeIsWall == false)
			{
				gtentative = currentNode->g + euclideanDistance(currentNode, node);
				inOpenSet = checkForNodeInVector(node, openSet);

				if (inOpenSet == false || gtentative < node->g)
				{
					node->g = gtentative;
					node->h = euclideanDistance(node, goalNode);
					node->cameFrom = currentNode;
					openSet.push_back(node);
				}//End if

			}//End if
		

		}// End of for node in neighbourNodes

		
	}//End while 
	

	std::vector<Point> result;
	return result;

}