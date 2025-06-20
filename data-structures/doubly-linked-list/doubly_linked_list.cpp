// doubly_linked_list.cpp
#include <iostream>

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int v) : value(v), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void pushFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;

        if (head) head->prev = newNode;
        head = newNode;

        if (!tail) tail = newNode;
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        newNode->prev = tail;

        if (tail) tail->next = newNode;
        tail = newNode;

        if (!head) head = newNode;
    }

    void deleteValue(int val) {
        Node* curr = head;

        while (curr && curr->value != val) {
            curr = curr->next;
        }

        if (!curr) return;

        if (curr->prev) curr->prev->next = curr->next;
        else head = curr->next;

        if (curr->next) curr->next->prev = curr->prev;
        else tail = curr->prev;

        delete curr;
    }

    void printForward() {
        Node* curr = head;
        std::cout << "Forward: ";
        while (curr) {
            std::cout << curr->value << " <-> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    void printBackward() {
        Node* curr = tail;
        std::cout << "Backward: ";
        while (curr) {
            std::cout << curr->value << " <-> ";
            curr = curr->prev;
        }
        std::cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushFront(5);
    list.pushBack(20);
    list.pushFront(1);

    list.printForward();   // 1 <-> 5 <-> 10 <-> 20
    list.printBackward();  // 20 <-> 10 <-> 5 <-> 1

    list.deleteValue(10);
    list.printForward();   // 1 <-> 5 <-> 20

    return 0;
}

/*
Output
Forward: 1 <-> 5 <-> 10 <-> 20 <-> NULL
Backward: 20 <-> 10 <-> 5 <-> 1 <-> NULL
Forward: 1 <-> 5 <-> 20 <-> NULL
*/