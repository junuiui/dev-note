#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> data;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (data[parent] <= data[idx]) break;
            std::swap(data[parent], data[idx]);
            idx = parent;
        }
    }

    void heapifyDown(int idx) {
        int n = data.size();
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;

            if (left < n && data[left] < data[smallest]) smallest = left;
            if (right < n && data[right] < data[smallest]) smallest = right;

            if (smallest == idx) break;

            std::swap(data[idx], data[smallest]);
            idx = smallest;
        }
    }

public:
    void push(int val) {
        data.push_back(val);
        heapifyUp(data.size() - 1);
    }

    void pop() {
        if (data.empty()) return;
        data[0] = data.back();
        data.pop_back();
        heapifyDown(0);
    }

    int top() const {
        if (data.empty()) throw std::runtime_error("Heap is empty");
        return data[0];
    }

    bool empty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }
};

int main() {
    MinHeap heap;
    heap.push(30);
    heap.push(20);
    heap.push(15);
    heap.push(10);

    std::cout << "MinHeap top: " << heap.top() << "\n"; // 10

    heap.pop();

    std::cout << "MinHeap top after pop: " << heap.top() << "\n"; // 15

    return 0;
}

/* cpp PQ*/
// #include <iostream>
// #include <queue>
// #include <vector>

// int main() {
//     // Max Heap (default)
//     std::priority_queue<int> maxHeap;
//     maxHeap.push(10);
//     maxHeap.push(5);
//     maxHeap.push(20);

//     std::cout << "Max heap top: " << maxHeap.top() << "\n"; // 20

//     // Min Heap
//     std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
//     minHeap.push(10);
//     minHeap.push(5);
//     minHeap.push(20);

//     std::cout << "Min heap top: " << minHeap.top() << "\n"; // 5

//     return 0;
// }
