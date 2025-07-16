Adapter 
==
## Adapter Pattern?
- 서로 호환되지 않는 인터페이스를 연결해주는 패턴
- 기존 코드를 변경하지 않고 새 코드에 맞게 중간에 `통역`역할을 함
- 비유:
    - 한국 콘센트 (220V) -- 미국 충전기 (110V) => 중간에 애덥터를 껴서 둘이 연결 시킴

## When to use?
- 키존 코드(legacy)가 우리가 원하는 interface와 다를 때
- Library나 API를 우리가 쓰기 편하게 감싸고 싶을 때

## Example
- Scenario
    1. 우리가 쓰는 코드는 `Target` interface만 인식
    2. 그런데 외부에서 받은 class는 `Adaptee`
    3. 그 사이를 `Adapter`가 연결해 줌
- Chec [adapter.cpp](adapter.cpp)

## Summary
| 구성 요소     | 역할                    |
| --------- | --------------------- |
| `Target`  | 우리가 기대하는 인터페이스        |
| `Adaptee` | 외부 코드 / 호환되지 않는 인터페이스 |
| `Adapter` | 중간에서 번역/호환시켜주는 클래스    |

## 실무
- C++ STL 또는 OpenGL, SDL, DirectX와 같은 라이브러리 감쌀 때
- 다른 팀/회사 API를 내부 표준에 맞게 감쌀 때
- 테스트할 때 mock 객체로 교체 용이하게 만들 때