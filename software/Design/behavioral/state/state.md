State
==
## What is?
- 객체의 상탵에 따라 행동이 바뀌어야 할 때, 상태를 클래스로 분리해서 객체가 행동을 상태에게 위임하도록 만드는 패턴

## Why use?
- 일반적으로 상태가 많아질수록 `if`나 `switch`문이 늘어나고 코드가 엉망이 되는데, State 패턴을 쓰면 각 상태를 클래스로 나눠서 SRP (Single Responsibility Principle)을 지킬 수 있음
```
// 나쁜 예
if (state == STATE_LOCKED) {
    if (event == "push") print("Locked");
    else if (event == "coin") state = STATE_UNLOCKED;
}
else if (state == STATE_UNLOCKED) {
    if (event == "push") {
        print("Open");
        state = STATE_LOCKED;
    }
}
```

## 구조
```
Context → State (interface)
               ↳ ConcreteStateA
               ↳ ConcreteStateB
```
- Context: 현재 상태를 가진 주체. 상태 변경을 여기서 함
- State: 인터페이스. 상태별 행동 정의
- ConcreteState: 각 상태마다 고유한 행동 정의

## Where to use?
| 사용 예시                 | 설명                   |
| --------------------- | -------------------- |
| 자판기 / 교통카드 시스템        | 상태에 따라 행동 다르게        |
| TCP Connection        | 연결 전/후 상태마다 로직 다름    |
| 게임 상태 (대기, 공격, 죽음 등)  | Player가 상태에 따라 다른 액션 |
| 워크플로우 처리 (e.g. 주문 처리) | 상태 전이에 따라 처리 분리      |
| 백엔드 비즈니스 로직           | 결제 상태, 배송 상태 등       |

## 핵심
- 상태가 많고, 각 상태마다 로직이 다르면 State 패턴을 써라!
- if/else가 길어지는 건 신호탄
- 인터뷰에서 “코드가 상태에 따라 바뀌어야 해요” → State 패턴 떠올리기


