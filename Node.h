#pragma once
class Node
{
public:
	Node();
	~Node();

	int getX() { return nodeX; }
	int getY() { return nodeY; }

private:
	int nodeX, nodeY;
};

