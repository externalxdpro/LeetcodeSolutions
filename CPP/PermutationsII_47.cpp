// Difficulty: Medium
// Given a collection of numbers, nums, that might contain duplicates, return
// all possible unique permutations in any order.

// Example 1:
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// Example 2:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Constraints:
//     1 <= nums.length <= 8
//     -10 <= nums[i] <= 10

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

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

// std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
//     std::vector<std::vector<int>> result;

//     do {
//         result.push_back(nums);
//         nextPermutation(nums);
//     } while (result[0] != nums);

//     return result;
// }

// using stl
std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;

    do {
        result.push_back(nums);
        std::next_permutation(nums.begin(), nums.end());
    } while (result[0] != nums);

    return result;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> tests = {
        {1, 1, 2},
        {1, 2, 3},
    };

    for (auto test : tests) {
        fmt::print("{}: {}\n", test, permuteUnique(test));
    }

    return 0;
}
