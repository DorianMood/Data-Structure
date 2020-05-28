#include <iostream>

#include "MaxPriorityQueueList.h"
#include "MaxPriorityQueueChain.h"

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
	queue->output(std::cout);
	queue->push(3);
	queue->output(std::cout);
	queue->push(2);
	queue->output(std::cout);
	queue->push(0);

	int top_value;
	top_value = queue->top();
	std::cout << "Top node : " << top_value << std::endl;
	queue->pop();
	top_value = queue->top();
	std::cout << "Top node : " << top_value << std::endl;

	delete queue;

	// 2. Unordered cahin approach

	MaxPriorityQueueChain<int>* chainQueue = new MaxPriorityQueueChain<int>();

	chainQueue->push(1);
	chainQueue->push(3);
	chainQueue->push(2);
	chainQueue->push(0);

	top_value = chainQueue->top();
	std::cout << "Top node : " << top_value << std::endl;
	chainQueue->pop();
	top_value = chainQueue->top();
	std::cout << "Top node : " << top_value << std::endl;

	delete chainQueue;

	return 0;
}
