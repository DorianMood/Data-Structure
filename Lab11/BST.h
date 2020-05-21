#include "binaryTree.h"

template<class E, class K>
class BSTree : public binaryTree<E> {
public:
	bool Search(const K& k, E& e) const;
	BSTree<E, K>& Insert(const E& e);
	BSTree<E, K>& InsertVisit(const E& e, void(*visit)(E& u));
	BSTree<E, K>& Delete(const K& k, E& e);
	void Ascend() { InOutput(); }
};
