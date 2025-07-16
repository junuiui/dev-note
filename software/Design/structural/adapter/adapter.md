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

