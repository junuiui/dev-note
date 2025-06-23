Binary Search Tree
=

# What is?
- Special kind of binary tree where each node satisfies following properties
    - For every node, 
        - All values in the **left subtree** are **less than** the node's value
        - All values in the **right subtree** are **greater than** the node's value
- Above properties enable efficient **searching, insertion, and deletion**, typically in **O(log n)** time (if balanced)

# Operations and Time Complexity
| Operation | Average Case | Worst Case (Skewed) |
| --------- | ------------ | ------------------- |
| `Search`    | `O(log n)`     | `O(n)`                |
| `Insert`    | `O(log n)`     | `O(n)`                |
| `Delete`    | `O(log n)`     | `O(n)`                |

# Use cases
- Fast lookup, insert, and delete
- Sorted data traversal
- Used in:
    - Set/Map implementations (std::set, std::map)
    - Auto-completion
    - Range queries

# Key characteristics
| Feature         | Description                                  |
| --------------- | -------------------------------------------- |
| `Unique values`   | Typically no duplicates (but can be allowed) |
| `Sorted order`    | In-order traversal gives sorted sequence     |
| `Unbalanced risk` | Can degrade to linked list (O(n))            |



## Code Example
See [bst.cpp](bst.cpp) for C++ example.


