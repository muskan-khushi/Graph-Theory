// Floyd-Warshall Algorithm: Find shortest path between all pairs of vertices

#include <bits/stdc++.h>
using namespace std;

void Solve(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Only update if paths through k are valid
                if (matrix[i][k] != 9999 && matrix[k][j] != 9999)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the Adjacency Matrix (-1 for no edge):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1 && i != j)
                matrix[i][j] = 9999; // No edge
        }
    }

    Solve(matrix);

    cout << "\nShortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 9999)
                cout << "INF ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

