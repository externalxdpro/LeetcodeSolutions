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
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::string findDifferentBinaryString(std::vector<std::string> &nums) {
        std::unordered_set<std::string> set(nums.begin(), nums.end());
        std::string                     curr(nums[0].size(), '0');
        while (true) {
            if (!set.contains(curr)) {
                return curr;
            }
            increase(curr);
        }
    }

  private:
    void increase(std::string &curr) {
        for (int i = curr.size() - 1; i >= 0; i--) {
            if (curr[i] == '0') {
                curr[i] = '1';
                break;
            }
            curr[i] = '0';
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, std::string>> tests = {
        {{"01", "10"}, "00"},
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
