# Queue

## What is a Queue?

- A **First In, First Out (FIFO)** data structure.
- The first element added is the first one to be removed.

## Common Operations

- `enqueue(x)`: Add element `x` to the back.
- `dequeue()`: Remove the front element.
- `front()`: Access the front element without removing.
- `isEmpty()`: Check if queue is empty.

## Use Cases

- Print spooling.
- Task scheduling.
- Breadth-First Search (BFS) in graphs.

## Time Complexity

| Operation | Time Complexity |
| --------- | --------------- |
| enqueue   | O(1)            |
| dequeue   | O(1)            |
| front     | O(1)            |

## Code Example

See [queue.cpp](queue.cpp) for C++ example.
