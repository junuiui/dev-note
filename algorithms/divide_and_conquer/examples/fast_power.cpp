/*
Given two integers a and b,
compute a^b (a to the power of b),
using a divide and conquer approach.

핵심 아이디어: a^b = a^(b/2) * a^(b/2)
    짝수일 때:
        a^b = (a^(b/2))^2
    
    홀수일 때:
        a^b = a * (a^(b/2))^2
*/

#include <iostream>
using namespace std;

long long fastPower(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    long long half = fastPower(a, b / 2);

    if (b % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}


int main() {
    int a = 2;
    int b = 10;

    cout << a << "^" << b << " = " << fastPower(a, b) << endl;
    return 0;
}

/*
Note:

                        a ^ 10
                    a ^ 5 * a ^ 5
        a (a ^ 2 * a ^ 2) * a (a ^ 2 * a ^ 2)

f(2, 10)
    f(2, 5) * f(2, 5)
        a * f(2, 2) * f(2, 2) * a * f(2, 2) * f(2, 2)


*/