#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Compare function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unionSets(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if (xroot == yroot) return;

        // Union by rank
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
};

void kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result;  // Store the MST
    sort(edges.begin(), edges.end(), compare); // Sort all edges by weight

    DisjointSet ds(V);

    for (Edge e : edges) {
        int setU = ds.find(e.src);
        int setV = ds.find(e.dest);

        // Check if current edge forms a cycle
        if (setU != setV) {
            result.push_back(e);
            ds.unionSets(setU, setV);
        }
    }

    cout << "Edge \tWeight\n";
    for (Edge e : result)
        cout << e.src << " - " << e.dest << "\t" << e.weight << "\n";
}

int main() {
    int V = 5; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V);

    return 0;
}
