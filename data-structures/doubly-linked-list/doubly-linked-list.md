## Doubly Linked List

- Each node contains:
  - A data value
  - A pointer to the **next** node
  - A pointer to the **previous** node

## Common Operations

- `pushFront(value)` - Insert at the beginning
- `pushBack(value)` - Insert at the end
- `deleteValue(value)` - Delete a node by value
- `printForward()` - Print from head to tail
- `printBackward()` - Print from tail to head

## Time Complexity

| Operation      | Time    |
|----------------|---------|
| Insert (front) | O(1)    |
| Insert (end)   | O(1)\*  |
| Search         | O(n)    |
| Delete         | O(n)    |

\* With tail pointer
