// Luke Pan, Final Project, Dr. Rhonda Hoenigman
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// Public 
// Constructor, initializes total distance as zero
Graph::Graph()
{
    totalDistance = 0;
} 

// Adds a vertex to the vector of vertices
void Graph::addVertex(std::string city)
{
    // Create the new vertex
    vertex *v = new vertex;
    v->city = city; 
    // add it to the list of vertices
    vertices.push_back(*v);
}

// Adds an edge between two vertices using their adjacency lists
void Graph::addEdge(std::string v1, std::string v2, int weight)
{
    vertex *x = findVertex(v1);
    vertex *y = findVertex(v2);
    // check if vertices exist in the graph
    if (!x || !y) {
        cout << "Vertix not found" << endl;
        return;
    }
    else {
    // check for duplicates
    for (int i = 0; i < x->adj.size(); i++) {
        if (x->adj[i].v->city == v2) {
            return;
        }
    }
    }
    // link them thru their adjacency lists
    adjVertex *adjX = new adjVertex;
    adjX->v = x; adjX->weight = weight;
    adjVertex *adjY = new adjVertex;
    adjY->v = y; adjY->weight = weight;
    x->adj.push_back(*adjY);
    y->adj.push_back(*adjX);
}

// Generates the graph from a file
void Graph::generateGraph(std::string filename)
{
    // Open file
    ifstream file(filename);

    // Variables to store data
    string line, word, selectedCity;
    double weight;

    // Vector to store city names
    vector<string> cities;
    
    // Read the first line and create a stringstream
    getline(file, line);
    stringstream lineStream(line);

    // read in vertices
    while(getline(lineStream, word, ',')) {
        addVertex(word);
        cities.push_back(word);
    }

    // read in edges
    while(getline(file, line)) {
        stringstream lineStream(line);
        getline(lineStream, word, ',');
        selectedCity = word;

        for(int i=0; i < cities.size(); i++) {
            getline(lineStream, word, ',');
            weight = atof(word.c_str());

            // add edge to graph if not -1
            if(weight != -1 && weight != 0)
                addEdge(selectedCity, cities[i], weight);
        }
    }
}

void Graph::printGraph()
{
    // Loop thru the vertices and print
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i].city << "::";
        for (int j = 0; j < vertices[i].adj.size(); j++) {
            cout << vertices[i].adj[j].v->city << " ";
            cout << "(" << vertices[i].adj[j].weight << ") ";
        }
        cout << endl;
    }
}

// Private
vertex *Graph::findVertex(std::string city)
{
    // Search for the vertex in vertices, return address if found else return null
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].city == city) {
            return &vertices[i];
        }
    }
    return NULL;
}