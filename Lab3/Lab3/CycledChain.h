#ifndef _CHAIN_H_
#define _CHAIN_H_

#include <stdexcept>
#include <iostream>
#include <ostream>

template <typename T>
struct Node
{
    T data;
    struct Node* next;
    struct Node* prev; // TODO : Add this pointer to the collection
};

template <typename T>
class CycledChain
{
private:
    Node<T>* head;
    Node<T>* tail; // TODO : Add this to the structure.
    int size;

public:
    CycledChain();
    ~CycledChain();

    bool IsEmpty() { return size == 0; }
    int Size() { return size; }
    bool Find(int index, T& item) const;
    int Search(const T& item) const;
    CycledChain<T>& Delete(int at, T& item);
    CycledChain<T>& Insert(int after, const T& item);
    void Output(std::ostream &out) const;
};

template<typename T>
CycledChain<T>::CycledChain()
{
    head = new Node<T>();
    head->next = nullptr;

    tail = new Node<T>();
    tail->prev = nullptr;

    size = 0;
}

template <typename T>
CycledChain<T>::~CycledChain()
{
    Node<T>* next;
    for (int i = 0; i < size; i++)
    {
        next = head->next;
        delete head;
        head = next;
    }
}

template <typename T>
bool CycledChain<T>::Find(int index, T& item) const
{
    if (index < 0 || size < 1 || index >= size)
        return false;
    
    Node<T>* current = head->next;
    for (int i = 0; i < size && i <= index; i++, current = current->next)
    {
        item = current->data;
    }
    return true;
}

template <typename T>
int CycledChain<T>::Search(const T& item) const
{
    Node<T>* current = head->next;

    Node<T>* first = head;
    for (int i = 0; i < size; i++)
    {
        first = first->next;
        if (first->data == item)
            return i;
    }

    return -1;
}

template <typename T>
CycledChain<T>& CycledChain<T>::Delete(int at, T& item)
{
    if (at < 0 || at >= size)
        throw std::out_of_range("Out of range");

    // TODO : implement


    return *this;
}

template <typename T>
CycledChain<T>& CycledChain<T>::Insert(int at, const T& data)
{
    if (at < 0 || at > size)
        throw std::out_of_range("Out of range");
    
    Node<T>* node = new Node<T>();
    node->data = data;

    Node<T>* insertAfter = head;
    for (int i = 0; i < at; i++)
        insertAfter = insertAfter->next;

    
    // insertAfter -> node -> tmp
    Node<T>* tmp = insertAfter->next;
    insertAfter->next = node;
    node->next = tmp;

    // insertAfter <- node <- tmp
    if (tmp)
        tmp->prev = node;
    if (insertAfter != head)
        node->prev = insertAfter;

    // TODO : do we need tail node at all?

    size++;

    return *this;
}

template <class T>
void CycledChain<T>::Output(std::ostream &out) const
{
    Node<T>* node = head->next;
    while (node)
    {
        out << node->data << " ";
        node = node->next;
    }
    out << std::endl;
}

#endif
