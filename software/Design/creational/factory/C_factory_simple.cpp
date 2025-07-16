// Shape Factory Pattern

#include <iostream>
#include <memory>
using namespace std;

// Interface
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Rectangle\n";
    }
};

// Factory
class ShapeFactory {
public:
    static unique_ptr<Shape> createShape(const string& type) {
        if (type == "circle") return make_unique<Circle>();
        else if (type == "rectangle") return make_unique<Rectangle>();
        else return nullptr;
    }
};

// Client Side
int main() {
    auto shape1 = ShapeFactory::createShape("circle");
    shape1->draw(); // Drawing a Circle

    auto shape2 = ShapeFactory::createShape("rectangle");
    shape2->draw(); // Drawing a Rectangle

    return 0;
}