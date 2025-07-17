Strategy Pattern
==
## What is?
- Strategy Pattern은 행동(algorithm)을 캡슐화해서 서로 교체 가능하게 만들고, 객체가 사용할 알고리즘을 runtime에 선택할 수 있게 해주는 패턴

## Why use?
- `Algorithm` / `Logic` 이 자주 바뀌거나, 여러 변형이 있을 때
- `if-else` 혹은 `switch` 문이 길어지는 것을 피하고 싶을 때
- 새로운 전략이 생기더라도 **기존 코드 수정 없이 확장** 가능하게 하기 위해

## Example
- 예를 들어 `TextEditor` 앱이 있는데, 사용자가 선택한 언어에 따라 다른 맞춤법 검사기를 사용해야 함

- 구조
    ```
    +----------------+      +---------------------+
    |   Context      | ---> |Strategy (interface) |
    +----------------+      +---------------------+
            |                        ^
            v                        |
    +------------------+     +---------------------+
    |ConcreteStrategyA |     |  ConcreteStrategyB  |
    +------------------+     +---------------------+

    ```

check [strategy.cpp](strategy.cpp)

## Questions
- "if-else가 많아지는 구조를 어떻게 개선하겠어요?"
- "사용자가 동적으로 전략(알고리즘)을 선택해야 할 때 어떻게 설계하겠어요?"
- "OCP(개방-폐쇄 원칙)를 지키려면 어떻게 해야 할까요?"