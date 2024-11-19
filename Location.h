/**
 * @file Location.h
 * @author Nathan White (white432@csusm.edu)
 * @brief Location of Vertices in a Graph
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

#pragma once
#include <iostream>
using namespace std;

class Location
{
public:
	int key;
	char name;
	Location *next;
	bool wasVisited;
	float x;
	float y;

	void Display()
	{
		cout << name << endl;
	}

	Location(int key, char name)
	{
		this->key = key;
		this->name = name;
		x = 0;
		y = 0;
	}

	Location(int key, char name, float x, float y)
	{
		this->key = key;
		this->name = name;
		this->x = x;
		this->y = y;
	}

	bool operator!=(const Location &rhd)
	{
		if (this->key != rhd.key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(const Location &rhd)
	{
		if (this->key < rhd.key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const Location &rhd)
	{
		if (this->key == rhd.key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator>(const Location &rhd)
	{
		if (this->key > rhd.key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};