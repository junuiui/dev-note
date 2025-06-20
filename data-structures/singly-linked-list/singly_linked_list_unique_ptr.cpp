// singly_linked_list_smart.cpp
#include <iostream>
#include <memory>  // for std::unique_ptr

class Node {
public:
    int value;
    std::unique_ptr<Node> next;

    Node(int v) : value(v), next(nullptr) {}
};

class SinglyLinkedList {
private:
    std::unique_ptr<Node> head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void pushFront(int val) {
        auto newNode = std::make_unique<Node>(val);
        newNode->next = std::move(head);  // transfer ownership
        head = std::move(newNode);
    }

    void pushBack(int val) {
        auto newNode = std::make_unique<Node>(val);

        if (!head) {
            head = std::move(newNode);
            return;
        }

        Node* curr = head.get();  // raw pointer for traversal
        while (curr->next) {
            curr = curr->next.get();
        }
        curr->next = std::move(newNode);
    }

    void deleteValue(int val) {
        if (!head) return;

        if (head->value == val) {
            head = std::move(head->next);
            return;
        }

        Node* curr = head.get();
        while (curr->next && curr->next->value != val) {
            curr = curr->next.get();
        }

        if (curr->next && curr->next->value == val) {
            curr->next = std::move(curr->next->next);
        }
    }

    bool search(int val) const {
        Node* curr = head.get();
        while (curr) {
            if (curr->value == val) return true;
            curr = curr->next.get();
        }
        return false;
    }

    void print() const {
        Node* curr = head.get();
        std::cout << "Linked List: ";
        while (curr) {
            std::cout << curr->value << " -> ";
            curr = curr->next.get();
        }
        std::cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.pushBack(10);
    list.pushFront(5);
    list.pushBack(20);
    list.pushBack(30);

    list.print();

    list.deleteValue(20);
    list.print();

    std::cout << "Search 10? " << (list.search(10) ? "Found" : "Not Found") << "\n";
    std::cout << "Search 100? " << (list.search(100) ? "Found" : "Not Found") << "\n";

    return 0;
}
