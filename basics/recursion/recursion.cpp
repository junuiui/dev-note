#include <iostream>
#include <string>

using namespace std;

string reverseString(const string& s) {
    // Base Case: empty string or single character
    if (s.length() <= 1) return s;

    // Recursive Case:
    return reverseString(s.substr(1)) + s[0];
}

int sumOfDigits(int n) {
    if (n <= 0) return n;
    return (n % 10) + sumOfDigits(n/10);
}

int sumOfDigitsTail(int n, int acc = 0) {
    if (n == 0) return acc;
    return sumOfDigitsTail(n / 10, acc + (n % 10));
}

int main() {

    string k = "abc de";
    
    cout << k << endl;
    cout << reverseString(k) << endl;

    cout << 1234 << endl;
    cout << sumOfDigits(1234) << endl;
    cout << sumOfDigitsTail(1234) << endl;

    return 0;
}