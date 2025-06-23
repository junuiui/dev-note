Tree
=============
# What is?
- Hierarchical 
- Nodes are connected with edge
- Root -> children
- Example..
    
- Example (Binary Tree):

         1        ← root
        / \
        2   3      ← children of 1
       / \
      4   5        ← leaf nodes

# Tree Terminology
| Term    | Description                              |
| ------- | ---------------------------------------- |
| `Node`    | A data point in the tree                 |
| `Root`    | The topmost node                         |
| `Parent`  | A node that has child nodes              |
| `Child`   | A node that descends from a parent       |
| `Leaf`    | A node with no children                  |
| `Sibling` | Nodes with the same parent               |
| `Depth`   | Distance from the root to a node         |
| `Height`  | Distance from a node to the deepest leaf |
| `Subtree` | A tree from any node as root             |
| `Edge`    | A connection between two nodes           |

# Types of Tree
| Term    | Description                              |
| ------- | ---------------------------------------- |
| `Binary Tree`    | Each node has at most two children |
| `Binary Search Tree`    | A binary tree where: left_child < parent < right_child|
| `Complete Binary Tree`  | All levels are filled wexcept the last, which is filled from left to right -> **Heap**, for example              |
| `Full Binary Tree`   | Every node has 0 or 2 children |
| `Perfect Binary Tree`    | All leaves are at the same level, and every internal node has 2 children                  |
| `N-ary Tree` | A tree where each node can have upto **N children**|
| `Trie`   | Used for string/prefix operations, like autocomplete |

# Tree Traversal Methods
- Inorder (Left → Root → Right)
    - In a BST, this gives sorted output.

- Preorder (Root → Left → Right)
    - Used for copying the tree or prefix expression.

- Postorder (Left → Right → Root)
    - Useful for deleting nodes, postfix expression.

- Level Order (Breadth First)
    - Top to bottom, left to right using a queue.


# Common Used Case
| Use Case           | Description                          |
| ------------------ | ------------------------------------ |
| `Heap          `     | Built on Complete Binary Tree        |
| `Binary Search Tree` | For fast lookup, insertion, deletion |
| `Trie             `  | Efficient string/prefix searching    |
| `Segment Tree    `   | Range queries (sum, min, max, etc.)  |
| `Syntax Tree     `   | Used in compilers                    |
| `Decision Tree   `   | Used in machine learning models      |

## Code Example

See [tree.cpp](tree.cpp) for C++ example.
