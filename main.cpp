// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "priorityQueue.h"
#include "graph.h"

using namespace std;

// ./"executableName" priorityQueueData graphData
int main(int argc, char *argv[]){
    // Create priority queue object with a capacity of 20
    PriorityQH pq(20);

    // Generate priority queue from file name
    pq.generatePriorityQueue(argv[1]);

    // Create graph object
    Graph g;

    // Generate graph from file name
    g.generateGraph(argv[2]);

    std::string dmenu = "======Menu=====\n"
					"1. Refill priority queue from file\n"
					"2. Run simulation by jumps\n"
                    "3. Run simulation by distance\n"
                    "4. Least number of jumps between cities\n"
                    "5. Least distance between cities\n"
                    "6. Get total jumps\n"
                    "7. Get total distance\n"
                    "8. Print priority queue\n"
                    "9. Print graph\n"
                    "10. Reset simulation\n"
					"11. Quit";
    
    int choice;
    bool exit = false;
    
    cout << dmenu << endl;
    
    while(cin >> choice) {
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                // Generate graph from file
                pq.generatePriorityQueue(argv[1]);
                break;
            }
            
            case 2:
            {
                // Get user input
                int n;
                cout << "Enter number of trucks:" << endl;
                cin >> n;
                // Run function
                g.runNTrucksByJumps(&pq, n);
                break;
            }

            case 3:
            {
                // Get user input
                int n;
                cout << "Enter number of trucks:" << endl;
                cin >> n;
                // Run function
                g.runNTrucksByDistance(&pq, n);
                break;
            }
            
            case 4:
            {
                // Get user input
                string s, e;
                cout << "Enter start city:" << endl;
                cin >> s;
                cout << "Enter end city:" << endl;
                cin >> e;

                // Run breadth-first search and return number of jumps
                g.bfs(s, e);
                cout << g.getTotalJumps() << " jumps" << endl;
                g.reset();
                break;
            }

            case 5:
            {
                // Get user input
                string s, e;
                cout << "Enter start city:" << endl;
                cin >> s;
                cout << "Enter end city:" << endl;
                cin >> e;

                // Run breadth-first search and return number of jumps
                g.dijkstras(s, e);
                cout << g.getTotalDistance() << " miles" << endl;
                g.reset();
                break;
            }

            case 6:
            {
                // Print total jumps
                cout << g.getTotalJumps() << " jumps" << endl;
                break;
            }            
            
            case 7:
            {
                // Print total jumps
                cout << g.getTotalDistance() << " miles" << endl;
                break;
            }  

            case 8:
            {
                // Print priority queue
                pq.printQH();
                break;
            }  

            case 9:
            {
                // Print graph
                g.printGraph();
                break;
            }  

            case 10:
            {
                // Reset graph
                g.reset();
                break;
            }
                
            case 11:
            {
                exit = true;
                break;
            }
        }
        
        if (exit) {
            break;
        }
        
        cout << dmenu << endl;
    }

    // Testing code below
    // g.runNTrucksByJumps(&pq, 20);
    // g.runNTrucksByDistance(&pq, 20);

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