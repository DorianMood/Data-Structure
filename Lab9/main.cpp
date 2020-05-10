#include <iostream>

#include "MaxHeap.h"
#include "MaxHBLT.h"

#define MAX_HEAP_SIZE 32

int main()
{
	/**
	1. Develop a C++ class for the ADT MaxPriorityQueue using an unordered formula-based linear list
	(i.e, use the class LinearList of Program 3.1). The insert time should be жи(1),
	and the delete max time should be O(n) where n is the number of elements in the queue.

	2. Do Exercise 1 using an unordered chain (i.e, use the class Chain of Program 3.8).
	**/

	int* arr = new int[MAX_HEAP_SIZE];
	for (int i = 0; i < MAX_HEAP_SIZE; i++)
	{
		arr[i] = i % 16;
	}

	// MaxHeap

	MaxHeap<int>* heap = new MaxHeap<int>(MAX_HEAP_SIZE);

	heap->Initialize(arr, MAX_HEAP_SIZE, MAX_HEAP_SIZE);

	heap->Output();

	// MaxHBLT

	MaxHBLT<int>* tree = new MaxHBLT<int>();

	tree->Initialize(arr, MAX_HEAP_SIZE);

	tree->Output();

	/**
	1. Develop a C++ class for the ADT MaxPriorityQueue
	using an unordered formula-based linear list (i.e, use the class LinearList of Program 3.1).
	The insert time should be жи(1), and the delete max time should be O(n) where n is the number of elements in the queue.

	2. Do Exercise 1 using an unordered chain (i.e, use the class Chain of Program 3.8).
	*/

	return 0;
}
