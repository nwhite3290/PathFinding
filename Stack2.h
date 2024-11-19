/**
 * @file Stack2.h
 * @author Nathan White (white432@csusm.edu)
 * @brief Stack2 template header file
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

#ifndef STACK2_H
#define STACK2_H

#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack2
{
private:
	int maxSize;
	T** stackData;
	int top;
public:
	Stack2<T>(int maxSize)
	{
		this->maxSize = maxSize;
		stackData = new T* [maxSize];
		top = -1;
	}

	bool IsEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		if (top == (maxSize - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T* Peek()
	{
		return stackData[top];
	}

	T* Pop()
	{
		T* valToReturn = stackData[top];
		//stackData[top] = 0; // if want to delete
		top--;
		return valToReturn;
	}

	void Push(T* value)
	{
		top++;
		stackData[top] = value;
	}

/*
	int Count()
	{
		return maxSize;
	}
*/

};


#endif

