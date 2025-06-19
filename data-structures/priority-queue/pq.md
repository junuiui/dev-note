# Priority Queue (Heap)

## What is a Priority Queue?

A priority queue is a special type of queue where each element has a **priority**.
- Elements with higher priority are served first.
- Implemented as a **binary heap** under the hood.

In C++, it's implemented using `std::priority_queue`.

---

## Types

- **Max-Heap** (default in C++): Highest value comes out first.
- **Min-Heap**: Lowest value comes out first (requires custom comparator).

---

## Common Operations

- `push(x)`: Insert element `x`.
- `top()`: Access the highest-priority element.
- `pop()`: Remove the highest-priority element.
- `empty()`: Check if the queue is empty.

---

## Time Complexity

| Operation | Time    |
|-----------|---------|
| push      | O(log n) |
| pop       | O(log n) |
| top       | O(1)     |

---

## Code Example

See [pq.cpp](pq.cpp) for both STL and custom implementations.
