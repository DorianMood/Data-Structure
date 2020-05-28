// chain node

#ifndef chainNode_
#define chainNode_

template <class T>
struct chainNode
{
	// data members
	T element;
	chainNode<T>* next = nullptr;

	// methods
	chainNode()
	{
		this->next = nullptr;
	}
	chainNode(const T& element)
	{
		this->element = element;
		this->next = nullptr;
	}
	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};

#endif
