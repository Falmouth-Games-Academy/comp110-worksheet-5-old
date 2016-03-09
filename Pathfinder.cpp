#include "stdafx.h"
#include "Pathfinder.h"
#include "Node.h"
#include "Point.h"

double EuclideanDistance(Node currentNode, Node nextNode) //Change names
{ //Calculates the euclidean distance between two nodes

	//Squares the difference between the values of each node's X and Y values
	double processX = pow((nextNode.getX() - currentNode.getX()), 2);
	double processY = pow(nextNode.getY() - currentNode.getY(),2);
	
	double distance = sqrt(processX + processY);
	return distance;
}

std::vector<Point> Pathfinder::reconstructPath(Node goalNode)
{
	std::vector<Point> path;
	Node currentNode = goalNode;
	Point currentPoint(goalNode.getX(), goalNode.getY());
	

	while (true)
	{
		path.push_back(currentPoint);
		//currentNode = currentNode.cameFrom ??
	}//End while 

	return path;
}

std::vector<Point> Pathfinder::findPath(const Map& map, const Point& start, const Point& goal, int tileSize)
{ // main function in Pathfinder.cpp contains a majority of the A* algorithm 

	Node startNode(start);
	Node goalNode(goal);

	//options for Node.cameFrom
	std::vector<std::string> neighbourDirections{ "up", "down", "left", "right" };  
	// startNode has no cameFrom direction
	startNode.cameFrom = "none";
		
	std::vector<Node> closedSet;
	std::vector<Node> openSet;
	openSet.push_back(startNode);

	startNode.g = 0;
	startNode.h = EuclideanDistance(startNode, goalNode);
	

	while (openSet.size() != 0)
	{
		// score will be node.g + node.h
		double score; 
		// A number that is larger than the distance between the startNode and goalNode
		double lowestScore = maxDistance; 
		

		for (Node node : openSet)
		{// Goes though all nodes in openSet to find the one with the lowest g + h value
			score = node.g + node.h;
			if (score < lowestScore)
			{
				lowestScore = score;
			}//end if
		}//End for loop

		// i is used to record what position the required node is at in the openSet
		int i = 0; 
		for (Node node : openSet)
		{
			if ((node.g + node.h) == score)
			{
				break;
			} //End if
			i++;
		} //End for loop
		
		Node currentNode = openSet[i];

		if (openSet[i].h == 0)
		{
				return reconstructPath(goalNode);
			
		}//End  if

		// move node from openSet to closedSet
		closedSet.push_back(openSet[i]);
		openSet.erase(openSet.begin() + i);

		// neighbourX and neighbourY are used to calculate the X and Y coordinates of the neighbourNodes
		int neighbourX;
		int neighbourY;
		// neighbourNodes is used to store the neighbourNode
		std::vector<Node> neighbourNodes;

		for (std::string direction : neighbourDirections)
		{ // Creates four neighbour nodes around the currentNode
			if (direction == "up")
			{
				neighbourX = currentNode.getX() + tileSize;
				neighbourY = currentNode.getY();
			} // End "up" if
			else if (direction == "down")
			{
				neighbourX = currentNode.getX() - tileSize;
				neighbourY = currentNode.getY();
			} // End "down" if
			else if (direction == "right")
			{
				neighbourX = currentNode.getX();
				neighbourY = currentNode.getY() + tileSize;
			} // End "right" if
			else if (direction == "left")
			{
				neighbourX = currentNode.getX();
				neighbourY = currentNode.getY() - tileSize;
			} // End "left" if
			
			Point neighbourPoint(neighbourX, neighbourY);
			Node neighbourNode(neighbourPoint);
			neighbourNode.cameFrom = direction;

			neighbourNodes.push_back(neighbourNode);
		}// End for directions 

		int gtentative;

		for (Node neighbourNode : neighbourNodes)
		{
			//TODO: check if node not a wall
			for (Node i : closedSet)
			{
				if (i.getX() != currentNode.getX() && i.getY() != currentNode.getY()) //TODO make function that will compare two node's X & Y values
				{
					gtentative = currentNode.g + EuclideanDistance(currentNode, neighbourNode);

					for (Node openNode : openSet)
					{
						if ((neighbourNode.getX() != openNode.getX() && neighbourNode.getY() != openNode.getY()) || gtentative < neighbourNode.g)
						{
							neighbourNode.g = gtentative;
							neighbourNode.h = EuclideanDistance(neighbourNode, goalNode);
							//neighbourNode.cameFrom = currentNode;
							//TODO: check if node is in openSet before adding
							openSet.push_back(neighbourNode);
						} // End if

					}// End of for open nodes 
				}// End of if 
			}// For i in closedSet


		}// End for node


	}//End while 


		std::vector<Point> result;
		return result;
	
}




