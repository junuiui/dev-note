# Deque (Double-Ended Queue)

## What is a Deque?

A **deque** (short for *double-ended queue*) is a linear data structure that allows:
- Insertion and deletion at **both front and back** in O(1) time.

---

## Common Operations

- `push_front(x)`: Add element to the front.
- `push_back(x)`: Add element to the back.
- `pop_front()`: Remove element from the front.
- `pop_back()`: Remove element from the back.
- `front()`: Access front element.
- `back()`: Access last element.
- `empty()`: Check if deque is empty.

---

## Time Complexity

| Operation      | Time |
|----------------|------|
| push_front     | O(1) |
| push_back      | O(1) |
| pop_front      | O(1) |
| pop_back       | O(1) |
| front / back   | O(1) |

---

## Code Example

See [deque.cpp](deque.cpp) for a C++ example using `std::deque`.
