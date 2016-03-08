#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "Point.h"

double EuclideanDistance(Node currentNode, Node nextNode) //Change names
{ //Calculates the euclidean distance between two nodes

	double processX = pow((nextNode.getX() - currentNode.getX()), 2);
	double processY = pow(nextNode.getY() - currentNode.getY(),2);
	double distance = sqrt(processX + processY);
	return distance;
}

std::vector<Point> Pathfinder::reconstructPath(Node goalNode)
{
	std::vector<Point> path;
	Node currentNode = goalNode; //Not sure if right
	Point currentPoint(goalNode.getX(), goalNode.getY());
	

	while (true)
	{
		path.push_back(currentPoint);
		//currentNode = currentNode.cameFrom ??
	}//End while 

	return path;
}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal, int tileSize)
{

	Node startNode(start);
	Node goalNode(goal);

	std::vector<std::string> neighbourDirections{ "up", "down", "left", "right" };  //options for node.cameFrom
	startNode.cameFrom = "none";
		

	std::vector<Node> closedSet;
	std::vector<Node> openSet;
	openSet.push_back(startNode);

	startNode.g = 0;
	startNode.h = EuclideanDistance(startNode, goalNode);
	

	while (openSet.size() != 0)
	{
		double score;
		double lowestScore = maxDistance;
		int i = 0;

		for (Node node : openSet)
		{// Goes though all nodes in openset finds the one with the lowest g + h value
			score = node.g + node.h;
			if (score < lowestScore)
			{
				lowestScore = score;
			}//end if
		}//End for loop

		i = 0;
		for (Node node : openSet)
		{
			if ((node.g + node.h) == score)
			{
				break;
			}
			i++;
		}
		
		Node currentNode = openSet[i];

		if (openSet[i].h == 0)
		{
				return reconstructPath(goalNode);
			
		}//End  if

		closedSet.push_back(openSet[i]);
		openSet.erase(openSet.begin() + i);


		//TODO get neighbours & cameFrom working
		int neighbourX;
		int neighbourY;

		for (std::string direction : neighbourDirections)
		{
			if (direction == "up")
			{
				neighbourX = currentNode.getX() + tileSize;
				neighbourY = currentNode.getY();
			}
			else if (direction == "down")
			{
				neighbourX = currentNode.getX() - tileSize;
				neighbourY = currentNode.getY();
			}
			else if (direction == "right")
			{
				neighbourX = currentNode.getX();
				neighbourY = currentNode.getY() + tileSize;
			}
			else if (direction == "left")
			{
				neighbourX = currentNode.getX();
				neighbourY = currentNode.getY() - tileSize;
			}
			
			Point neighbourPoint(neighbourX, neighbourY);
			Node neighbourNode(neighbourPoint);

			openSet.push_back(neighbourNode); // add to different vector
		}

	}//End while 


		std::vector<Point> result;
		return result;
	
}




