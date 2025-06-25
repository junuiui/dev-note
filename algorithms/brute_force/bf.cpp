// Problem: 모든 조합 구하기
// 설명:
// 1부터 N까지의 숫자 중에서 M개를 고르는 모든 조합을 구하자.
// (숫자는 오름차순, 중복 없이 고른다.)

// Input
// N = 4, M = 2

// Output (각 줄에 하나의 조합)
// 1 2  
// 1 3  
// 1 4  
// 2 3  
// 2 4  
// 3 4

#include <iostream>
#include <vector>

using namespace std;

int N = 4; // Can change
int M = 2; // Can change

vector<int> combination;

void dfs(int start) {
    // Base case
    if (combination.size() == M) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        combination.push_back(i);
        dfs(i + 1);            // 다음 숫자부터 탐색 (중복 방지)
        combination.pop_back();   // 백트래킹
    }
}

int main() {
    dfs(1); // Start from 1
    return 0;
}
