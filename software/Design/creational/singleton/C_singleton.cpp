#include <iostream>
#include <algorithm>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {
        cout << "Singleton Instance Created" << endl;
    }

public:
    // delete copy constructor & assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void show() {
        cout << "This is the Singleton instance!" << endl;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* a = Singleton::getInstance();
    a->show();

    Singleton* b = Singleton::getInstance();
    b->show();

    // Check if they point to the same address
    cout << "a: " << a << ", b: " << b << endl;

    return 0;
}