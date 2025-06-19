// pq.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional> // for std::greater

// ----------- STL Priority Queue Examples -------------
void stlPQDemo() {
    // Max-heap (default)
    std::priority_queue<int> maxPQ;
    maxPQ.push(5);
    maxPQ.push(1);
    maxPQ.push(10);

    std::cout << "Max-Heap Priority Queue:\n";
    while (!maxPQ.empty()) {
        std::cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    std::cout << "\n\n";

    // Min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
    minPQ.push(5);
    minPQ.push(1);
    minPQ.push(10);

    std::cout << "Min-Heap Priority Queue:\n";
    while (!minPQ.empty()) {
        std::cout << minPQ.top() << " ";
        minPQ.pop();
    }
    std::cout << "\n\n";
}

// ----------- Custom Min-Heap Implementation -------------
class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int l = left(index), r = right(index);
        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() const {
        if (!heap.empty()) return heap[0];
        std::cerr << "Heap is empty\n";
        return -1;
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

void customPQDemo() {
    MinHeap h;
    h.push(20);
    h.push(5);
    h.push(15);

    std::cout << "Custom Min-Heap:\n";
    while (!h.empty()) {
        std::cout << h.top() << " ";
        h.pop();
    }
    std::cout << "\n";
}

// ------------------- Main ---------------------
int main() {
    stlPQDemo();
    customPQDemo();
    return 0;
}

/*
output
--------------
Max-Heap Priority Queue:
10 5 1 

Min-Heap Priority Queue:
1 5 10 

Custom Min-Heap:
5 15 20 

*/