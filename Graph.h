/**
 * @file Graph.h
 * @author Nathan White (white432@csusm.edu)
 * @brief Implement a Graph for Pathfinding
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

#pragma once
#include "Location.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
using namespace std;

class Graph
{
private:
	int** adjMat;
	static const int INF = 999999;
	int numberVertices;
	int size;
public:
	Location** vertices;

	Graph(int size)
	{
		this->size = size;
		numberVertices = 0;
		// create new vertex location
		vertices = new Location* [size];
		// initialize adjacency matrix 
		adjMat = new int*[size];
		for(int i = 0; i < size; i++)
		{
			adjMat[i] = new int[size];
		}
		// initialize adjacency matrix rows and cols to infinity
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				adjMat[i][j] = INF;
			}
		}
	}

	int GetNumberVertices()
	{
		return numberVertices;

	}

	Location* GetLowestWeight(LinkedList<Location>* adjacentVertices, Location* vertex)
	{
		int lowest = adjacentVertices->first->key;
		float lowestWeight = adjMat[vertex->key][lowest];
		Location* current = adjacentVertices->first->next;
		while(current != NULL)
		{
			if (adjMat[vertex->key][current->key] < lowestWeight)
			{
				lowest = current->key;
				lowestWeight = adjMat[vertex->key][current->key];
			}
			current = current->next;
		}
		return vertices[lowest];
	}

	LinkedList<Location>* GetAdjacentVerticesLL(Location* vertex)
	{
		LinkedList<Location>* adjacent = new LinkedList<Location>();
		for (int j = 0; j < numberVertices; j++)
		{
			if (adjMat[vertex->key][j] != INF)
			{
				adjacent->Insert(vertices[j]);
			}
		}
		return adjacent;
	}

	PriorityQueue<Location>* GetAdjacentVertices(Location* vertex)
	{
		PriorityQueue<Location>* adjacent = new PriorityQueue<Location>(numberVertices);
		for (int j = 0; j < numberVertices; j++)
		{
			if (adjMat[vertex->key][j] != INF)
			{
				adjacent->Insert(vertices[j]);
			}
		}
		return adjacent;
	}

	int DistanceBetweenVertices(Location* first, Location* second)
	{
		return adjMat[first->key][second->key];
	}

	void Display()
	{
		cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << vertices[i]->name << "\t";
			for (int j = 0; j < size; j++)
			{
				cout << adjMat[i][j] << "\t";
			}
			cout << endl;
		}
	}

	void addVertex(Location* vertex)
	{
		vertices[numberVertices] = vertex;
		numberVertices++;
	}

	void AddEdge(int start, int end, int weight)
	{
		adjMat[start][end] = weight;
	}

	

	

	

	
};



/*
 * 				(A)           
 *         /   / \   \       
 *        v   v   v    v     
 *       (E) (D)  (C) (B)    
 *            |        |     
 *            v        v     
 *           (G)      (F)    
 *            |        |     
 *            v        v     
 *           (I)      (H)    
 */