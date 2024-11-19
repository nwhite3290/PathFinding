/**
 * @file LinkedList.h
 * @author Nathan White (white432@csusm.edu)
 * @brief Linked List Template
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
//#include "Link.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
public:
	T* first;
	LinkedList()
	{
		first = 0;
	}

	void Display()
	{
		T* current = first;
		while(current != 0)
		{
			current->Display();
			current = current->next;
		}
	}

	T* Find(T* key)
	{
		T* current = first;
		while(current != 0)
		{
			if(*current == *key)
			{
				return current;
			}
			else
			{
				current = current->next;
			}
		}
		return 0;
	}

	void Insert(T* newLink)
	{
		newLink->next = first;
		first = newLink;
	}

	bool IsEmpty()
	{
		return (first == 0);
	}

	T* Delete(T* key)
	{
		T* current = first;
		T* previous = first;
		while(*current != *key)
		{
			if(current->next == 0)
			{
				return 0;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
		if (current == first)
		{
			first = first->next;
		}
		else
		{
			previous->next = current->next;
		}
		return current;
	}

	
};

#endif