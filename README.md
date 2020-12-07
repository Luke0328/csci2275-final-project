# csci2275-final-project
C++ final project for CSCI 2275 - Programming and Data structures. The goal of this project is to simulate prioritized vaccine distribution. In the simulation, the most populous cities receive the vaccines first. 

In this project I utilize two data structures that we learned about in class: a priority queue using a heap and a graph. The priority queue stores major cities in Colorado and orders them by population. The graph stores Colorado cities as vertices and uses weighted edges to represent distances between them. 

Dijkstra's algorithm is used to calculate the shortest route between cities by distance. Breadth-first search is used to calculate the route with the least number of jumps. Prioritizing the most populous cities first, the program visits cities one by one until vaccines are distributed to all cities. The user can choose the number of shipping trucks to run the simulation with.

Priority queue data from: https://www.colorado-demographics.com/cities_by_population
Graph data from Google Maps: https://www.google.com/maps

To download the code, click the green "Code" button on Github. Then click "Download ZIP". Finally, unzip the code. To view the code open the folder with your text editor of choice.
To run the program, first compile it by running "g++ -std=c++11 priorityQueue.cpp graph.cpp main.cpp -o run" in your terminal. Then enter "./run pqData.csv graphData.csv". The first argument should be the priority queue data and the second argument should be the graph data.

No additional dependencies or system requirements.