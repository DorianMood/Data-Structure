#ifndef _NODE_H_
#define _NODE_H_

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node() {}
    Node(T data) { this->data = data; };
    ~Node() { }
};

#endif
