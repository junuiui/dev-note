Recursion (재귀)
=
## What is?
- Resursion is a technique where a function **calls itself** to solve a smaller version of the problem
- It can replace the loop

## 구성요소 (REQUIRED)
- Base Case (종료 조건)
    - 재귀를 멈추는 조건. 이게 없으면 무한 호출
- Recursive Case (자기 자신 호출)
    - 더 작은 문제로 쪼개서 자기 자신을 호출하는 부분

## Example: Factorial
```
int factorial(int n) {
    if (n == 0) return 1;       // base case
    return n * factorial(n-1);  // Recursive Case
}
```
- 흐름
    - factorial(3)
        1. 3 * factorial(2)
        2. 3 * (2 * factorial(1))
        3. 3 * (2 * (1 * factorial(0)))
        4. 3 * 2 * 1 * 1 = 6
        
## Call Stack
- 각 함수 호출은 ``stack frame``으로 저장됨 (``Last-In-First_Out``)
```
    factorial(3)
        factorial(2)
            factorial(1)
                factorial(0)
```
- factorial(0) 부터 차례로 값이 반환되면서 stack 이 줄어듦.

## Recursion vs Tail Recursion
| 구분      | 일반 재귀 (Recursion)   | 꼬리 재귀 (Tail Recursion)                     |
| ------- | ------------------- | ------------------------------------------ |
| 호출 후 작업 | 재귀 호출 뒤에 **작업이 남음** | 재귀 호출이 **마지막 작업**                          |
| 최적화 가능성 | 일반적으로 불가능           | 컴파일러가 최적화 가능 (TCO: Tail Call Optimization) |
| 메모리 사용  | Stack frame이 계속 쌓임  | Stack frame을 **재사용**할 수 있음                 |
| 속도      | 느릴 수 있음             | 더 빠를 수 있음 (지원되는 경우)                        |

