#ifndef MAX_PRIORITY_QUEUE_
#define MAX_PRIORITY_QUEUE_

#include <iostream>
#include <stdexcept>

#include "MaxPriorityQueue.h"
#include "ArrayList.h"

template <class T>
class MaxPriorityQueueList : public maxPriorityQueue<T>
{
public:
	MaxPriorityQueueList();
	~MaxPriorityQueueList();

	bool empty() const { return count == 0; }
	int size() const { return count; }

	const T& top();
	void pop();
	void push(const T& element);

	void output(ostream& out) const;

private:
	int count = 0;
	ArrayList<T>* list;

};

template <class T>
MaxPriorityQueueList<T>::MaxPriorityQueueList()
{
	list = new ArrayList<T>();
	count = 0;
}

template <class T>
MaxPriorityQueueList<T>::~MaxPriorityQueueList()
{
	count = 0;
	delete list;
}

template <class T>
const T& MaxPriorityQueueList<T>::top()
{
	if (count == 0)
		throw queueEmpty();
	T element = list->get(0);
	return element;
}

template <class T>
void MaxPriorityQueueList<T>::pop()
{
	list->erase(0);
	count--;
}

template <class T>
void MaxPriorityQueueList<T>::push(const T& element)
{
	list->insert(count, element);
	count++;
}

template <class T>
void MaxPriorityQueueList<T>::output(ostream& out) const
{
	out << "Queue size : " << list->size() << std::endl;
	list->output(out);
}
#endif // !MAX_PRIORITY_QUEUE_
