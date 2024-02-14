// Difficulty: Easy
// You have a set of integers s, which originally contains all the numbers from
// 1 to n. Unfortunately, due to some error, one of the numbers in s got
// duplicated to another number in the set, which results in repetition of one
// number and loss of another number.
// You are given an integer array nums representing the data status of this set
// after the error.
// Find the number that occurs twice and the number that is missing and return
// them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]

// Example 2:
// Input: nums = [1,1]
// Output: [1,2]

// Constraints:
//     2 <= nums.length <= 10^4
//     1 <= nums[i] <= 10^4

#include <algorithm>
#include <fmt/ranges.h>
#include <set>
#include <vector>

class Solution {
  public:
    std::vector<int> findErrorNums(std::vector<int> &nums) {
        std::ranges::sort(nums);
        std::set<int>    set;
        std::vector<int> result(2);

        for (int num : nums) {
            if (set.contains(num)) {
                result[0] = num;
            }
            set.insert(num);
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (!set.contains(i)) {
                result[1] = i;
                break;
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 2, 2, 4}, {2, 3}}, {{1, 1}, {1, 2}},
        {{2, 2}, {2, 1}},       {{3, 2, 2}, {2, 1}},
        {{3, 3, 1}, {3, 2}},    {{1, 5, 3, 2, 2, 7, 6, 4, 8, 9}, {2, 10}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findErrorNums(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
