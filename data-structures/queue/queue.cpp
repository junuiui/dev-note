// queue.cpp
#include <iostream>
#include <vector>

class MyQueue {
private:
    std::vector<int> data;
    int frontIndex;

public:
    MyQueue() : frontIndex(0) {}

    void enqueue(int x) {
        data.push_back(x);
    }

    void dequeue() {
        if (!empty()) {
            frontIndex++;
            if (frontIndex > 50) { // arbitrary threshold
                data.erase(data.begin(), data.begin() + frontIndex);
                frontIndex = 0;
            }
        } else {
            std::cerr << "Queue is empty, cannot dequeue\n";
        }
    }

    int front() const {
        if (!empty()) {
            return data[frontIndex];
        } else {
            std::cerr << "Queue is empty, no front element\n";
            return -1; // or throw exception
        }
    }

    bool empty() const {
        return frontIndex >= (int)data.size();
    }

    int size() const {
        return (int)data.size() - frontIndex;
    }
};

int main() {

    std::cout << "Use of <queue>\n";
    std::queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.front() << "\n"; // 10

    q.pop();
    std::cout << "Front element after pop: " << q.front() << "\n"; // 20

    if (q.empty()) {
        std::cout << "Queue is empty\n";
    } else {
        std::cout << "Queue is not empty\n";
    }

    std::cout << "\nCustom Queue\n"; 
    MyQueue mq;

    mq.enqueue(10);
    mq.enqueue(20);
    mq.enqueue(30);

    std::cout << "Front element: " << mq.front() << "\n"; // 10

    mq.dequeue();
    std::cout << "Front element after dequeue: " << mq.front() << "\n"; // 20

    std::cout << "Queue size: " << mq.size() << "\n";

    while (!mq.empty()) {
        std::cout << "Dequeuing: " << mq.front() << "\n";
        mq.dequeue();
    }

    std::cout << "Queue empty? " << (mq.empty() ? "Yes" : "No") << "\n";

    return 0;
}

/*
Output
-----------------
Use of <queue>
Front element: 10
Front element after pop: 20
Queue is not empty

Custom Queue
Front element: 10
Front element after dequeue: 20
Queue size: 2
Dequeuing: 20
Dequeuing: 30
Queue empty? Yes
*/
