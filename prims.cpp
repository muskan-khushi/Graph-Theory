#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 5 // Number of vertices (you can change this)

// Function to find the vertex with the minimum key value
int minKey(vector<int>& key, vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the MST stored in parent[]
void printMST(vector<int>& parent, vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

// Function to construct and print MST for a graph represented using adjacency matrix
void primMST(vector<vector<int>>& graph) {
    vector<int> parent(V);    // Array to store constructed MST
    vector<int> key(V, INT_MAX);  // Key values used to pick minimum weight edge
    vector<bool> mstSet(V, false); // To represent set of vertices included in MST

    key[0] = 0;     // Include first vertex in MST
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick minimum key vertex not yet included
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    // Example graph (Adjacency Matrix)
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
