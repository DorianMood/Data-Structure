#ifndef _LIST_H_
#define _LIST_H_

template <typename T>
class List
{
public:
	List();
	~List();

	bool IsEmpty() { return size == 0; }
	int Size() { return size; }
	bool Find(int index, T& item) const;
	int Search(const T& item) const;
	List<T>& Delete(int at, T& item);
	List<T>& Insert(int after, const T& item);
private:
	T* x;
	int size;
	int capacity;

	const int CAPACITY_GROW_RATE = 2;
	const int START_CAPACITY = 16;
};

template <typename T>
List<T>::List()
{
	capacity = START_CAPACITY;
	x = new int[START_CAPACITY];
	size = 0;
}

template <typename T>
List<T>::~List()
{
	delete[] x;
}

template <typename T>
bool List<T>::Find(int index, T& item) const
{
	if (index >= size)
		return false;

	item = x[index];

	return true;
}

template <typename T>
int List<T>::Search(const T& item) const
{
	for (int i = 0; i < size; i++)
		if (x[i] == item)
			return i;

	return -1;
}

template <typename T>
List<T>& List<T>::Delete(int at, T& item)
{
	for (int i = at; i < size - 1; i++)
	{
		x[i] = x[i + 1];
	}
	size--;
}

template <typename T>
List<T>& List<T>::Insert(int at, const T& item)
{
	if (size >= capacity)
	{
		capacity *= CAPACITY_GROW_RATE;
	}

	T* newX = new T[capacity];
	bool middle = false;
	for (int i = 0; i < size + 1; i++)
	{
		if (i == at)
		{
			newX[at] = item;
			middle = true;
		}
		else
		{
			newX[middle ? i + 1 : i] = x[i];
		}
	}
	x = newX;
	size++;

	return *this;
}

#endif