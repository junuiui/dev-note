// Binary Search Example

/*
nums = {-5, -2, 0, 3, 7, 10, 15}

    target = 3
    output: True (found)

    target = 1
    output: False (Not Found)
*/
#include <vector>
#include <iostream>

using namespace std;

int binarySearch(const vector<int>& vec, int target) {
    if (vec.size() == 0) return -1;

    int low = 0;
    int high = vec.size()-1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (target == vec[mid]) return mid;
        else if (target < vec[mid]) high = mid - 1;
        else low = mid+1;
    }

    return -1;
}

bool find(const vector<int>& vec, int target) {

    int index = binarySearch(vec, target);
    return false;
}

int main() {
    vector<int> nums = {-5, -2, 0, 3, 7, 10, 15};
    int target = 3;

    int index = binarySearch(nums, target);
    cout << "Index of target: " << index << endl;

    return 0;
}