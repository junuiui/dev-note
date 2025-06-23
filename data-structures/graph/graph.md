Graph
=
# What is?
- A graph is a collection of nodes (also called vertices) connected by edges.
    - A graph can be:
        - Directed (→) or Undirected (—)
        - Weighted or Unweighted
        - Cyclic or Acyclic
        - Connected or Disconnected

# Real-World Examples
- Google Maps → cities (nodes) and roads (edges)
- Social networks → users and relationships
- Web pages and hyperlinks
- Network routing

# Terminology
| Term       | Meaning                                |
| ---------- | -------------------------------------- |
| `Vertex (V)` | A node in the graph                    |
| `Edge (E)`   | A connection between two nodes         |
| `Degree `    | Number of edges connected to a node    |
| `Path`       | A sequence of connected nodes          |
| `Cycle`      | Path that starts and ends at same node |

# Algorithm
| Algorithm        | Purpose                      |
| ---------------- | ---------------------------- |
| `BFS / DFS`        | Traversal, component check   |
| `Dijkstra`         | Shortest path (weighted)     |
| `Bellman-Ford`     | Shortest path with negatives |
| `Floyd-Warshall`   | All-pairs shortest paths     |
| `Prim / Kruskal`   | Minimum Spanning Tree        |
| `Topological Sort` | Ordering for DAGs            |

# Types
| Type       | Example                       |
| ---------- | ----------------------------- |
| `Undirected` | Social Network                |
| `Directed`   | Web Links, Task Scheduling    |
| `Weighted`   | Road Maps                     |
| `Unweighted` | Friend Suggestions            |
| `Cyclic`     | Currency Exchange (Arbitrage) |
| `Acyclic`    | Build Systems, Dependencies   |

## Code Example
See [graph.cpp](graph.cpp) for C++ example.
