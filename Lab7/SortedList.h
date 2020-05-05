#ifndef SORTED_LIST_
#define SORTED_LIST_

#include <iostream>
#include <map>
#include <algorithm>

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
    std::pair<K, E>* x;
    int size;
    int capacity;

    const int INITIAL_CAPACITY = 16;

};

template <class K, class E>
SortedList<K, E>::SortedList()
{
    capacity = INITIAL_CAPACITY;
    x = new std::pair<K, E>[capacity];
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
        else // TODO : fix this, return actual pair not copy.
            return &std::pair<const K, E>(x[middle].first, x[middle].second);
    }

    return nullptr;
}

template <class K, class E>
void SortedList<K, E>::Erase(const K& key)
{
    // Delete from correct position

    int actualIndex = 0;
    for (; actualIndex < size && x[actualIndex].first != key; actualIndex++);

    // No element found
    if (actualIndex == size)
        return;

    for (int i = actualIndex; i < size - 1; i++)
        x[i] = x[i + 1];

    size--;
}

template <class K, class E>
void SortedList<K, E>::Insert(const pair<const K, E>& item)
{
    // Make 2 bigger
    if (size == capacity)
    {
        capacity *= 2;
        std::pair<K, E>* newX = new std::pair<K, E>[capacity];
        for (int i = 0; i < size; i++)
            newX[i] = x[i];
        x = newX;
    }
    
    x[size] = item;
    size++;

    std::sort(x, x + size);
}

template <class K, class E>
void SortedList<K, E>::Output(std::ostream& out) const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << x[i].first << " " << x[i].second << "\t";
    }
    std::cout << std::endl;
}

#endif // !SORTED_LIST_
