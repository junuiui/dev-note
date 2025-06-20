# Singly Linked List

## What is a Linked List?

A **linked list** is a linear data structure where elements (nodes) are stored in separate memory blocks and linked using pointers.

## Singly Linked List

- Each node contains:
  - A data value
  - A pointer to the **next** node
- The last node points to `nullptr`.

## Operations

- `insertFront(value)` - Insert at the beginning
- `insertBack(value)` - Insert at the end
- `deleteValue(value)` - Delete a node by value
- `search(value)` - Check if a value exists
- `print()` - Display all elements

## Use Cases

- Dynamic memory-efficient structures
- Insertion/deletion at arbitrary positions
- Useful for implementing stacks, queues, etc.

## Time Complexity

| Operation      | Time      |
|----------------|-----------|
| Insert (front) | O(1)      |
| Insert (end)   | O(n)      |
| Search         | O(n)      |
| Delete         | O(n)      |
