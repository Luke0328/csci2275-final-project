// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#include <iostream>
#include <fstream>
#include <sstream>
#include "math.h"
#include "priorityQueue.h"

using namespace std;

// Public
// Constructor, sets the first index of the array to an empty node and sets the capacity and current size
PriorityQH::PriorityQH(int n)
{
    currSize = 0;
    capacity = n;
    maxHeap = new node[capacity];
    node empty = {"", 0};
    maxHeap[0] = empty;
}

// Adds a node to the heap
void PriorityQH::push(std::string n, int p)
{
    // Create node to push
    node newNode = {n, p};
    if (currSize == capacity) {
        cout << "full" << endl;
        return;
    }
    currSize++;
    int i = currSize;
    maxHeap[i] = newNode;

    while ((i > 1) && (maxHeap[int(floor(double(i)/2))].population < maxHeap[i].population))  {
        swap(i, floor(i/2));
        i = floor(i/2);
    }
}

// Removes and returns the element with the highest priority
node PriorityQH::pop()
{
    // If the heap is empty, return an empty node
    if (currSize == 0)
    {
        cout << "empty" << endl;
        node empty = {"", 0};
        return empty;
    }
    if (currSize == 1) {
        currSize--;
        return maxHeap[1];
    }
    node toRet = maxHeap[1];
    maxHeap[1] = maxHeap[currSize];
    currSize--;
    maxHeapify(1);
    return toRet;
}

// Generates the priority queue and reads in data from a file
void PriorityQH::generatePriorityQueue(std::string filename)
{
    // Read in priority queue data
    ifstream file(filename);

    // Throw error if file could not be opened
    if (!file)
    {
        cout << "Error: Could not open priority queue data for reading" << endl;
        return;
    }

    // Variables to store data
    string line, n, p;
    int p2;

    // Read in all the data from file1 and store it in the priority queue
    while(getline(file, line)) {
        // save info from file
        stringstream ss(line);
        getline(ss, n, ',');
        getline(ss, p);

        // Convert string to integer
        p2 = stoi(p);

        // Push node to priority queue
        push(n, p2);
    }

    // Close file
    file.close();
}

// Prints the priority queue
void PriorityQH::printQH()
{
    if (isEmpty()) {
        cout << "Priority queue is empty" << endl;
    }
    for (int i = 1; i < currSize + 1; i++) {
        cout << maxHeap[i].city << "," << maxHeap[i].population << endl;
    }
}

// Returns true if the priority queue is empty, else return false
bool PriorityQH::isEmpty()
{
    if (currSize == 0) {
        return true;
    }
    return false;
}

// Private
// Reorders the heap so that it stays as a maxHeap
void PriorityQH::maxHeapify(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int biggest = i;
    if ((left <= currSize) && (maxHeap[left].population > maxHeap[i].population)) {
        biggest = left;
    }
    if ((right <= currSize) && (maxHeap[right].population > maxHeap[biggest].population)) {
        biggest = right;
    }
    if (biggest != i) {
        swap(i, biggest);
        maxHeapify(biggest);
    }
}

// Swap two nodes in the array
void PriorityQH::swap(int i, int j)
{
    node tmp = {"", 0};
    tmp = maxHeap[i];
    maxHeap[i] = maxHeap[j];
    maxHeap[j] = tmp;
}