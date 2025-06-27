Permutations
=
## What is?
- Arrangement of elements in all possible orders
- 순서를 고려해서 원소들을 나열하는 모든 경우
    - Example)
        - All Combinations of ``1, 2, 3`` 
            - `1, 2, 3`
            - `1, 3, 2`
            - `2, 1, 3`
            - `2, 3, 1`
            - `3, 1, 2`
            - `3, 2, 1`
                = `6` (= `3!`) possible combinations

### Equation
- When $0 \leq k \leq n$, the number of **permutations** of $k$ items chosen from $n$ is:
    $$
    nP_k = \frac{n!}{(n - k)!}
    $$


        
Combinations
=
## What is?
- 순서를 고려하지 않고, 원소들을 고르는 모든 경우
    - Example)
        - Combinations of 2 of ``1, 2, 3`` 
        - `1, 2`
        - `1, 3`
        - `2, 3`
            = `3` (= `3C2`) possible combinations

### Equation
- When $0 \leq k \leq n$, the number of **combinations** of $k$ items chosen from $n$ is:
$$
nC_k = \frac{n!}{k!(n - k)!}
$$

## Relationship
$$
nP_k = nC_k \cdot k!
$$

## 핵심 차이점
| 구분      | Permutation (순열)  | Combination (조합)   |
| ------- | ----------------- | ------------------ |
| 순서      | 고려함               | 고려하지 않음            |
| 중복된 결과  | `[1,2]` ≠ `[2,1]` | `[1,2]` == `[2,1]` |
| 개수      | n!                | nCr                |
| 주요 알고리즘 | 백트래킹, DFS         | 백트래킹, DFS          |

## 예시
| 문제                  | 순열 or 조합?      | 이유         |
| ------------------- | -------------- | ---------- |
| 숫자들을 전부 다 나열하기      | 순열             | 순서 중요      |
| 로또 번호 고르기           | 조합             | 순서 무관      |
| 암호 만들기              | 조합 (조건에 따라 다름) | 보통 순서 필요 X |
| Travelling Salesman | 순열             | 방문 순서 중요   |





