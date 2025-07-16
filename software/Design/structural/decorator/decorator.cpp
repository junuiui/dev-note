#include <iostream>
#include <memory>

using namespace std;

// Component
class Coffee {
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
    virtual ~Coffee() = default;
};

// Concrete Component
class BasicCoffee : public Coffee {
public:
    string getDescription() override {
        return "Basic Coffee";
    }

    double cost() override {
        return 2.0;
    }
};

// Decorator
class CoffeeDecorator : public Coffee {
protected:
    unique_ptr<Coffee> coffee;
public:
    CoffeeDecorator(unique_ptr<Coffee> c) : coffee(move(c)) {};
};

// ConcreteDecorator
class Milk : public CoffeeDecorator {
public:
    Milk(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}

    string getDescription() override {
        return coffee->getDescription() + " + Milk";
    }

    double cost() override {
        return coffee->cost() + 0.5;
    }
};

class Whip : public CoffeeDecorator {
public:
    Whip(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}

    string getDescription() override {
        return coffee->getDescription() + " + Whip";
    }

    double cost() override {
        return coffee->cost() + 0.7;
    }

};

// ====================
int main() {
    unique_ptr<Coffee> order = make_unique<BasicCoffee>();
    order = make_unique<Milk>(move(order));
    order = make_unique<Whip>(move(order));

    cout << "Order: " << order->getDescription() << endl;
    cout << "Total Cost: $" << order->cost() << endl;
    return 0;
}