// Difficulty: Easy
// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// Constraints:
//     1 <= nums.length <= 105
//     -109 <= nums[i] <= 109

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

// bool containsDuplicate(std::vector<int> &nums) {
//     std::map<int, int> occurences;
//     for (int i : nums) {
//         if (occurences[i]) return true;
//         occurences[i] = 1;
//     }
//     return false;
// }

bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    return set.size() != nums.size() ? true : false;
}

int main() {
    std::vector<std::vector<int>> tests{
        {1, 2, 3, 1}, {1, 2, 3, 4}, {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}};

    for (auto i : tests) {
        std::cout << (containsDuplicate(i) ? "true" : "false") << std::endl;
    }

    return 0;
}
