#include <iostream>

// 기존 코드
class Target {
public:
    virtual void request() {
        std::cout << "Target: Default request\n";
    }
    virtual ~Target() = default;
};

// 우리가 바꾸기 어려운 외부 코드 (legacy, third party)
class Adaptee {
public:
    void specificRequest() {
        std::cout << "Adaptee: Specific request\n";
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee;
public:
    Adapter(Adaptee* a) : adaptee(a) {}

    void request() override {
        // Call Adaptee instead of Target request
        adaptee->specificRequest();
    }
};

// =======================
int main() {
    Target* target = new Target();
    target->request();  // Target 방식 호출

    Adaptee* legacy = new Adaptee();
    Target* adapted = new Adapter(legacy);
    adapted->request(); // 내부적으로 specificRequest() 호출

    delete target;
    delete legacy;
    delete adapted;

    return 0;
}

