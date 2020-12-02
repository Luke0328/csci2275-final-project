// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "priorityQueue.h"

using namespace std;

int main(int argc, char *argv[]){
    ifstream file1;
    file1.open(argv[1]);
    ifstream file2;
    file2.open(argv[2]);

    // Throw error if file could not be opened
    if (!file1)
    {
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }

    // Create priority queue object
    PriorityQH pq(30);
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

    // Close files
    file1.close();
    file2.close();

    return 0;
}