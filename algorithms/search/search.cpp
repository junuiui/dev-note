#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

// Linear Search Using Loop
int getIndexLinearL(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) return i;
    }

    return -1;
}

int getIndexLinearR_helper(const vector<int>& vec, int target, int index) {
    if (index == vec.size()) return -1;
    if (vec[index] == target) return index;
    return getIndexLinearR_helper(vec, target, index + 1);
}

// Linear Search Using R
int getIndexLinearR(const vector<int>& vec, int target) {
    return getIndexLinearR_helper(vec, target, 0);
}

// Binary Search Using Loop
int getIndexBinaryL(const vector<int>& vec, int target){
    if (vec.size() == 0) return -1;

    int low = 0, high = vec.size()-1;

    while (low <= high) {
       int mid = (low + high) / 2;
       if (vec[mid] == target) return mid;
       else if (vec[mid] > target) high = mid - 1;
       else low = mid + 1; 
    }

    return -1;
}

// Binary Search Using Recursion
int getIndexBinaryR_helper(const vector<int>& vec, int target, int low, int high){
    if (vec.size() == 0) return -1;
    
    int mid = (low + high) / 2;
    if (vec[mid] == target) return mid;
    else if (vec[mid] > target) return getIndexBinaryR_helper(vec, target, low,  mid - 1);
    else return getIndexBinaryR_helper(vec, target, mid + 1, high); 
}

int getIndexBinaryR(const vector<int>& vec, int target){
    return getIndexBinaryR_helper(vec, target, 0, vec.size()-1);
}

int main() {
    vector<int> sorted = {-31,-7,10,15,18,20};
    vector<int> unsorted = {123,-23,14,5,11,1,9,-21};

    cout << "Testing 1: Linear Search Loop...";
    assert(getIndexLinearL(sorted, -7) == 1);
    assert(getIndexLinearL(unsorted, 1) == 5);
    cout << "\t ...PASSED\n";

    cout << "Testing 2: Linear Search Recursion...";
    assert(getIndexLinearR(sorted, -7) == 1);
    assert(getIndexLinearR(unsorted, 1) == 5);
    cout << "\t ...PASSED\n";

    cout << "Testing 3: Binary Search Loop...";
    assert(getIndexBinaryL(sorted, -7) == 1);
    cout << "\t ...PASSED\n";

    cout << "Testing 4: Binary Search Recursion...";
    assert(getIndexBinaryR(sorted, -7) == 1);
    cout << "\t ...PASSED\n";

    return 0;
}