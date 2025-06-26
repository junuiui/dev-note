Searching
=
## What is?
- The process of finding the location of a target element in a collection of data (like an array or list).
- The goal is usually to **return the index** of the target, or determine if it **exists or not**.

## Types
1. ``Linear Search``
    - Concept
        - Check each element one by one from start to end
        - Works on unsorted/sorted data
    - Time Complexity
        | Case       | Time |
        | ---------- | ---- |
        | Best Case  | O(1) |
        | Worst Case | O(n) |
        | Space      | O(1) |
    - When to use?
        - Small input size
        - Data is *unsorted*
        - You do not need fast lookups

2. ``Binary Search``
    - Concept:
        - Divide and conquer method.
            - Only works on sorted arrays.
            - Repeatedly divide the search range in half:
            - Compare the middle element with the target
            - Go left or right depending on the result
    - Time Complexity
        | Case       | Time                          |
        | ---------- | ----------------------------- |
        | Best Case  | O(1)                          |
        | Worst Case | O(log n)                      |
        | Space      | O(1) or O(log n) if recursive |
    - When to use?
        - Data is sorted
        - fast lookup
        - Large datasets


