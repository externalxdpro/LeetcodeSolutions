// 1980. Find Unique Binary String
// Difficulty: Medium

// Given an array of strings nums containing n unique binary strings each of
// length n, return a binary string of length n that does not appear in nums. If
// there are multiple answers, you may return any of them.

// Example 1:

// Input: nums = ["01","10"]
// Output: "11"
// Explanation: "11" does not appear in nums. "00" would also be correct.

// Example 2:

// Input: nums = ["00","01"]
// Output: "11"
// Explanation: "11" does not appear in nums. "10" would also be correct.

// Example 3:

// Input: nums = ["111","011","001"]
// Output: "101"
// Explanation: "101" does not appear in nums. "000", "010", "100", and "110"
// would also be correct.

// Constraints:

//     n == nums.length
//     1 <= n <= 16
//     nums[i].length == n
//     nums[i] is either '0' or '1'.
//     All the strings of nums are unique.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string findDifferentBinaryString(std::vector<std::string> &nums) {
        std::string result;
        for (int i = 0; i < nums.size(); i++) {
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, std::string>> tests = {
        {{"01", "10"}, "11"},
        {{"00", "01"}, "10"},
        {{"111", "011", "001"}, "000"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findDifferentBinaryString(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
