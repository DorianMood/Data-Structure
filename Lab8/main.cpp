#include <iostream>
#include <stack>

#include "binaryTreeNode.h"

template <class T>
void visit(binaryTreeNode<T>* node)
{
    std::cout << node->element << " ";
}

template <class T>
void inOrder(binaryTreeNode<T>* node)
{
    std::stack<binaryTreeNode<T>*> s;
    
    binaryTreeNode<T>* current = node;

    while (current != NULL || s.empty() == false)
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->leftChild;
        }
        
        current = s.top();
        s.pop();

        visit(current);

        current = current->rightChild;
    }

    std::cout << std::endl;
}

template <class T>
void preOrder(binaryTreeNode<T>* root)
{
    std::stack<binaryTreeNode<T>*> s;
    s.push(root);

    while (!s.empty())
    {
        binaryTreeNode<T>* node = s.top();
        s.pop();

        visit(node);

        if (node->rightChild)
            s.push(node->rightChild);
        if (node->leftChild)
            s.push(node->leftChild);
    }

    std::cout << std::endl;
}

int main()
{
    // Write a non-recursive algorithm for preorder traversal

    // Create tree:
    //      c(3)
    //    /   \
    //  a(1)  b(2)
    
    binaryTreeNode<int>* a = new binaryTreeNode<int>(1);
    binaryTreeNode<int>* b = new binaryTreeNode<int>(2);
    binaryTreeNode<int>* c = new binaryTreeNode<int>(3, a, b);

    inOrder(c);

    preOrder(c);

    return 0;
}
