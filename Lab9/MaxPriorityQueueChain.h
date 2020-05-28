#ifndef MAX_PRIORITY_QUEUE_CHAIN
#define MAX_PRIORITY_QUEUE_CHAIN

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "MaxPriorityQueue.h"
#include "Chain.h"
#include "chainNode.h"

template <class T>
class MaxPriorityQueueChain : public maxPriorityQueue<T>, public chain<T>
{
public:
	MaxPriorityQueueChain();

	bool empty() const { return this->listSize == 0; }
	int size() const { return this->listSize; }

	const T& top();
	void pop();
	void push(const T& element);

	void output(ostream& out) const;

};

template <class T>
MaxPriorityQueueChain<T>::MaxPriorityQueueChain()
{
	this->firstNode = new chainNode<T>();
}

template <class T>
const T& MaxPriorityQueueChain<T>::top()
{
	if (this->listSize == 0)
		throw queueEmpty();

	// Find max
	chainNode<T>* node = this->firstNode->next;
	T maxElement = node->element;
	for (int i = 1; i < this->listSize; i++)
	{
		node = node->next;
		if (maxElement < node->element)
		{
			maxElement = node->element;
		}
	}
	return maxElement;
}

template <class T>
void MaxPriorityQueueChain<T>::pop()
{
	if (this->listSize == 0)
		throw queueEmpty();

	// Find and delete max
	chainNode<T>* node = this->firstNode->next;
	this->firstNode->next = node->next;
	this->listSize--;
}

template <class T>
void MaxPriorityQueueChain<T>::push(const T& element)
{
	// Push elements on the right position
	chainNode<T>* node = this->firstNode;
	while ((node->next != nullptr) && (node->next->element > element)) node = node->next;
	node->next = new chainNode<T>(element, node->next);
	this->listSize++;
}

template <class T>
void MaxPriorityQueueChain<T>::output(ostream& out) const
{
	out << "Queue size : " << this->listSize << std::endl;
	chainNode<T>* node = this->firstNode;
	while (node->next)
	{
		node = node->next;
		std::cout << node->element << " ";
	}
	out << std::endl;
}
#endif // !MAX_PRIORITY_QUEUE_CHAIN
