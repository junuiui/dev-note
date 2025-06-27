BackTracking
=
## What is?
- Systematic trial-and-error approach for solving problems incrementally, by trying partial solutions and then abandoning them ("Backtrack") if they don't lead to a valid solution.
    - Explore all possibilities (like brute force)
    - if a choice **leads to invalid state**, go back ("backtrack")
    - Normally implemented using recursion

## Typical Structure
    void backtrack(State current) {
        if (isGoal(current)) {
            process(current);
            return;
        }

        for (choice in choices) {
            if (isValid(choice)) {
                makeChoice(current, choice);
                backtrack(current);
                undoChoice(current, choice); // backtrack
            }
        }
    }

## 대표 문제 유형
| 유형               | 예시 문제                          |
| ---------------- | ------------------------------ |
| 조합 (Combination) | nCr, Subsets                   |
| 순열 (Permutation) | 모든 순열, 암호 만들기                  |
| 조건 탐색            | N-Queen, Sudoku                |
| 문자열 생성           | 괄호 생성, Palindrome Partitioning |


