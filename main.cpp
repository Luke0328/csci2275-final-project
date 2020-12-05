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

    // Create priority queue object with a capacity of 20
    PriorityQH pq(20);

    // Generate graph from file name
    pq.generatePriorityQueue(argv[1]);

    pq.printQH();

    // Create graph object
    Graph g;

    // Generate graph from file name
    g.generateGraph(argv[2]);

    g.printGraph();

    cout << endl;

    g.runNTrucksByJumps(&pq, 20);

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

    return 0;
}