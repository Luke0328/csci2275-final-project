# csci2275-final-project
C++ final project for CSCI 2275 - Programming and Data structures. The goal of this project is to simulate prioritized vaccine distribution. In the simulation, the most populous cities receive the vaccines first. 

In this project I utilize two data structures that we learned about in class: a priority queue using a heap and a graph. The priority queue stores major cities in Colorado and orders them by population. The graph stores Colorado cities as vertices and uses weighted edges to represent distances between them. 

Prioritizing the most populous cities first, the program visits cities one by one until vaccines are distributed to all cities. Dijkstra's algorithm is used to calculate the shortest route between cities by distance. Alternatively, Breadth-first search is used to calculate the route with the least number of jumps. Finally, the user can choose to run the simulation with multiple shipping trucks. 

Priority queue data from: https://www.colorado-demographics.com/cities_by_population
Graph data from Google Maps