// Difficulty: Medium
// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:
// Input: nums = [1]
// Output: [[1]]

// Constraints:
//     1 <= nums.length <= 6
//     -10 <= nums[i] <= 10
//     All the integers of nums are unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <vector>

using namespace std;

// manual permutating
// void nextPermutation(std::vector<int> &nums) {
//     int len = nums.size();

//     int i;
//     for (i = len - 2; i >= 0; i--) {
//         if (nums[i] < nums[i + 1]) {
//             break;
//         }
//     }

//     if (i < 0) {
//         std::ranges::reverse(nums);
//         return;
//     }

//     int j;
//     for (j = len - 1; j > i; j--) {
//         if (nums[j] > nums[i]) {
//             break;
//         }
//     }
//     std::swap(nums[i], nums[j]);

//     std::reverse(nums.begin() + i + 1, nums.end());
//     return;
// }

// std::vector<std::vector<int>> permute(std::vector<int> &nums) {
//     std::vector<std::vector<int>> result;
//     std::vector<int> orig = nums;
//     do {
//         result.push_back(nums);
//         nextPermutation(nums);
//     } while (nums != orig);

//     return result;
// }

// using stl
std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;

    std::vector<int> orig = nums;
    do {
        result.push_back(nums);
        std::next_permutation(nums.begin(), nums.end());
    } while (nums != orig);

    return result;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> tests = {
        {1, 2, 3},
        {0, 1},
        {1},
    };

    for (auto test : tests) {
        std::vector<std::vector<int>> permutations = permute(test);
        fmt::print("{}: {}\n", test, permutations);
    }

    return 0;
}
