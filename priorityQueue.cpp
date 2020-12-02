// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#include <iostream>
#include "priorityQueue.h"

using namespace std;

// Public
PriorityQH::PriorityQH(int n)
{
    currSize = 0;
    capacity = n;
    maxHeap = new node[capacity];
    node empty = {"", 0};
    maxHeap[0] = empty;
}

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

node PriorityQH::pop()
{
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

void PriorityQH::printQH()
{
    for (int i = 1; i < currSize + 1; i++) {
        cout << maxHeap[i].city << "," << maxHeap[i].population << endl;
    }
}

// Private
void PriorityQH::maxHeapify(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int biggest = i;
    if ((left <= currSize) && (maxHeap[left].population > maxHeap[i].population)) {
        biggest = left;
    }
    if ((right <= currSize) && (maxHeap[right].population > maxHeap[i].population)) {
        biggest = right;
    }
    if (biggest != i) {
        swap(i, biggest);
        maxHeapify(biggest);
    }
}

void PriorityQH::swap(int i, int j)
{
    node tmp = {"", 0};
    tmp = maxHeap[i];
    maxHeap[i] = maxHeap[j];
    maxHeap[j] = tmp;
}