// deque.cpp
#include <iostream>
#include <deque>
#include <vector>

// ----------- STL deque usage -------------
void stlDequeDemo() {
    std::deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(40);

    std::cout << "STL Deque:\n";
    std::cout << "Front: " << dq.front() << "\n"; // 40
    std::cout << "Back: " << dq.back() << "\n";   // 30

    dq.pop_front();
    dq.pop_back();

    std::cout << "After popping front and back:\n";
    std::cout << "Front: " << dq.front() << "\n"; // 20
    std::cout << "Back: " << dq.back() << "\n";   // 10

    std::cout << "Remaining elements:\n";
    while (!dq.empty()) {
        std::cout << dq.front() << " ";
        dq.pop_front();
    }
    std::cout << "\n\n";
}

// ----------- Custom deque using vector -------------
class MyDeque {
private:
    std::vector<int> data;
    int left = 0, right = -1;

public:
    void push_back(int x) {
        data.push_back(x);
        right++;
    }

    void push_front(int x) {
        data.insert(data.begin() + left, x);
        right++;
    }

    void pop_back() {
        if (!empty()) {
            data.pop_back();
            right--;
        } else {
            std::cerr << "Deque is empty. Cannot pop_back.\n";
        }
    }

    void pop_front() {
        if (!empty()) {
            data.erase(data.begin() + left);
            right--;
        } else {
            std::cerr << "Deque is empty. Cannot pop_front.\n";
        }
    }

    int front() const {
        if (!empty()) return data[left];
        std::cerr << "Deque is empty. No front.\n";
        return -1;
    }

    int back() const {
        if (!empty()) return data[right];
        std::cerr << "Deque is empty. No back.\n";
        return -1;
    }

    bool empty() const {
        return data.empty();
    }

    int size() const {
        return (int)data.size();
    }
};

void customDequeDemo() {
    MyDeque dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);
    dq.push_front(40);

    std::cout << "Custom Deque:\n";
    std::cout << "Front: " << dq.front() << "\n"; // 40
    std::cout << "Back: " << dq.back() << "\n";   // 30

    dq.pop_front();
    dq.pop_back();

    std::cout << "After popping front and back:\n";
    std::cout << "Front: " << dq.front() << "\n"; // 20
    std::cout << "Back: " << dq.back() << "\n";   // 10

    std::cout << "Remaining elements:\n";
    while (!dq.empty()) {
        std::cout << dq.front() << " ";
        dq.pop_front();
    }
    std::cout << "\n";
}

// ------------------ main ------------------

int main() {
    stlDequeDemo();
    customDequeDemo();
    return 0;
}

/*
Output
-----------------
STL Deque:
Front: 40
Back: 30
After popping front and back:
Front: 20
Back: 10
Remaining elements:
20 10 

Custom Deque:
Front: 40
Back: 30
After popping front and back:
Front: 20
Back: 10
Remaining elements:
20 10 
*/