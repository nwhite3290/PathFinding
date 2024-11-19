/*
 * compile with makefile
 * $ make
 * run
 * $ ./path
 * 
 */


/**
 * @file main.cpp
 * @author Nathan White (white432@csusm.edu)
 * @brief Tests PathFinding
 * @version 0.1
 * @date 18/11/2024
 * @copyright Copyright (c) 2024
 */

/*
 * test graph: see graph.dot and graph.pdf
 *-----------
 * 		  (B)---4--->(D)        
 *        ^ ^ \        ^ \       
 *       /  |  \       |  2      
 *      4   |   \      |   \     
 *     /    |    \     |    v    
 *  (A)     1     2    3    (F)  
 *     \    |      \   |    ^    
 *      4   |       \  |   /     
 *       \  |        \ |  2      
 *        v v         v| /       
 *         (C)---3--->(E)        
 */

/*
 * city.cpp reads roads.txt and cities.txt
 * need to incorportate them into the PathFinding project
 * and change the program to either use the "int ID", or the "string City_Code"
 * also need to print out the distances from Dijkstra.h
 * finally need to add notes and clean it up.
 */

#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "Stack2.h"
using namespace std;

int main()
{
	Graph *g = new Graph(6);
	Location* startVert = new Location(0, 'A');

	g->addVertex(startVert);
	g->addVertex(new Location(1, 'B'));
	g->addVertex(new Location(2, 'C'));
	g->addVertex(new Location(3, 'D'));
	g->addVertex(new Location(4, 'E'));
	Location* endVert = new Location(5, 'F');
	g->addVertex(endVert);



	g->AddEdge(0, 1, 2); // from 0=A, to 1=B, weight=2
	g->AddEdge(0, 2, 4); // from 0=A, to 2=C, weight=4

	g->AddEdge(1, 2, 1); // from 1=B, to 2=C, weight=1
	g->AddEdge(1, 3, 4); // from 1=B, to 3=D, weight=4
	g->AddEdge(1, 4, 2); // from 1=B, to 4=E, weight=2

	g->AddEdge(2, 4, 3); // from 2=C, to 4=E, weight=3

	g->AddEdge(3, 5, 2); // from 3=D, to 5=F, weight=2

	g->AddEdge(4, 3, 3); // from 4=E, to 3=D, weight=3
	g->AddEdge(4, 5, 2); // from 4=E, to 5=F, weight=2
	
	//g->Display();
	Dijkstra* d = new Dijkstra(g);
	Stack2<Node>* dPath = d->GetPath(startVert, endVert);
	while(dPath->IsEmpty() == false)
	{
		cout << dPath->Pop()->location->name << endl;
	}

	return 0;
}