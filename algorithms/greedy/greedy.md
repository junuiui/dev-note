Greedy
=
## What is?
- Builds up a solution by **choosing the best option at each step**, hoping that this local choice leads to a **globally optimal solution**

## Key Properties
| Property                 | Meaning                                                           |
| ------------------------ | ----------------------------------------------------------------- |
| **Greedy Choice**        | Make a locally optimal choice at each step                        |
| **Optimal Substructure** | The global optimal solution can be built from optimal subproblems |
- Greedy does **NOT** always guarantee the best solution - only works when the problem satisfies these two properties

## Why use?
- Often faster than DP (no need to explore all possibilities)
- Simple and intuitive
- Very useful in interviews and real-world scheduling/resource problems

## Common Patterns & Examples
| Pattern                   | Example Problems                         |
| ------------------------- | ---------------------------------------- |
| **Sort + Pick Strategy**      | Activity Selection, Job Scheduling       |
| **Resource Allocation**       | Coin Change (limited cases), Gas Station |
| **Coverage Minimization**     | Jump Game, Balloon Arrows                |
| **Optimization by Frequency** | Huffman Coding                           |

## Time Complexity
Usually ``O(n log n)`` due to sorting, then ``O(n)`` for greedy decisions.

## When to use?
- Ask yourself:
    - Can I make a choice that looks best now and be sure it won't hurt the future?
    - Does the problem allow sorting and greedy picking?
    - Is it possible to prove my choice leads to optimality?



