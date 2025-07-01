#include <iostream>

#include <vector>

using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();

    if (n <= 1) return;
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1; // left

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 3, 4, 1, 2};

    cout << "Before sorting: ";
    printArray(arr);

    insertionSort(arr);

    cout << "After sorting: ";
    printArray(arr);

    return 0;
}