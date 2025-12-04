#ifndef FLIGHTSCHEDULER_H
#define FLIGHTSCHEDULER_H

#include "Graph.h"

// Handles user interaction and menu logic
class FlightScheduler {
private:
    Graph graph;   // Graph object to store routes

public:
    void run();               // Main menu loop
    void addRoute();          // Adds new route
    void displayAllRoutes();  // Displays all routes
    void queryShortestPath(); // Finds shortest path
};

#endif
