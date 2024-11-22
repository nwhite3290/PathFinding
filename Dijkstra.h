/**
 * @file Dijkstra.h
 * @author Nathan White (white432@csusm.edu)
 * @brief Find Shortest Path
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

#include <iostream>
#include "Stack.h"
#include "Node.h"
#include "Graph.h"

using namespace std;

class Dijkstra
{
private:
	Graph* graph;
	LinkedList<Node>* open;
	Stack<Node>* path;
	float dist;

public:
	Dijkstra(Graph* graph)
	{
		this->graph = graph;
		open = new LinkedList<Node>();
	}

	float getDistance()
	{
		return dist;
	}

	Stack<Node>* ReconstructPlan(Node* goal)
	{
		Stack<Node>* path = new Stack<Node>(graph->GetNumberVertices());
		Node* current = goal;
		while(current->parent != 0)
		{
			path->Push(current);
			current = current->parent;
		}
		path->Push(current);
		return path;
	}

	Node* FindLowestNode(LinkedList<Node>* lst)
	{
		int lowest = 100000;
		Node* lowestNode = 0;
		Node* current = lst->first;
		while(current != 0)
		{
			if (current->g < lowest)
			{
				lowest = current->g;
				lowestNode = current;
			}
			current = current->next;
		}
		return lowestNode;
	}

	Stack<Node>* GetPath(Location* start, Location* goal)
	{
	
		Node* startNode = new Node(start);
		Node* goalNode = new Node(goal);
		open->Insert(startNode);
		while(open->IsEmpty() == false)
		{
			Node* current = FindLowestNode(open);
			open->Delete(current);
			LinkedList<Location>* adjacentVertices = graph->GetAdjacentVerticesLL(current->location);
			while(adjacentVertices->IsEmpty() == false)
			{
				Location* adj = graph->GetLowestWeight(adjacentVertices, current->location);
				Node* adjNode = new Node(adj);
				float distance = current->g + graph->DistanceBetweenVertices(current->location, adj);
				if (adjNode->g == 0 || distance < adjNode->g)
				{
					adjNode->g = distance;
					dist = distance;
					adjNode->parent = current;
				}
				if (adjNode->location == goal)
				{
					return ReconstructPlan(adjNode);
				}
				open->Insert(adjNode);
				adjacentVertices->Delete(adj);
			}
		}
		return 0;
	}
};

