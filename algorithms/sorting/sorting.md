Sorting
=
## What is?
- Arranging elements in a specific order
    1. Ascending    (e.g., `[1, 2, 3, 4]`)
    2. Descending   (e.g., `[4, 3, 2, 1]`)

## Why is it important?
- Makes `searching faster` (e.g., Binary Search needs sorted input)
- Helps in `data organization` (e.g., leaderboard, ranking)
- Used in many `real-world applications` (e.g., databases, UI lists, scheduling)

## Key Properties of Soring Algorithm
| Property             | Meaning                                                       |
| -------------------- | ------------------------------------------------------------- |
| **Time Complexity**  | How fast it sorts (best/average/worst case)                   |
| **Space Complexity** | Extra memory needed (in-place or not)                         |
| **Stability**        | Keeps relative order of equal elements (good for linked data) |
| **In-place**         | Sorts without using extra array memory                        |
| **Comparison-based** | Sorts by comparing elements (e.g., if `a > b`)                |

## Sorting Algoritms
| Name             | Time Complexity | In-Place | Stable? |
| ---------------- | --------------- | -------- | ------- |
| Bubble Sort      | O(n²)           | ✅        | ✅       |
| Selection Sort   | O(n²)           | ✅        | ❌       |
| Insertion Sort   | O(n²)           | ✅        | ✅       |
| Merge Sort       | O(n log n)      | ❌        | ✅       |
| Quick Sort       | O(n log n) avg  | ✅        | ❌       |
| Heap Sort        | O(n log n)      | ✅        | ❌       |
| Radix / Counting | O(n) (special)  | ❌        | ✅       |
