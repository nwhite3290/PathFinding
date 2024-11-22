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

#include "Dijkstra.h"
#include "Graph.h"
#include "Stack.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void title() {
  vector<string> authors = {" Nathan White, "};
  cout << "\n\n----------------------------------------------------------------"
          "\n";
  cout << "Authors: ";
  for (string author : authors) {
    cout << author;
  }
  cout << endl;
  cout << "Date: 11/24/2024\n";
  cout << "Course: CS311 (Data structures and Algorithms)\n";
  cout << "Description : Program to find the shortest route between cities\n";
  cout << "----------------------------------------------------------------\n";
}

/**
 * Extracts the city information from an input file
 * @param ID the entry number of the associated city
 * @param City_Code the key representing a city
 * @param City_Name the string for holding the city name
 * @param Population the population of the associated city
 * @param Elevation the elevation of the associated city
 */
struct City {
  int City_Key; // int ID
  int Population;
  int Elevation;
  string City_Code; // const char* City_Code
  string City_Name; // string City_Name
};

/**
 * Extracts the route information from an input file
 * @param From_City_ID the key representing the source city
 * @param To_City_ID the key representing the destination city
 * @param Distance the distance from the source to the destination
 */
struct Route {
  int Route_From_Key; // int ID
  int Route_To_Key;
  int Distance;
  //string Route_From_City_Code; // string From_City_ID
  //string Route_To_City_Code;   // string To_City_ID
};







int main(int argc, char **argv) {
  title();
	/*
   * Graph(int key, string name)
   * create Adjacenty Matrix of Locations
   * using Cities as Vertices
   * city.City_Code = Vertex = Graph(Location* name)
   * city.City_Key = Used for calling a vertex
   */
  Graph *g = new Graph(20);
  Location *startVert;
  Location *endVert;

  int V = 0;
  std::string source;      // argv[1];
  std::string destination; // argv[2];

  // testing
  //Location *startVert = new Location(0, "AA");
  //g->addVertex(startVert);

  if (argv[1] && argv[2]) {
    source = argv[1];
    destination = argv[2];
    cout << "Source: " << source
         << "\nDestination: " << destination << endl;
  }
  cout << endl;

  // int cost[100][100];

  //[vertices] int: City_Key, Population, Elevation
  // String: City_Code, City_Name
  City city;
  vector<City> cityList;
  //[edges] int: Route_From_City_Key, Route_To_City_Key, Distance
  // string: Route_From_City_Code, Route_To_City_Code
  Route route; // edges
  vector<Route> routeList;

  //  create input and output files
  ifstream infile1;
  ifstream infile2;
  ofstream outfile;

  //  Open output file - Exit the program if opening failed
  outfile.open("city_data.txt");
  if (outfile.fail()) {
    cout << "Error opening output file city_data.txt\n";
    return 1;
  }

  //  Open input file 1 - Exit the program if opening failed
  infile1.open("city.txt");
  if (infile1.fail()) {
    cout << "Error opening input file - city.txt:\n";
    return 1;
  }
  int count = 0;
  while (count < 20) {
	int key;
	string code;
	string name;
	int pop;
	int ele;
    //infile1 >> city.City_Key >> city.City_Code >> city.City_Name >>
        //city.Population >> city.Elevation;
	infile1 >> key >> code >> name >> pop >> ele;
	city.City_Key = key;
	city.City_Code = code;
	city.City_Name = name;
	city.Population = pop;
	city.Elevation = ele;
	cityList.emplace_back(city);
    
	 cout << "key: " << key << ", code: " << code << ", name: " << name << ", pop: " << pop << ", ele: " << ele << endl << endl;
	 if (code == source)
	 {
		
		 startVert = new Location(key, code);
		 cout << "startVert: " << startVert << ", key: " << key << ", code: " << code << endl << endl;
		 g->addVertex(startVert);
	 }
	 else if (code == destination)
	 {
		
		endVert = new Location(key, code);
		cout << "endVert: " << endVert << ", key: " << key << ", code: " << code << endl << endl;
		g->addVertex(endVert);
	 }
	 else
	 {
		cout << "AddVertex - ";
		cout << "key: " << key << ", code: " << code << endl << endl;
		g->addVertex(new Location(key, code));
	 }
	 count++;
	 V++;
  }
  infile1.close();

  //  open input file 2 - Exit the program if opening failed
  infile2.open("roads.txt");
  if (infile2.fail()) {
    cout << "Error opening input file - roads.txt\n";
    return 1;
  }
  while (infile2)
  {
	int f;
	int t;
	int d;
	//string fc = "xx";
	//string tc = "xx";
	infile2 >> f >> t >> d;
	if (!routeList.empty())
	{
		if(routeList.back().Route_From_Key == f &&
			routeList.back().Route_To_Key == t &&
			routeList.back().Distance == d)
		{
			break;
		}
	}
    //infile2 >> route.Route_From_Key >> route.Route_To_Key >> route.Distance;
    //route.Route_From_City_Code = fc;
    //route.Route_To_City_Code = tc;
		route.Route_From_Key = f;
		route.Route_To_Key = t;
		route.Distance = d;
		routeList.emplace_back(route);
		cout << "from: " << f << ", to: " << t << ", dist: " << d << endl << endl;
		g->AddEdge(f, t, d); // from 0=A, to 1=B, weight=2
  }

  infile2.close();

/*
  for (int i = 0; i < cityList.size() - 1; i++) {
    for (int j = 0; j < routeList.size() - 1; j++) {
      if (routeList[j].Route_From_Key == cityList[i].City_Key &&
          routeList[j].Route_From_City_Code == "xx") {
        routeList[j].Route_From_City_Code = cityList[i].City_Code;
      }
      if (routeList[j].Route_To_Key == cityList[i].City_Key &&
          routeList[j].Route_To_City_Code == "xx") {
        routeList[j].Route_To_City_Code = cityList[i].City_Code;
      }


		
		if (cityList[i].City_Code == Route_Source_Key)
		{
			Location *startVert = new Location(cityList[i].City_Key, cityList[i].City_Name);
		}
		if (cityList[i].City_Code == Route_Destination_Key)
		{
			Location *endVert = new Location(cityList[i].City_Key, cityList[i].City_Name);
		}
		
    }
  }
*/

  //Location *startVert = new Location(cityList[0].City_Key, cityList[0].City_Code);
  //g->addVertex(startVert);
	//for (int i = 1; i < cityList.size() - 2; i++)
	//{
		//g->addVertex(new Location(cityList[i].City_Key, cityList[i].City_Code));
	//}
	//Location *endVert = new Location(cityList[19].City_Key, cityList[19].City_Code);
  //g->addVertex(endVert);
  // for testing
  //Location *endVert = new Location(5, "FF");
  //g->addVertex(endVert);
	cout << "V: " << V << endl;
  g->Display();
  cout << endl;
/*
  for (int i = 0; i < cityList.size() - 1; i++)
  {
		std::cout << cityList[i] << endl;
  }

  for (int i = 0; i < routeList.size() - 1; i++)
  {
		cout << routeList[i] << endl;
  }
*/
  /*
   * Graph(int key, string name)
   * create Adjacenty Matrix of Locations
   * using Cities as Vertices
   * city.City_Code = Vertex = Graph(Location* name)
   * city.City_Key = Used for calling a vertex
   */
  // Graph *g = new Graph(20);
  /*
    Location *startVert = new Location(0, "AA");

    g->addVertex(startVert);
    g->addVertex(new Location(1, "BB"));
    g->addVertex(new Location(2, "CC"));
    g->addVertex(new Location(3, "DD"));
    g->addVertex(new Location(4, "EE"));
    Location *endVert = new Location(5, "FF");
    g->addVertex(endVert);
  */
  // pause_time(1);

  // pause_time(1);

  // print cities
  /*
    if (argv[1] && argv[2]) {
      for (int i = 0; i < cityList.size() - 1; i++) {
        if (source == cityList[i].City_Code) {
          cout << "source == cityList[i].ID: " << cityList[i].City_Name << endl;
          outfile << "source == cityList[i].ID: " << cityList[i].City_Name
                  << endl;
        }
        if (destination == cityList[i].City_Code) {
          cout << "destination == cityList[i].ID: " << cityList[i].City_Name
               << endl;
          outfile << "destination == cityList[i].ID: " << cityList[i].City_Name
                  << endl;
        }
      }
    } else {
  */

  /*
      cout << "No source or destination input" << endl;
      cout << "please run ./a.out <City_Code> <City_Code>" << endl;
      cout << "ex: ./a.out AN VV" << endl;
      cout << endl;
      for (int i = 0; i < cityList.size() - 1; i++) {
        // cout << cityList[i].ID << ", " << cityList[i].City_Code << ", " <<
        // cityList[i].City_Name; cout << ", " << cityList[i].Population << ", "
        // << cityList[i].Elevation << endl;
      }
    }
  */
  /*
          // print routes
          for (int j = 0; j = routeList.size() - 1; j++)
          {
                  cout << routeList[j].From_City_ID << ", " <<
     routeList[j].To_City_ID << ", " << routeList[j].Distance << endl;
          }
  */

  /*Graph *g = new Graph(6);
  Location *startVert = new Location(0, "AA");

  g->addVertex(startVert);
  g->addVertex(new Location(1, "BB"));
  g->addVertex(new Location(2, "CC"));
  g->addVertex(new Location(3, "DD"));
  g->addVertex(new Location(4, "EE"));
  Location *endVert = new Location(5, "FF");
  g->addVertex(endVert);
*/

/*
  g->AddEdge(0, 1, 2); // from 0=A, to 1=B, weight=2
  g->AddEdge(0, 2, 4); // from 0=A, to 2=C, weight=4

  g->AddEdge(1, 2, 1); // from 1=B, to 2=C, weight=1
  g->AddEdge(1, 3, 4); // from 1=B, to 3=D, weight=4
  g->AddEdge(1, 4, 2); // from 1=B, to 4=E, weight=2

  g->AddEdge(2, 4, 3); // from 2=C, to 4=E, weight=3

  g->AddEdge(3, 5, 2); // from 3=D, to 5=F, weight=2

  g->AddEdge(4, 3, 3); // from 4=E, to 3=D, weight=3
  g->AddEdge(4, 5, 2); // from 4=E, to 5=F, weight=2
*/
	cout << "startVert: " << startVert << endl;
	cout << "endVert: " << endVert << endl;
  // g->Display();
  Dijkstra *d = new Dijkstra(g);
  Stack<Node> *dPath = d->GetPath(startVert, endVert);
  while (dPath->IsEmpty() == false) {
    cout << dPath->Pop()->location->name << endl;
  }
  //while (dPath->IsEmpty() == false) {
    //cout << dPath->Pop()->location->name << endl;
  //}
	cout << "distance: " << d->getDistance() << endl;
	
  outfile.close();
  return 0;
}