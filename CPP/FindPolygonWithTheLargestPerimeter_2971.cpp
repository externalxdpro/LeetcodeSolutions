#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    long long largestPerimeter(std::vector<int> &nums) {
        std::ranges::sort(nums);
        std::vector<long long> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
        fmt::print("{}\n", prefixSum);

        for (int i = prefixSum.size() - 1; i >= 2; i--) {
            if (prefixSum[i - 1] > nums[i]) {
                return prefixSum[i];
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, long long>> tests = {
        {{5, 5, 5}, 15},
        {{1, 12, 1, 2, 5, 50, 3}, 12},
        {{5, 5, 50}, -1},
        {{5, 50, 50}, 105},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        fmt::print("{}: ", test);
        auto result = solution.largestPerimeter(test);
        fmt::print("{} {}\n", result, result == ans ? "✅" : "❌");
    }

    return 0;
}
