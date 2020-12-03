// Luke Pan, Final Project, Dr. Rhonda Hoenigman
#include <iostream>
#include "graph.h"
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// Public 
Graph::Graph()
{
    totalDistance = 0;
}  

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
void Graph::addVertex(std::string city)
{
    // Create the new vertex
    vertex *v = new vertex;
    v->city = city; 
    // add it to the list of vertices
    vertices.push_back(*v);
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
    // Search for the vertex in vertices, return address if found
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].city == city) {
            return &vertices[i];
        }
    }
    return NULL;
}