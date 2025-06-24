Dynamic Programming
=
## What is?
- Optimization technique used to solve **overlapping subproblem** problems by **sorting solutions** to subproblems instead of recomputing them
    - Useful when a **recursive brute force solution** has **redundant work**

## Key Concepts
| Concept                     | Description                                                             |
| --------------------------- | ----------------------------------------------------------------------- |
| **Overlapping Subproblems** | Same subproblems appear multiple times                                  |
| **Optimal Substructure**    | The solution to the problem depends on solutions to smaller subproblems |
| **Memoization (Top-Down)**  | Use a cache + recursion                                                 |
| **Tabulation (Bottom-Up)**  | Use an array and build the solution iteratively                         |

## Common DP Problems Type
| Type                | Examples                                            |
| ------------------- | --------------------------------------------------- |
| **1D DP**           | Fibonacci, Climbing Stairs, House Robber            |
| **2D DP**           | Grid Path, Longest Common Subsequence               |
| **Knapsack**        | 0/1 Knapsack, Subset Sum                            |
| **Sequence Based**  | LIS (Longest Increasing Subsequence), Edit Distance |
| **String Matching** | LCS, Palindromic Substrings, Regex Match            |
| **State DP**        | DP with multiple parameters (e.g., DP\[i]\[j]\[k])  |
| **Bitmask DP**      | Traveling Salesman Problem                          |
| **DP on Trees**     | Tree DP (e.g., maximum sum path in tree)            |

