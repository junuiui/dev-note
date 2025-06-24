/*
Problem: Unique Paths (2D DP)
    You are a robot on a 2D grid with size m x n.
    You start at the top-left corner (0, 0) and want to reach the bottom-right corner (m-1, n-1).

You can only move:
    right
    down

Find the number of unique paths to reach the destination.

Input
    m = 3, n = 7
Output
    28
*/

#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

int findPaths(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // first row: only go right
    for (int j = 0; j < n; j++) {
        grid[0][j] = 1;
    }

    // first col: only go down
    for (int i = 0; i < m; i++) {
        grid[i][0] = 1;
    }

    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }

    return grid[m-1][n-1];
}

int main() {
    int m = 3; // rows
    int n = 7; // columns

    vector<vector<int>> grid(m, vector<int>(n, 0));

    int result = findPaths(grid);

    cout << "Number of unique paths: " << result << endl;

    return 0;
}
