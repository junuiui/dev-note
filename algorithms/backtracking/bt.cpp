/*
Problem: Generate All Subsets (Power Set)
Description:
    You are given a list of distinct integers nums.
    Your task is to generate all possible subsets (the power set).

Input:
    A list of integers nums, where all elements are distinct.
    Example: nums = [1, 2, 3]

Output:
    Return a list of all subsets (each subset is a list).
    The solution set must not contain duplicate subsets.

Example)
    Input:  [1, 2]
    Output: [[], [1], [2], [1, 2]]

    Input:  [1, 2, 3]
    Output: 
    [
    [],
    [1],
    [2],
    [3],
    [1, 2],
    [1, 3],
    [2, 3],
    [1, 2, 3]
    ]

Contraints
    You may return the subsets in any order.
    Must use backtracking, not bit manipulation.
*/

#include <vector>
#include <iostream>

using namespace std;

void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current); // Add the current subset

    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);             // Choose
        backtrack(nums, i + 1, current, result); // Explore
        current.pop_back();                      // Undo (Backtrack)
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> allSubsets = subsets(nums);

    cout << "All subsets:\n";
    for (auto subset : allSubsets) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}

