#include "FlightScheduler.h"

// Displays menu and takes user input repeatedly
void FlightScheduler::run() {
    int choice;
    while (true) {
        cout << "\n====== Flight Scheduling System ======\n";
        cout << "1. Add Flight Route\n";
        cout << "2. Display All Routes\n";
        cout << "3. Query Shortest Path\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addRoute(); break;
            case 2: displayAllRoutes(); break;
            case 3: queryShortestPath(); break;
            case 4: cout << " Exiting the system. Goodbye!\n"; return;
            default: cout << " Invalid choice. Try again.\n";
        }
    }
}

// Adds new flight route
void FlightScheduler::addRoute() {
    string src, dest;
    int time;

    cout << "Enter source city: ";
    cin >> src;
    cout << "Enter destination city: ";
    cin >> dest;
    cout << "Enter travel time (in minutes): ";
    cin >> time;

    if (src == dest) {
        cout << " Source and destination cannot be the same.\n";
        return;
    }

    graph.addEdge(src, dest, time);
}

// Displays all routes
void FlightScheduler::displayAllRoutes() {
    graph.displayRoutes();
}

// Queries shortest path
void FlightScheduler::queryShortestPath() {
    string src, dest;

    cout << "Enter source city: ";
    cin >> src;
    cout << "Enter destination city: ";
    cin >> dest;

    graph.shortestPath(src, dest);
}
