#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (const auto& edge : edges) {
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]) {
                distance[edge.v] = distance[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Print distances
    cout << "Vertex\tDistance from Source " << source << endl;
    for (int i = 0; i < V; ++i) {
        if (distance[i] == INT_MAX)
            cout << i << "\tINF" << endl;
        else
            cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (format: u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, E, edges, source);

    return 0;
}
