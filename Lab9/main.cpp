#include <iostream>

#include "MaxPriorityQueueList.h"

int main()
{
	/**
	1. Develop a C++ class for the ADT MaxPriorityQueue
	using an unordered formula-based linear list (i.e, use the class LinearList of Program 3.1).
	The insert time should be жи(1), and the delete max time should be O(n)
	where n is the number of elements in the queue.

	2. Do Exercise 1 using an unordered chain (i.e, use the class Chain of Program 3.8).
	*/

	// 1. MaxPriorityQueue
	MaxPriorityQueueList<int>* queue = new MaxPriorityQueueList<int>();

	queue->push(1);
	queue->push(3);
	queue->push(2);
	queue->push(0);

	std::cout << queue->top() << std::endl;
	queue->pop();
	std::cout << queue->top() << std::endl;


	// 2. Unordered cahin approach



	return 0;
}
