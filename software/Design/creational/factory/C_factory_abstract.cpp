/*
관련된 객체들을 묶어서 팩토리로 만들어주는 패턴
(서로 잘 맞는 객체들끼리 세트로 생성하고 싶을 때)

UI 테마
  - Light Theme
    - LightButton
    - LightCheckbox

  - Dark Theme
    - DarkButton
    - DarkCheckbox
*/

#include <iostream>
#include <memory>

using namespace std;

// Abstract Products
class Button { public: virtual void click() = 0; };
class Checkbox { public: virtual void toggle() = 0; };

// Concrete Products
class LightButton : public Button {
public: void click() override { cout << "Light Button Clicked\n"; }
};
class DarkButton : public Button {
public: void click() override { cout << "Dark Button Clicked\n"; }
};

class LightCheckbox : public Checkbox {
public: void toggle() override { cout << "Light Checkbox Toggled\n"; }
};
class DarkCheckbox : public Checkbox {
public: void toggle() override { cout << "Dark Checkbox Toggled\n"; }
};

// Abstract Factory
class UIFactory {
public:
    virtual unique_ptr<Button> createButton() = 0;
    virtual unique_ptr<Checkbox> createCheckbox() = 0;
};

// Concrete Factories
class LightUIFactory : public UIFactory {
public:
    unique_ptr<Button> createButton() override { return make_unique<LightButton>(); }
    unique_ptr<Checkbox> createCheckbox() override { return make_unique<LightCheckbox>(); }
};

class DarkUIFactory : public UIFactory {
public:
    unique_ptr<Button> createButton() override { return make_unique<DarkButton>(); }
    unique_ptr<Checkbox> createCheckbox() override { return make_unique<DarkCheckbox>(); }
};

int main() {
    unique_ptr<UIFactory> factory = make_unique<DarkUIFactory>();
    auto button = factory->createButton();
    auto checkbox = factory->createCheckbox();

    button->click();      // Dark Button Clicked
    checkbox->toggle();   // Dark Checkbox Toggled

    return 0;
}
