# Stack

## What is a Stack?
- A **Last In, First Out (LIFO)** data structure.
- The last element added is the first one to be removed.

## Common Operations
- `push(x)`: Add element `x` on top.
- `pop()`: Remove the top element.
- `top()`: Access the top element without removing.
- `isEmpty()`: Check if stack is empty.

## Use Cases
- Function call stacks.
- Undo/redo features.
- Expression parsing and evaluation.

## Time Complexity
| Operation | Time Complexity |
| --------- | --------------- |
| push      | O(1)            |
| pop       | O(1)            |
| top       | O(1)            |

## Code Example
See [stack.cpp](stack.cpp) for C++ example.
