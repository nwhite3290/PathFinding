/**
 * @file Node.h
 * @author Nathan White (white432@csusm.edu)
 * @brief Node class for Path Finding
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

#ifndef NODE_H
#define NODE_H

#pragma once
#include <iostream>
#include "Graph.h"
using namespace std;

class Node
{
public:
	float g;
	Location* location;
	Node* next;
	Node* parent;

	Node(Location* location)
	{
		this->location = location;
		this->parent = 0;
		this->g = 0;
	}

	bool operator!=(const Node& rhd)
	{
		if (this->location != rhd.location)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const Node& rhd)
	{
		if (this->location == rhd.location)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

};


#endif