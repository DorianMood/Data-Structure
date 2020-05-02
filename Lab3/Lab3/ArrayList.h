// array implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented
// USES STL ALGORITHMS TO SIMPLIFY CODE

#ifndef arrayList_
#define arrayList_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include "LinearList.h"

using namespace std;

template <class T>
class ArrayList : public linearList<T>
{
public:
    // constructor, copy constructor and destructor
    ArrayList(int initialCapacity = 10);
    ArrayList(const ArrayList<T>&);
    ~ArrayList() { delete[] element; }

    // ADT methods
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    // additional method
    int capacity() const { return arrayLength; }

protected:
    void checkIndex(int theIndex) const;
    // throw illegalIndex if theIndex invalid
    T* element;      // 1D array to hold list elements
    int arrayLength; // capacity of the 1D array
    int listSize;    // number of elements in list
};

template <class T>
ArrayList<T>::ArrayList(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw out_of_range(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& theList)
{ // Copy constructor.
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}

template <class T>
void ArrayList<T>::checkIndex(int theIndex) const
{ // Verify that theIndex is between 0 and listSize - 1.
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw out_of_range(s.str());
    }
}

template <class T>
T& ArrayList<T>::get(int theIndex) const
{  // Return element whose index is theIndex.
   // Throw illegalIndex exception if no such element.
    checkIndex(theIndex);
    return element[theIndex];
}

template <class T>
int ArrayList<T>::indexOf(const T& theElement) const
{  // Return index of first occurrence of theElement.
   // Return -1 if theElement not in list.

   // search for theElement
    int theIndex = (int)(find(element, element + listSize, theElement) - element);

    // check if theElement was found
    if (theIndex == listSize)
        // not found
        return -1;
    else
        return theIndex;
}

template <class T>
void ArrayList<T>::erase(int theIndex)
{  // Delete the element whose index is theIndex.
   // Throw illegalIndex exception if no such element.
    checkIndex(theIndex);

    // valid index, shift elements with higher index
    copy(element + theIndex + 1, element + listSize,
        element + theIndex);

    element[--listSize].~T(); // invoke destructor
}

template <class T>
void ArrayList<T>::insert(int theIndex, const T& theElement)
{ // Insert theElement so that its index is theIndex.
    if (theIndex < 0 || theIndex > listSize)
    { // invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw out_of_range(s.str());
    }

    // valid index, make sure we have space
    if (listSize == arrayLength)
    { // no space, double capacity
        T* newArray = new T[arrayLength * 2];
        for (int i = 0; i < arrayLength; i++)
        {
            newArray[i] = element[i];
        }
        //changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
        element = newArray;
    }

    // shift elements right one position
    copy_backward(element + theIndex, element + listSize,
        element + listSize + 1);

    element[theIndex] = theElement;

    listSize++;
}

template <class T>
void ArrayList<T>::output(ostream& out) const
{ // Put the list into the stream out.
    copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const ArrayList<T>& x)
{
    x.output(out);
    return out;
}

#endif
