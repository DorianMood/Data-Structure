#include <iostream>

#include "MaxHeap.h"

#define MAX_HEAP_SIZE 32

int main()
{
	/**
	1. Develop a C++ class for the ADT MaxPriorityQueue using an unordered formula-based linear list
	(i.e, use the class LinearList of Program 3.1). The insert time should be жи(1),
	and the delete max time should be O(n) where n is the number of elements in the queue.

	2. Do Exercise 1 using an unordered chain (i.e, use the class Chain of Program 3.8).
	*/

	// MaxHeap

	MaxHeap<int>* heap = new MaxHeap<int>(MAX_HEAP_SIZE);

	for (int i = 0; i < MAX_HEAP_SIZE; i++)
	{
		heap->Insert(i % 16);
	}
	heap->Output();
}
