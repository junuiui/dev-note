// Find the M coin for N amount of money

/*
💰 Problem: Greedy Coin Change
You are given:
    An array coins[] of M coin denominations (all positive integers).
    An integer N representing the amount of money you need to make.

Your goal is to:
    Find the minimum number of coins needed to make exactly N using the given coin denominations.
    You can use unlimited coins of each denomination.

Constraint:
    Use a Greedy approach, i.e., always pick the largest coin possible first.

🧠 Input:
coins = [1, 2, 5, 10, 20, 50, 100]
N = 93
✅ Output:
Minimum coins needed: 5
Coins used: [50, 20, 20, 2, 1]
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100};
    int N = 93;
    int remaining = N;

    vector<int> coinsUsed(coins.size(), 0);
    int result = 0;

    // Greedy approach: use largest coins first
    for (int i = coins.size() - 1; i >= 0; i--) {
        int count = remaining / coins[i];
        if (count > 0) {
            coinsUsed[i] = count;
            result += count;
            remaining -= count * coins[i];
        }
    }

    // Build result list
    vector<int> coinsResult;
    for (int i = coins.size() - 1; i >= 0; i--) {
        for (int j = 0; j < coinsUsed[i]; j++) {
            coinsResult.push_back(coins[i]);
        }
    }

    // Print result
    cout << "Coins used: [";
    for (int i = 0; i < coinsResult.size(); i++) {
        cout << coinsResult[i];
        if (i != coinsResult.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Minimum coins needed: " << result << endl;
    return 0;
}