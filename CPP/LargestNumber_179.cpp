// 179. Largest Number
// Difficulty: Medium

// Given a list of non-negative integers nums, arrange them such that they form
// the largest number and return it.
// Since the result may be very large, so you need to return a string instead of
// an integer.

// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

// Constraints:
//     1 <= nums.length <= 100
//     0 <= nums[i] <= 10^9

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    std::string largestNumber(std::vector<int> &nums) {
        std::vector<std::string> numStrs;
        std::ranges::transform(nums, std::back_inserter(numStrs),
                               [](int i) { return std::to_string(i); });
        std::sort(numStrs.begin(), numStrs.end(),
                  [](auto i, auto j) { return j + i < i + j; });
        std::string result =
            std::accumulate(numStrs.begin(), numStrs.end(), std::string());
        return result[0] == '0' ? "0" : result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::string>> tests = {
        {{10, 2}, "210"},
        {{3, 30, 34, 5, 9}, "9534330"},
        {{0, 0}, "0"},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "9876543210"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.largestNumber(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
