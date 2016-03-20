# COMP110 Worksheet 5

I have used a two-dimensional vector (a vector of vectors of pointers to nodes) to store pointers to each of the nodes, so that it is easy to get the neighbour nodes based on their x and y coordinates.
I have used a priority queue for the open set, so that the node with the lowest g+h score can be accessed using top(), removing the need to loop through every node in the open set. 
I have simply used a boolean member in the nodes to indicate whether it is in the closed set or not, as the algorithm only ever needs to check if a node is in the closed set, or set it to being in the closed set.
