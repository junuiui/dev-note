#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int V; // number of vertices
    std::vector<std::vector<int>> adj;

public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void bfs(int start) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        std::cout << "BFS: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }

    void dfsUtil(int node, std::vector<bool>& visited) {
        visited[node] = true;
        std::cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        std::vector<bool> visited(V, false);
        std::cout << "DFS: ";
        dfsUtil(start, visited);
        std::cout << "\n";
    }

    void printGraph() {
        std::cout << "Adjacency List:\n";
        for (int i = 0; i < V; ++i) {
            std::cout << i << ": ";
            for (int neighbor : adj[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    g.bfs(0);
    g.dfs(0);

    return 0;
}
