// stack.cpp
#include <iostream>
#include <stack>
#include <vector>

/**
 * Custom Stack
 */
class MyStack {
private:
    std::vector<int> data;

public:
    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        } else {
            std::cerr << "Stack is empty, cannot pop\n";
        }
    }

    int top() const {
        if (!data.empty()) {
            return data.back();
        } else {
            std::cerr << "Stack is empty, no top element\n";
            return -1; // or throw exception
        }
    }

    bool empty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }
};

int main() {

    // Use of <stack>
    std::stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Using <stack>\n";
    std::cout << "Stack top: " << s.top() << "\n"; // 30

    s.pop();
    std::cout << "Stack top after pop: " << s.top() << "\n"; // 20

    if (s.empty()) {
        std::cout << "Stack is empty\n";
    } else {
        std::cout << "Stack is not empty\n";
    }

    // Use of custom stack (vector version)
    MyStack ms;

    ms.push(10);
    ms.push(20);
    ms.push(30);

    std::cout << "\nUsing Custom Stack\n";
    std::cout << "Stack top: " << ms.top() << "\n";  // 30

    ms.pop();
    std::cout << "Stack top after pop: " << ms.top() << "\n";  // 20

    std::cout << "Stack size: " << ms.size() << "\n";

    while (!ms.empty()) {
        std::cout << "Popping: " << ms.top() << "\n";
        ms.pop();
    }

    std::cout << "Stack empty? " << (ms.empty() ? "Yes" : "No") << "\n";

    return 0;
}

/*
Output
-------------
Using <stack>
Stack top: 30
Stack top after pop: 20
Stack is not empty

Using Custom Stack
Stack top: 30
Stack top after pop: 20
Stack size: 2
Popping: 20
Popping: 10
Stack empty? Yes
*/