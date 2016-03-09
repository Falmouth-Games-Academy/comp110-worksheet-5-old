# COMP110 Worksheet 5

##Standard Template Library Structures:
There are a variety of data structures that can be used for this task: vectors, linked lists, sets, maps, queues, priority queues and stacks.

###Vectors (https://www.sgi.com/tech/stl/Vector.html)
A vector is a simple container that allows for random access of the elements within the container. This includes the addition and removal of elements at any point. This is useful for my A* pathfinding as I need to be able to remove nodes from the open list to the closed list and also identify if the current node is the target. As this is described as the simplest, as it automatically manages memory, I think I'll use vectors as a base for a data structure for the closedSet.

##Priority Queue
Priority queues allow for a top element in the queue to be at the top of the queue, which I can use to reduce the number of checks to find the next node I want to check. 
I'll use this for the openSet. This big O notationfor this use of priority queue gives a O(n) pull time.
