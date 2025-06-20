# Singly Linked List

## What is a Linked List?
A **linked list** is a linear data structure where elements (nodes) are stored in separate memory blocks and linked using pointers.

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

Node(1, Node2_addr), Node2(2, Node3_addr), Node3(3, Node4_addr)...

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

## Code Example
See [singly_linked_list.cpp](singly_linked_list.cpp) for C++ example.
See [singly_linked_list.cpp](singly_linked_list_unique_ptr.cpp) for C++ example (Unique Pointer).
