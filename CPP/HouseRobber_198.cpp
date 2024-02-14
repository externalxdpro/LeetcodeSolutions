#include <fmt/ranges.h>
#include <vector>

// Recursion
// class Solution {
//   public:
//     int rob(std::vector<int> &nums) {
//         return std::max(recurse(nums, 0), recurse(nums, 1));
//     }

//   private:
//     int recurse(std::vector<int> &nums, int i) {
//         if (i == nums.size() - 1) {
//             return nums[i];
//         }
//         if (i >= nums.size()) {
//             return 0;
//         }

//         return nums[i] + std::max(recurse(nums, i + 2), recurse(nums, i +
//         3));
//     }
// };

// Recursion + memo
class Solution {
  public:
    int rob(std::vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        std::vector<int> memo(nums.size() + 3, -1);
        *memo.rbegin() = 0;
        *(memo.rbegin() + 1) = 0;
        *(memo.rbegin() + 2) = 0;
        return std::max(recurse(nums, 0, memo), recurse(nums, 1, memo));
    }

  private:
    int recurse(std::vector<int> &nums, int i, std::vector<int> &memo) {
        if (i + 2 <= nums.size() - 1 && memo[i + 2] == -1) {
            memo[i + 2] = recurse(nums, i + 2, memo);
        }
        if (i + 3 <= nums.size() - 1 && memo[i + 3] == -1) {
            memo[i + 3] = recurse(nums, i + 3, memo);
        }

        memo[i] = nums[i] + std::max(memo[i + 2], memo[i + 3]);
        return memo[i];
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> tests = {
        {1, 2, 3, 1}, {2, 7, 9, 3, 1}, {2, 1, 1, 2}, {1, 2}, {0},
    };

    Solution solution;
    for (auto &test : tests) {
        fmt::print("{}: {}\n", test, solution.rob(test));
    }

    return 0;
}
