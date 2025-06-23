Heap
=
# What is?
- Complete Binary Tree that satisfies following properties:
    - **Max Heap**: Every parent node is **greater than or equal to** its children
    - **Min Heap**: Every parent node is **less than or equal to** its children
- Because it's a compelte binary tree, heaps are usually implements as arrays

# Why use?
- Efficiently get **maximum or minimum** element in `O(1)` time
- Insert and delete operations take `O(log n)` time
- Used in:
    - Priority Queue
    - Heap Sort
    - Graph algorithms (Dijkstra's, Prim's)

# Heap Operations
| Operation | Description                    | Time Complexity |
| --------- | ------------------------------ | --------------- |
| `push`    | Insert a new element           | O(log n)        |
| `pop`     | Remove root (max/min)          | O(log n)        |
| `top`     | Get root element               | O(1)            |
| `heapify` | Build heap from unordered data | O(n)            |

## Code Example

See [heap.cpp](heap.cpp) for C++ example.
