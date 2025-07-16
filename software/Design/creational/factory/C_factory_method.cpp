#include <iostream>
#include <memory>
using namespace std;

// Product interface
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

// Concrete Products
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle\n";
    }
};

// Factory interface
class ShapeFactory {
public:
    virtual unique_ptr<Shape> createShape() = 0;
    virtual ~ShapeFactory() = default;
};

// Concrete Factories
class CircleFactory : public ShapeFactory {
public:
    unique_ptr<Shape> createShape() override {
        return make_unique<Circle>();
    }
};

class RectangleFactory : public ShapeFactory {
public:
    unique_ptr<Shape> createShape() override {
        return make_unique<Rectangle>();
    }
};

int main() {
    unique_ptr<ShapeFactory> factory1 = make_unique<CircleFactory>();
    auto shape1 = factory1->createShape();
    shape1->draw(); // Drawing Circle

    unique_ptr<ShapeFactory> factory2 = make_unique<RectangleFactory>();
    auto shape2 = factory2->createShape();
    shape2->draw(); // Drawing Rectangle

    return 0;
}
