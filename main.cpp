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

    // Throw error if file could not be opened
    if (!file1)
    {
        cout << "Error: Could not open priority queue data for reading" << endl;
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

    // BFS testing
    // vertex *x = g.bfs("Pueblo", "Grand Junction");
    // cout << x->city << x->dist << endl;
    // x = g.bfs("Grand Junction", "Fort Collins");
    // cout << x->city << x->dist << endl;
    // cout << g.getTotalJumps() << endl;

    // Dijkstras testing
    // vertex *y = g.dijkstras("Denver", "Arvada");
    // cout << y->city << y->dist << endl;
    // y = g.dijkstras("Arvada", "Fort Collins");
    // cout << y->city << y->dist << endl;
    // cout << g.getTotalDistance() << endl;

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