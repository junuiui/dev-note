// unordered_map.cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main() {
    // Creating an unordered_map
    std::unordered_map<std::string, int> freq;
    freq["apple"] = 3;
    freq["banana"] = 5;

    // Accessing values
    std::cout << "apple count: " << freq["apple"] << "\n";
    std::cout << "banana exists? " << (freq.count("banana") ? "Yes" : "No") << "\n";
    std::cout << "grape exists? " << (freq.count("grape") ? "Yes" : "No") << "\n";

    // Iterating over unordered_map
    std::cout << "Iterating unordered_map:\n";
    for (const auto& [key, value] : freq) {
        std::cout << key << ": " << value << "\n";
    }

    // Using unordered_set
    std::unordered_set<int> seen;
    seen.insert(10);
    seen.insert(20);
    seen.insert(10);  // Duplicate will be ignored

    std::cout << "10 is in set? " << (seen.count(10) ? "Yes" : "No") << "\n";
    std::cout << "Elements in unordered_set:\n";
    for (int n : seen) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}

/*
Output
apple count: 3
banana exists? Yes
grape exists? No
Iterating unordered_map:
banana: 5
apple: 3
10 is in set? Yes
Elements in unordered_set:
20 10 
*/
