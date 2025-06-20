// singly linked list
#include <iostream>

/**
 * Node Struct
 */
struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {};
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {};
    SinglyLinkedList(Node* start) : head(start) {};

    ~SinglyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * Insert first (changing head)
     */
    void pushFront(int val){
        Node* newNode = new Node(val);

        newNode->next = head;   // set new Node to be front of head
        head = newNode; // set new node to be the new head
    }

    void pushBack(int val){
        Node* newNode = new Node(val);

        // if head == nullptr
        if (!head) {
            head = newNode;
            return;
        }

        Node* curr = head;

        // while curr->next is NOT nullptr
        while(curr->next) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void deleteValue(int val){
        if (!head) return;
        if (head->value == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->value != val) {
            curr = curr->next;
        }

        if (curr->next) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    bool search(int val) {
        Node* curr = head;
        while (curr) {
            if (curr->value == val) return true;
            curr = curr->next;
        }
        return false;
    }

    void print() {
        Node* curr = head;
        std::cout << "Linked List: ";
        while (curr) {
            std::cout << curr->value << " -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    list.pushBack(2);
    list.pushBack(3);
    list.pushFront(1);
    list.pushBack(4);
    list.print();

    std::cout << "\nDeleting 20...\n";
    list.deleteValue(3);
    list.print();

    std::cout << "Search 10? " << (list.search(10) ? "Found" : "Not Found") << "\n";
    std::cout << "Search 100? " << (list.search(100) ? "Found" : "Not Found") << "\n";

    return 0;
}

/*
Linked List: 1 -> 2 -> 3 -> 4 -> NULL

Deleting 20...
Linked List: 1 -> 2 -> 4 -> NULL
Search 10? Not Found
Search 100? Not Found
*/