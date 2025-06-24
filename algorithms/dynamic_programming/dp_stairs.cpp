/*
🪜 Problem: Climbing Stairs
You are climbing a staircase.
It takes n steps to reach the top.
Each time, you can either:
climb 1 step, or
climb 2 steps.

🧠 Your task:
    Return the number of distinct ways you can climb to the top.

This is essentially:
    "In how many ways can you reach step n, taking 1 or 2 steps at a time?"

✅ Input
    An integer n (1 ≤ n ≤ 45)

✅ Output
    Return the total number of ways to reach the top.
*/

#include <vector>
#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5;
    cout << "Number of ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}