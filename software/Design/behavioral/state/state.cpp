#include <iostream>
#include <memory>

using namespace std;

// State Interface
class State {
public:
    virtual void insertCoin() = 0;
    virtual void pushButton() = 0;
    virtual ~State() {}
};

// Context
class VendingMachine {
private:
    State* currentState;
public:
    void setState(State* s) {
        currentState = s;
    }

    void insertCoin() {
        currentState->insertCoin();
    }

    void pushButton() {
        currentState->pushButton();
    }
};

// Concrete
class NoCoinState : public State {
    VendingMachine* machine;

public:
    NoCoinState(VendingMachine* m) : machine(m) {}

    void insertCoin() override {
        cout << "Coin inserted!\n";
        machine->setState(new HasCoinState(machine));
    }

    void pushButton() override {
        cout << "Insert coin first!\n";
    }
};

class HasCoinState : public State {
    VendingMachine* machine;

public:
    HasCoinState(VendingMachine* m) : machine(m) {}

    void insertCoin() override {
        cout << "Already have coin!\n";
    }

    void pushButton() override {
        cout << "Item dispensed!\n";
        machine->setState(new NoCoinState(machine));
    }
};
