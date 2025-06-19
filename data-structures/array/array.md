# Array 

## What is?
Collection of elements stored in **contiguous memory locations**.
Allowing **random access** to elements using an **index**.

## Static Array
- Fixed size at compile time
- Declaration: `int arr[5];`
- Stored in continuous memory blocks 

### Advantages
- O(1) access time
- Cache-friendly due to memory locality

### Disadvantage
- Cannot change size
- Insertion and deletion are O(n) becuase of shifting

---

## Dynamic Array
- Can grow/shrink at runtime
- `std::vector` in c++ (cpp).
- Internally resizes by allocating a large array and copying elements.

See [array_ex.cpp](code/array_ex.cpp) for C++ example.