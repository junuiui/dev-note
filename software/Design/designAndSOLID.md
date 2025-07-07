Design
=
## What is?
- "코드를 작성하기 전에 전체 구조와 흐름을 먼저 설계하는 일"

## Why do we need?
| 이유      | 설명                     |
| ------- | ---------------------- |
| 유지보수 용이 | 기능 추가, 버그 수정이 쉬움       |
| 확장성 확보  | 새 기능을 넣을 때 최소한의 변경만 필요 |
| 협업 가능   | 역할과 책임이 명확하므로 분업 가능    |
| 성능 향상   | 구조적으로 효율적인 처리 가능       |

---
---
---
# Solid 원칙
- 각 원칙은 클래스, 모듈, 함수 등을 잘 분리하고 재사용하기 쉽게 만들어 줘.

## S - Single Responsibility Principle (단일 책임 원칙)
- 하나의 클래스는 하나의 책임만 가져야 한다
- 하나의 변경 이유만 존재해야 한다

- Example)
    ```
    // ❌
    class Report {
    public:
        void calculate() { /* logic */ }
        void print() { /* output to printer */ }
    };

    // ✅
    class ReportCalculator {
    public:
        void calculate() { /* logic */ }
    };

    class ReportPrinter {
    public:
        void print() { /* output */ }
    };
    ```

## O - Open/Closed Principle (개방/폐쇄 원칙)
- `확장`에는 열려 있고, `수정`에는 닫혀 있어야 한다
- 기존 코드를 건드리지 않고도 기능을 추가할 수 있어야 함

    ```
    // ❌ if-else로 모든 로직 처리
    double getArea(Shape* s) {
        if (s->type == "Circle") ...
        if (s->type == "Square") ...
    }

    // ✅ 다형성으로 확장
    class Shape {
    public:
        virtual double getArea() = 0;
    };

    class Circle : public Shape {
        double getArea() override { return ...; }
    };

    class Square : public Shape {
        double getArea() override { return ...; }
    };
    ```

## L - Liskov Substitution Principle
- 자식 클래스는 언제나 부모 클래스의 자리를 대체할 수 있어야 함
- 기능이 깨지지 않아야 함

    ```
    class Bird {
    public:
        virtual void fly() = 0;
    };

    class Sparrow : public Bird {
        void fly() override { /* flies */ }
    };

    // ❌ Penguin : Bird → Penguin can't fly
    // 펭귄은 날 수 없으나 모든 bird 가 날 수 있다고 해놓으면 펭귄도 날 수 있게됨. 그걸 방지.
    // 이럴 땐 fly가 없는 추상 클래스로 분리 필요!
    ```

## I - Interface Segregation Principle
- 많은 기능을 담은 인터페이스 하나보다는, 작은 인터페이스 여러 개가 낫다
- 필요 없는 기능은 구현하지 않도록 하는게 핵심

    ```
    // ❌ 하나의 인터페이스에 너무 많은 기능
    class Machine {
        virtual void print() = 0;
        virtual void scan() = 0;
        virtual void fax() = 0;
    };

    // ✅ 각 기능별 인터페이스 분리
    class Printer {
        virtual void print() = 0;
    };

    class Scanner {
        virtual void scan() = 0;
    };
    ```

## D - Dependency Inversion Principle
- 상위 모듈은 하위 모듈에 의존하면 안된다
- 둘 다 추상화에 의존 해야 한다
- 예) 핸드폰 앱이 특정 제조사 충전기에만 작동됨
    - 좋은 설계: 핸드폰 앱이 "충전기" 라는 공통 인터페이스만 알면, 어떤 브랜드 충전도 쓸 수 있게 해야함

    ```
    ❌ Bad Example
    class Keyboard {
    public:
        void input() {
            cout << "Typing on physical keyboard" << endl;
        }
    };

    class Computer {
    private:
        Keyboard keyboard;  // ❌ Low-level class에 직접 의존

    public:
        void work() {
            keyboard.input();
        }
    };

    Problem:
        1. Computer는 Keyboard에 강하게 의존
        2. 만약 Keyboard의 타입을 바꾸고 싶다면 Computer 클래스도 수정해야 함
    ```

    ```
    // ✅ 추상화된 인터페이스
    class IInputDevice {
    public:
        virtual void input() = 0;
        virtual ~IInputDevice() {}
    };

    // ✅ 저수준 구현 1
    class Keyboard : public IInputDevice {
    public:
        void input() override {
            cout << "Typing on physical keyboard" << endl;
        }
    };

    // ✅ 저수준 구현 2
    class TouchscreenKeyboard : public IInputDevice {
    public:
        void input() override {
            cout << "Typing on touchscreen" << endl;
        }
    };

    // ✅ 고수준 모듈이 추상화에만 의존
    class Computer {
    private:
        IInputDevice* inputDevice;

    public:
        Computer(IInputDevice* device) : inputDevice(device) {}

        void work() {
            inputDevice->input();  // 어떤 키보드든 상관 없음
        }
    };

    ```

    ```
    int main() {
        Keyboard keyboard;
        Computer pc(&keyboard);
        pc.work();

        TouchscreenKeyboard ts;
        Computer tablet(&ts);
        tablet.work();

        return 0;
    }
    ```

## Summary
| 원칙 | 의미               | 효과       |
| -- | ---------------- | -------- |
| S  | 한 클래스 = 하나의 책임   | 유지보수 쉬움  |
| O  | 수정 X, 확장 O       | 안전한 확장   |
| L  | 부모 자리에 자식이 와도 OK | 일관된 동작   |
| I  | 인터페이스는 작게 쪼개라    | 불필요 구현 X |
| D  | 추상화에 의존          | 유연한 구조   |
