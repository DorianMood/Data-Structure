#ifndef MAX_PRIORITY_QUEUE_
#define MAX_PRIORITY_QUEUE_

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "myExceptions.h"
#include "MaxPriorityQueue.h"
#include "ArrayList.h"

template <class T>
class MaxPriorityQueueList : public maxPriorityQueue<T>, public ArrayList<T>
{
public:
	bool empty() const { return this->listSize == 0; }
	int size() const { return this->listSize; }

	const T& top();
	void pop();
	void push(const T& element);

	void output(ostream& out) const;

};

template <class T>
const T& MaxPriorityQueueList<T>::top()
{
	if (this->listSize == 0)
		throw queueEmpty();

	// Find max
	T maxElement = this->element[0];
	for (int i = 1; i < this->listSize; i++)
	{
		if (maxElement < this->element[i])
		{
			maxElement = this->element[i];
		}
	}
	return maxElement;
}

template <class T>
void MaxPriorityQueueList<T>::pop()
{
	// Find and delete max
	int index = 0;
	T maxElement = this->element[index];
	for (int i = 0; i < this->listSize; i++)
	{
		if (maxElement < this->element[i])
		{
			maxElement = this->element[i];
			index = i;
		}
	}
	this->erase(index);
}

template <class T>
void MaxPriorityQueueList<T>::push(const T& element)
{
	// Push elements on the right position
	this->insert(this->listSize, element);
}

template <class T>
void MaxPriorityQueueList<T>::output(ostream& out) const
{
	out << "Queue size : " << this->listSize << std::endl;
	for (int i = 0; i < this->listSize; i++)
	{
		out << this->element[i] << " ";
	}
	out << std::endl;
}
#endif // !MAX_PRIORITY_QUEUE_