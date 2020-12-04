// Luke Pan, Final Project, Dr. Rhonda Hoenigman

#include<iostream>
#include<vector>

struct vertex;

struct adjVertex{
    vertex *v;
    double weight;
};

struct vertex{
    std::string city;
    bool visited;
    bool received;
    double dist;
    std::vector<adjVertex> adj;
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
        void distributeByDistance();
        void distributeByJumps();
        void runNTrucksByDistance();
        void runNTrucksByJumps();
        void reset();

    protected:
    private:
        vertex *findVertex(std::string city);
        void unvisit();
        std::vector<vertex> vertices;
        double totalDistance;
        int totalJumps;
};