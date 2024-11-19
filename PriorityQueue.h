/**
 * @file PriorityQueue.h
 * @author Nathan White (white432@csusm.edu)
 * @brief Priority Queue for Path Finding
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

#pragma once
#include <iostream>
using namespace std;

template <class T>
class PriorityQueue
{
	int size;
	T** data;
	int count;

public:
	PriorityQueue(int size);
	~PriorityQueue();
	void Insert(T *item);
	T* Remove();
	T* PeakMin();
	bool IsEmpty();
	bool IsFull();
	int Size();
};

template <class T>
PriorityQueue<T>::PriorityQueue(int size) : size(size)
{
	data = new T *[size];
	count = 0;
	//return size;
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {}

template <class T>
void PriorityQueue<T>::Insert(T *item)
{
	if (count == 0)
	{
		data[count++] = item;
	}
	else
	{
		int j;
		for (j = (count - 1); j >= 0; j--)
		{
			if (*item > *data[j])
			{
				data[j + 1] = data[j];
			}
			else
			{
				break;
			}
		}
		data[j + 1] = item;
		count++;
	}
}

template <class T>
T* PriorityQueue<T>::Remove()
{
	return data[--count];
}

template <class T>
T* PriorityQueue<T>::PeakMin()
{
	return data[count - 1];
}

template <class T>
bool PriorityQueue<T>::IsEmpty()
{
	return count == 0;
}

template <class T>
bool PriorityQueue<T>::IsFull()
{
	return count == size;
}

template <class T>
int PriorityQueue<T>::Size()
{
	return size;
}
