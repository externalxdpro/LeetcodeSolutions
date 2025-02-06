// 1726. Tuple with Same Product
// Difficulty: Medium

// Given an array nums of distinct positive integers, return the number of
// tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements
// of nums, and a != b != c != d.

// Example 1:

// Input: nums = [2,3,4,6]
// Output: 8
// Explanation: There are 8 valid tuples:
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)

// Example 2:

// Input: nums = [1,2,4,5,10]
// Output: 16
// Explanation: There are 16 valid tuples:
// (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
// (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
// (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
// (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)

// Constraints:

//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 104
//     All elements in nums are distinct.

#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int tupleSameProduct(std::vector<int> &nums) {
        std::vector<int> products;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int b = nums[j];
                products.push_back(a * b);
            }
        }
        std::unordered_map<int, int> counts;
        int                          result = 0;
        for (int i : products) {
            counts[i]++;
        }
        for (auto [_, count] : counts) {
            if (count >= 2) {
                result += 8 * ((count - 1) * count / 2);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{2, 3, 4, 6}, 8},
        {{1, 2, 4, 5, 10}, 16},
        {{2, 3, 4, 6, 8, 12}, 40},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.tupleSameProduct(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
