#pragma once
class Node
{
public:
	Node();
	~Node();

	double g = 0;
	double h = 0;


//getting x y values
	int getX() { return nodeX; }
	int getY() { return nodeY; }

	int setX(int newX) { return nodeX = newX; }
	int sety(int newY) { return nodeY = newY; }

//inistialising it
private:
	int nodeX, nodeY;
};

