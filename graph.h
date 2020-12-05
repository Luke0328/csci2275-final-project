// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
#include "priorityQueue.h"

struct vertex;

struct adjVertex{
    vertex *v;
    double weight;
};

struct vertex{
    std::string city;
    bool visited;
    double dist;
    std::vector<adjVertex> adj;
};

struct truck {
    std::string currCity;
    int num;
};

class Graph
{
    public:
        Graph();  
        ~Graph(){}; 
        void addVertex(std::string city);
        void addEdge(std::string v1, std::string v2, double weight);
        void generateGraph(std::string filename);
        void printGraph();
        vertex *bfs(std::string startC, std::string endC);
        vertex *dijkstras(std::string startC, std::string endC);
        double getTotalDistance();
        int getTotalJumps();
        void distributeByJumps(PriorityQH *pq, truck *t);
        void distributeByDistance(PriorityQH *pq, truck *t);
        void runNTrucksByDistance(PriorityQH *pq, int n);
        void runNTrucksByJumps(PriorityQH *pq, int n);
        void reset();

    protected:
    private:
        vertex *findVertex(std::string city);
        void unvisit();
        std::vector<vertex> vertices;
        double totalDistance;
        int totalJumps;
};

#endif