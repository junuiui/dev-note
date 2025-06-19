/**
 * Example code for Arrays
 */

#include <iostream>
#include <vector>

void printArray(const int* arr, int size);
void printArray(const std::vector<int>& arr);

int main() {

    // Static Arrays
    int staticArray[3]; // size 3 is fixed
    staticArray[0] = 10;
    staticArray[1] = 11;
    staticArray[2] = 12;

    printArray(staticArray, 3);

    // Dynamic
    std::vector<int> dynamicArray;  // size is not fixed
    dynamicArray.push_back(99);
    dynamicArray.push_back(44);
    dynamicArray.push_back(11);

    printArray(dynamicArray);


    return 0;
}

// Print static array
void printArray(const int* arr, int size) {
    std::cout << "\nPrinting static array...\n";
    for (int i = 0; i < size; i++) {
        std::cout << i << ": " << arr[i] << std::endl;
    }
    std::cout << "End of static array...\n";
}

// Print dynamic array (vector)
void printArray(const std::vector<int>& arr) {
    std::cout << "\nPrinting dynamic array...\n";
    for (int i = 0; i < (int)arr.size(); i++) {
        std::cout << i << ": " << arr[i] << std::endl;
    }
    std::cout << "End of dynamic array...\n";
}

/*

Code output:
--------------------------
Printing static array...
0: 10
1: 11
2: 12
End of static array...

Printing dynamic array...
0: 99
1: 44
2: 11
End of dynamic array...
--------------------------
*/