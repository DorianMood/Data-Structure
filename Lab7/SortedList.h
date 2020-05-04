#ifndef SORTED_LIST_
#define SORTED_LIST_

#include <iostream>

#include "Dictionary.h"

template <class K, class E>
class SortedList : Dictionary<K, E>
{
public:
    SortedList();
    ~SortedList();

    bool Empty() const { return size == 0; }
    int Size() const { return size; };
    std::pair<const K, E>* Find(const K& e) const;
    void Erase(const K& key);
    void Insert(const std::pair<const K, E>&);
    void Output(std::ostream& out) const;

private:
    std::pair<const K, E>* x;
    int size;
    int capacity;

    const int INITIAL_CAPACITY = 16;

};

template <class K, class E>
SortedList<K, E>::SortedList()
{
    capacity = INITIAL_CAPACITY;
    x = new std::pair<const K, E>[capacity];
    size = 0;
}

template <class K, class E>
SortedList<K, E>::~SortedList()
{
    delete[] x;
}

template <class K, class E>
std::pair<const K, E>* SortedList<K, E>::Find(const K& e) const
{
    // We can use binary search
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (x[middle].second < e)
            left = middle + 1;
        else if (x[middle].second > e)
            right = middle - 1;
        else
            return &x[middle];
    }

    return nullptr;
}

template <class K, class E>
void SortedList<K, E>::Erase(const K& key)
{
    // Delete from correct position

    return;
}

template <class K, class E>
void SortedList<K, E>::Insert(const pair<const K, E>& item)
{
    // Insert to the correct position
    if ()
    {
        capacity *= 2;
        // Recreate array
        std::pair<K, E> newX = new std::pair<K, E>[capacity];
        // Copy all the data

    }

    

    return;
}

template <class K, class E>
void SortedList<K, E>::Output(std::ostream& out) const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << x[i].second << " ";
    }
    std::cout << std::endl;
}

#endif // !SORTED_LIST_
