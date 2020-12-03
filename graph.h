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
    double distanceFromStart;
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
        void bfs(std::string city);
        void dijkstras(std::string city);
        double getTotalDistance();
        void distributeByDistance();
        void distributeByJumps();
        void runNTrucks();
        void reset();

    protected:
    private:
        vertex *findVertex(std::string city);
        std::vector<vertex> vertices;
        double totalDistance;
};