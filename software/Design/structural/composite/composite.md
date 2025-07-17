Composite Pattern
==
## What is?
- 부분-전체 계층 구조를 동일하게 다루기 위한 Design Pattern
    - 즉, 단일 객체(leaf)와 복합 객체(composite)를 같은 방식으로 처리할 수 있게 해줌

## When to use?
- 폴더 안에 파일 & 폴더가 있는 `file system`
- 부서 안에 팀, 팀 안에 직원이 있는 회사 조직도
- GUI 요소에서 Button, Pannel, 창 등이 계층 구조로 구성될 때

## 구조
```
Component (인터페이스)
├── Leaf (단일 요소)
└── Composite (여러 요소를 포함할 수 있는 복합 요소)
```

## Example)
- check [composite.cpp](composite.cpp)

## Questions
| 질문         | 핵심 포인트                                     |
| ---------- | ------------------------------------------ |
| 왜 써야 해?    | 클라이언트 코드가 **leaf와 composite를 구분 없이 처리** 가능 |
| OCP 원칙 지킴? | 새로운 부서나 역할이 생겨도 기존 구조는 건드리지 않음             |
| 실제 예시?     | 파일 시스템, UI 위젯 계층, 군대 조직도 등                 |
