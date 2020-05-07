#ifndef SWAP_
#define SWAP_

#include "HBLTNode.h"

template <class T>
void Swap(HBLTNode<T>* left, HBLTNode<T>* right)
{
	HBLTNode<T>* tmp = left;
	left = right;
	right = tmp;
}

#endif // !SWAP_
