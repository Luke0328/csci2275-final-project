// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "priorityQueue.h"
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]){
    // Read in priority queue data
    ifstream file1;
    file1.open(argv[1]);
    // Read in graph data
    // ifstream file2;
    // file2.open(argv[2]);

    // Throw error if file could not be opened
    if (!file1)
    {
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }

    // Create priority queue object with 20 cities
    PriorityQH pq(20);

    // Variables to store data
    string line, n, p;
    int p2;

    // Read in all the data from file1 and store it in the priority queue
    while(getline(file1, line)) {
        // save info from file
        stringstream ss(line);
        getline(ss, n, ',');
        getline(ss, p);

        // Convert string to integer
        p2 = stoi(p);

        // Push node to priority queue
        pq.push(n, p2);
    }

    // Create graph object
    Graph g;

    // Generate graph from file name
    g.generateGraph(argv[2]);

    g.printGraph();

    vertex *x = g.bfs("Denver", "Arvada");
    cout << x->city << x->dist << endl;

    // // Priority queue testing
    // pq.printQH();
    // node ret = pq.pop();
    // cout << ret.city << ret.population << endl;
    // pq.printQH();

    // Close files
    file1.close();
    // file2.close();

    return 0;
}