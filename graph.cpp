// Luke Pan, Final Project, Dr. Rhonda Hoenigman
#include <iostream>
#include <fstream>
#include <sstream>
#include "float.h"
#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include "priorityQueue.h"

using namespace std;

// Public 
// Constructor, initializes total distance/jumps as zero
Graph::Graph()
{
    totalDistance = 0;
    totalJumps = 0;
} 

// Adds a vertex to the vector of vertices
void Graph::addVertex(std::string city)
{
    // Create the new vertex
    vertex *v = new vertex;
    v->city = city; v->visited = false; v->dist = 0;
    // add it to the list of vertices
    vertices.push_back(*v);
}

// Adds an edge between two vertices using their adjacency lists
void Graph::addEdge(std::string v1, std::string v2, double weight)
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

    if (!file)
    {
        cout << "Error: Could not open graph data for reading" << endl;
        return;
    }
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
            weight = stod(word.c_str());

            // add edge to graph if not -1 or 0
            if (weight != -1 && weight != 0)
                addEdge(selectedCity, cities[i], weight);
        }
    }

    // Close file
    file.close();
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

// Breadth-First Search for the shortest path between two vertices in an unweighted graph
vertex *Graph::bfs(std::string startC, std::string endC)
{
    // Find the starting vertex and set its data
    vertex *start = findVertex(startC);
    start->visited = true; start->dist = 0;

    // Create vertex pointer queue and enqueue the starting vertex
    queue <vertex*> queue; 
    queue.push(start); 

    while (!queue.empty()) {
        // Dequeue
        vertex *tmp = queue.front();
        queue.pop();
        for (int i = 0; i < tmp->adj.size(); i++) {
            
            // If the vertex has not been visited
            if (!(tmp->adj[i].v->visited)) {
                // Set distance
                tmp->adj[i].v->dist = tmp->dist + 1;

                if (tmp->adj[i].v->city == endC) {
                    totalJumps += tmp->adj[i].v->dist;
                    // Return a pointer to the end city
                    return tmp->adj[i].v;
                }
                else {
                    tmp->adj[i].v->visited = true;
                    queue.push(tmp->adj[i].v);
                }
            }
        }
    }
    // Unvisit all
    unvisit();
    return nullptr;
}

// Dijkstras Aglorithm for the shortest path between two vertices in a weighted graph
vertex *Graph::dijkstras(std::string startC, std::string endC)
{
    // Find the starting and ending vertices
    vertex *start = findVertex(startC);
    vertex *end = findVertex(endC);
    start->visited = true; start->dist = 0;

    // Create vertex pointer vector and add the starting vertex
    vector<vertex*> solved;
    solved.push_back(start); 

    while (!(end->visited)) {
        // Set min dist to the maximum double
        double minDist = DBL_MAX;
        vertex *curr = nullptr;

        for (int i = 0; i < solved.size(); i++) {
            vertex *tmp = solved[i];

            // Loop through adjacent vertices
            for (int j = 0; j < tmp->adj.size(); j++) {

                if (!(tmp->adj[j].v->visited)) {
                    // Create variable for distance
                    double currDist = tmp->dist + tmp->adj[j].weight;
                    // If distance is less than the min distance
                    if (currDist < minDist) {
                        curr = tmp->adj[j].v;
                        minDist = currDist;
                    }
                }
            }
        }
        // Set the correct distance
        curr->dist = minDist;
        curr->visited = true;
        solved.push_back(curr);
    }
    // Unvisit all
    unvisit();
    totalDistance += end->dist;
    return end;
}

// Distribute by route with shortest number of jumps, priority queue and truck passed in by reference
void Graph::distributeByJumps(PriorityQH *pq, truck *t)
{
    // Pop a node for the truck to travel to
    node endNode = pq->pop();

    // Run BFS from the city that the truck is at to the endNode city
    bfs(t->currCity, endNode.city);

    // Print where the shipment traveled to and from
    cout << "Truck #" << t->num << " traveled from " << t->currCity << " to " << endNode.city << endl;
    // Set truck city to end city
    t->currCity = endNode.city;
    
}

// Simulate multiple shipments, distribute by least amount of jumps, priority queue and truck passed in by reference
void Graph::runNTrucksByJumps(PriorityQH *pq, int n)
{
    // Return if priority queue is empty
    if (pq->isEmpty()) {
        cout << "PQ empty" << endl;
        return;
    }

    // Pop first node from priority queue
    node startNode = pq->pop();

    // Make a vector of truck structs numbered up to n and all beginning at the start location
    vector<truck> trucks;
    for (int i = 0; i < n; i++) {
        truck t = {startNode.city, i + 1};
        trucks.push_back(t);
    }

    // Distribute until the priority queue is empty
    int i = 0;
    while (!(pq->isEmpty())) {
        // Pass the address of the truck into the function
        distributeByJumps(pq, &trucks.at(i));
        i = (i + 1) % n;
    }

    // Print some final info
    cout << "All shipments delivered" << endl;
    for (int j = 0; j < trucks.size(); j++) {
        cout << "Truck #" << trucks.at(j).num << " ended in " << trucks.at(j).currCity << endl;
    }
    cout << "A total of " << totalJumps << " jumps were made" << endl;
}


// Distribute by route with shortest distance, priority queue and truck passed in by reference
void Graph::distributeByDistance(PriorityQH *pq, truck *t)
{
    // Pop a node for the truck to travel to
    node endNode = pq->pop();

    // Run BFS from the city that the truck is at to the endNode city
    dijkstras(t->currCity, endNode.city);

    // Print where the shipment traveled to and from
    cout << "Truck #" << t->num << " traveled from " << t->currCity << " to " << endNode.city << endl;
    // Set truck city to end city
    t->currCity = endNode.city;
}

// Simulate multiple shipments, distribute by shortest distance, priority queue and truck passed in by reference
void Graph::runNTrucksByDistance(PriorityQH *pq, int n)
{
    // Return if priority queue is empty
    if (pq->isEmpty()) {
        cout << "PQ empty" << endl;
        return;
    }

    // Pop first node from priority queue
    node startNode = pq->pop();

    // Make a vector of truck structs numbered up to n and all beginning at the start location
    vector<truck> trucks;
    for (int i = 0; i < n; i++) {
        truck t = {startNode.city, i + 1};
        trucks.push_back(t);
    }

    // Distribute until the priority queue is empty
    int i = 0;
    while (!(pq->isEmpty())) {
        // Pass the address of the truck into the function
        distributeByDistance(pq, &trucks.at(i));
        i = (i + 1) % n;
    }

    // Print some final info
    cout << "All shipments delivered" << endl;
    for (int j = 0; j < trucks.size(); j++) {
        cout << "Truck #" << trucks.at(j).num << " ended in " << trucks.at(j).currCity << endl;
    }
    cout << "A total of " << totalDistance << " miles were traveled" << endl;
}
// Get the total distance traveled
double Graph::getTotalDistance()
{
    return totalDistance;
}

// Get the total number of jumps performed
int Graph::getTotalJumps()
{
    return totalJumps;
}

// Reset to original state
void Graph::reset() 
{
    totalDistance = 0;
    totalJumps = 0;
    unvisit();
}

// Private
// Returns a pointer to the vertex of a desired city
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

// Sets the visited variable to false for all vertices
void Graph::unvisit() 
{
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
    }
}