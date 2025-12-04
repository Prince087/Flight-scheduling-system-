#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Graph class to represent flight routes using adjacency list
class Graph {
private:
    // Stores city as key and list of (destination, time) as value
    unordered_map<string, vector<pair<string, int>>> adjList;

public:
    // Adds a directed flight route from src to dest
    void addEdge(const string& src, const string& dest, int time);

    // Displays all stored flight routes
    void displayRoutes() const;

    // Finds shortest path using Dijkstra Algorithm
    vector<string> shortestPath(const string& src, const string& dest);
};

#endif
