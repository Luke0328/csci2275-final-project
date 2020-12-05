// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>

struct node{
    std::string city;
    int population;
};

class PriorityQH
{
public:
    PriorityQH(int n);
    void push(std::string n, int p);
    node pop();
    void generatePriorityQueue(std::string filename);
    void printQH();
    bool isEmpty();
protected:
private:
    node *maxHeap;
    int capacity;
    int currSize;
    void maxHeapify(int i);
    void swap(int i, int j);
};

#endif