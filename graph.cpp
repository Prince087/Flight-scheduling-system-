#include "Graph.h"

// Adds a new route between two cities
void Graph::addEdge(const string& src, const string& dest, int time) {
    if (time < 0) {
        cout << "Travel time cannot be negative.\n";
        return;
    }

    // Add route (directed edge)
    adjList[src].push_back(make_pair(dest, time));

    // Ensure destination city exists
    if (!adjList.count(dest)) {
        adjList[dest] = vector<pair<string, int>>();
    }

    cout << "Route added: " << src << " -> " << dest << " (" << time << " mins)\n";
}

// Displays all saved routes
void Graph::displayRoutes() const {
    if (adjList.empty()) {
        cout << "No routes available.\n";
        return;
    }

    cout << "\n--- All Flight Routes ---\n";

    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        string src = it->first;
        vector<pair<string, int>> edges = it->second;

        for (size_t i = 0; i < edges.size(); i++) {
            string dest = edges[i].first;
            int time = edges[i].second;

            cout << src << " -> " << dest << " (" << time << " mins)\n";
        }
    }
}

// Finds the shortest path using Dijkstra’s Algorithm
vector<string> Graph::shortestPath(const string& src, const string& dest) {
    if (!adjList.count(src) || !adjList.count(dest)) {
        cout << "One or both cities not found.\n";
        return vector<string>();
    }

    unordered_map<string, int> dist;        // Distance from source
    unordered_map<string, string> parent;  // Stores path

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // Initialize distances
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        dist[it->first] = INT_MAX;
    }

    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        pair<int, string> top = pq.top();
        pq.pop();

        int d = top.first;
        string u = top.second;

        if (u == dest) break;

        vector<pair<string, int>> neighbors = adjList[u];

        for (size_t i = 0; i < neighbors.size(); i++) {
            string v = neighbors[i].first;
            int w = neighbors[i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No path found from " << src << " to " << dest << ".\n";
        return vector<string>();
    }

    // Reconstruct shortest path
    vector<string> path;
    string at = dest;

    while (at != "") {
        path.push_back(at);
        if (parent.count(at))
            at = parent[at];
        else
            break;
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest path from " << src << " to " << dest << ":\n";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }

    cout << "\nTotal Travel Time: " << dist[dest] << " mins\n";

    return path;
}
