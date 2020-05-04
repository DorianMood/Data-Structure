#ifndef SORTED_LIST_
#define SORTED_LIST_

#include <iostream>

template <class T>
class SortedList
{
public:
    SortedList() { first = 0; }
    ~SortedList();

    int Length() const { return size == 0; };
    bool Search(const T& e) const;
    SortedList<T>& Delete(int i);
    SortedList<T>& Insert(const T& e);
    void Output(std::ostream& out) const;

private:
    int* x;
    int size;
    int capacity;

    const int INITIAL_CAPACITY = 16;

};

template <class T>
SortedList<T>::SortedList()
{
    capacity = INITIAL_CAPACITY;
    x = new int[capacity];
    size = 0;
}

template <class T>
SortedList<T>::~SortedList()
{
    delete[] x;
}

template <class T>
bool SortedList<T>::Search(const T& e) const
{
    // We can use binary search
    return false;
}

template <class T>
SortedList<T>& SortedList<T>::Delete(int i)
{
    // Delete from correct position
    return this;
}

template <class T>
SortedList<T>& SortedList<T>::Insert(const T& value)
{
    // Insert to the correct position
    return this;
}

template <class T>
void SortedList<T>::Output(std::ostream& out) const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
}

#endif // !SORTED_LIST_
