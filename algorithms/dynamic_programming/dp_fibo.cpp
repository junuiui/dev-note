/*
Problem: Fibonacci Number (DP)
The Fibonacci sequence is defined as:
    F(0) = 0  
    F(1) = 1  
    F(n) = F(n - 1) + F(n - 2)  for n ≥ 2

🧠 Your task:
    Write a function that returns the n-th Fibonacci number using Dynamic Programming.

Input
    An integer n (0 ≤ n ≤ 45)

Output
    Return the nth Fibonacci number
*/

#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 10;
    vector<int> fibo(n + 1, 0); // to include fibo[n]

    for (int i = 0; i <= n; i++) {
        if (i < 2) fibo[i] = i;
        else fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    cout << "Fibonacci(" << n << ") = " << fibo[n] << endl;

    // Optional: Print full sequence
    cout << "Sequence: [";
    for (int i = 0; i <= n; i++) {
        cout << fibo[i];
        if (i != n) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}