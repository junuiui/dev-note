# Set, Map, and Unordered Versions

## 1. `unordered_map` and `unordered_set`

- Implemented using **hash tables**
- Average-case: O(1) insert, search, erase
- Order is **not preserved**

## unordered_map

### What is it?

- An associative container that stores key-value pairs with **unique keys**.
- Implemented using a **hash table**.
- Does **not maintain order** of elements.

### Syntax

```cpp
std::unordered_map<KeyType, ValueType> map_name;

### Usage
```cpp
std::unordered_map<std::string, int> freq;
freq["apple"] = 2;
if (freq.count("apple")) { /* ... */ }

## set

### What is it?

- A container that stores **unique elements** in **sorted order**.
- Internally implemented using a **Red-Black Tree** (self-balancing BST).

### Syntax

```cpp
std::set<int> s;

### Usage

std::unordered_set<int> seen;
seen.insert(10);
if (seen.count(10)) { /* ... */ }

| Container       | Ordered | Unique | Key-Value | Avg Time (Insert/Search) |
| --------------- | ------- | ------ | --------- | ------------------------ |
| `set`           | O       | O      | X         | O(log n)                 |
| `unordered_set` | X       | O      | X         | O(1)                     |
| `map`           | O       | O      | O         | O(log n)                 |
| `unordered_map` | X       | O      | O         | O(1)                     |


