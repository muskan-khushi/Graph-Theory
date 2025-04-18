// Write a program to find the number of vertices, even vertices, odd vertices, and the number of edges in a graph.

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> adj = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int n = adj.size();
    vector<int> degree(n, 0);
    int edge = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1 && i != j) {
                degree[i]++;
                edge++;
            }
        }
    }

    int even = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 == 0) {
            even++;
        }
    }

    cout << "Number of vertices = " << n << endl;
    cout << "Number of edges = " << edge / 2 << endl;
    cout << "Number of odd vertices = " << n - even << endl;
    cout << "Number of even vertices = " << even << endl;

    return 0;
}
