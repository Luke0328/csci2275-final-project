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
        void addVertex(std::string city);
        void generateGraph();
        void printGraph();
        void bfs(std::string city);
        void dijkstras(std::string city);
        double getTotalDistance();
        void distributeByPriority();
        void distributeByJumps();
        void reset();

    protected:
    private:
        vertex *findVertex(std::string city);
        std::vector<vertex> vertices;
        double totalDistance;
};