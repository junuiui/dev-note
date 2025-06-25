분할 정복 (Divide and Conquer)
=
## What is?
- 큰 문제를 작은 문제로 나눠서 풀고, 그 작은 문제들의 결과를 합쳐서 전체 문제를 해결하는 방식

## 기본 구조
    function solve(problem):
        if problem is small enough:
            return trivial solution

        divide problem into subproblems
        solve subproblems recursively
        combine results and return

## 대표적인 예시
| 알고리즘                          | 핵심 동작            |
| ----------------------------- | ---------------- |
| **Merge Sort**                | 배열을 나누고 정렬하며 병합  |
| **Quick Sort**                | 기준을 잡고 좌우로 나눠 정렬 |
| **Binary Search**             | 범위를 반으로 줄이며 탐색   |
| **Power Calculation (분할 정복)** | $a^b$ 계산 빠르게 하기  |

