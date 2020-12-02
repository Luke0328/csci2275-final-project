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
    double distance;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph(){};  
        ~Graph(){}; 
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void generateGraph();
        void printGraph();
        vertex *findVertex(std::string name);
        void bfs(std::string name);
        void dijkstras(std::string name);
        double getTotalDistance();
        void distributeByPriority();
        void distributeByJumps();

    protected:
    private:
        std::vector<vertex> vertices;
        double totalDistance;
};