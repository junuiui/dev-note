#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DFS 함수
void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << "Visited: " << node << endl;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

// BFS
void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << "Visited: " << node << endl;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5; // number of nodes: 0 to 4
    vector<vector<int>> graph(n);

    // 그래프 연결
    graph[0] = {1, 2};
    graph[1] = {3};
    graph[2] = {4};
    graph[3] = {};
    graph[4] = {};

    vector<bool> visited(n, false);

    dfs(0, graph, visited); // 시작 노드: 0
    bfs(0, graph, visited); // 시작점 0

    return 0;
}

/*
dfs(0)
 └ dfs(1)
     └ dfs(3)
 └ dfs(2)
     └ dfs(4)
*/
