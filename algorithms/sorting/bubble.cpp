/*
Bubble Sort

- 옆에 있는 두 값을 비교하고 잘못된 순서면 swap
- 끝으로 밀어냄

[5, 3, 8, 4]
→ 비교 5 > 3 → 교환 → [3, 5, 8, 4]
→ 비교 5 > 8 → OK
→ 비교 8 > 4 → 교환 → [3, 5, 4, 8] ← 큰 수가 뒤로 밀림
*/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            // Compare and swap
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps, array is already sorted
        if (!swapped) break;
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};

    cout << "Before sorting: ";
    printArray(arr);

    bubbleSort(arr);

    cout << "After sorting: ";
    printArray(arr);

    return 0;
}

/*
| Case       | Time                                   |
| ---------- | -------------------------------------- |
| Best Case  | O(n)     ← Already sorted, 1 pass only |
| Average    | O(n²)                                  |
| Worst Case | O(n²)    ← 완전히 역순일 때             |

*/