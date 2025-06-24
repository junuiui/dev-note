/*
Problem: Unique Paths II

You are given an m x n grid, where some cells are obstacles and some are free.
    0 means a free cell.
    1 means an obstacle.

You start at the top-left corner (0, 0) and want to reach the bottom-right corner (m-1, n-1).
You can only move:
    Right
    Down

Return the number of unique paths to reach the bottom-right corner without stepping on obstacles.

grid example)
    grid = [
        [0,0,0],
        [0,1,0],
        [0,0,0]
    ]
*/

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 1; i < m; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = uniquePathsWithObstacles(grid);
    cout << "Number of unique paths avoiding obstacles: " << result << endl;

    return 0;
}