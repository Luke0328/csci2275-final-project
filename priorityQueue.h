// Luke Pan, Final Project, Dr. Rhonda Hoenigman

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
    void printQH();
protected:
private:
    node *maxHeap;
    int capacity;
    int currSize;
    void maxHeapify(int i);
    void swap(int i, int j);
};