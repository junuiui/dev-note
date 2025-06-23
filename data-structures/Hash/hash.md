Hashing
======
# What is?
- Techenique used to map data to a fixed-size value, usually an index, using a hash function
- In data structure, it's used to:
    - Quickly access or insert data
    - Avoid linear searches

# Core concept
- Hash Table
    - Stores `key`-`value` pairs
    - Uses a `hash function` to compute an index for each key
    - Handles collisions (when multiple keys hash to the same index)
    ```
    Key       →  Hash Function → Index → Stored in Array
    "apple"   →  hash("apple") →   3   → table[3] = "apple"
    ```

# Common Hash-Based Containers in C++
| Container            | Description                         |
| -------------------- | ----------------------------------- |
| `std::unordered_map` | Key-value pair, average O(1) access |
| `std::unordered_set` | Unique values, fast existence check |

# Operations Time Complexity
| Operation            | Average Case | Worst Case | Notes                                  |
| -------------------- | ------------ | ---------- | -------------------------------------- |
| `insert()`           | O(1)         | O(n)       | Rare worst case due to hash collisions |
| `erase()`            | O(1)         | O(n)       | Same as above                          |
| `find()` / `count()` | O(1)         | O(n)       | Checks if a key exists                 |
| `[]` (operator)      | O(1)         | O(n)       | Creates key if it doesn’t exist        |
| `rehash()`           | O(n)         | O(n)       | When resizing table internally         |
| `Iteration`            | O(n)         | O(n)       | Linear through internal buckets        |


# Benefits
| Feature       | Advantage                       |
| ------------- | ------------------------------- |
| `Fast Lookup`   | O(1) average-case               |
| `Flexible Keys` | Can use strings, custom objects |
| `Easy to Use`   | Built-in STL support            |

# Example Usage
- Count frequency of elements → unordered_map
- Detect duplicates → unordered_set
- Caching (like LRU)
- Hashing + 2-pointer → Solve 2-sum problem in O(n)
- Used in hashing-based sliding window problems

## Code Example
See [hash.cpp](hash.cpp) for C++ example.
