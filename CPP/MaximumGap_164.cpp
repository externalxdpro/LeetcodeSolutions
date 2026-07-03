// 164. Maximum Gap
// Difficulty: Medium

// Given an integer array nums, return the maximum difference between two
// successive elements in its sorted form. If the array contains less than two
// elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra
// space.

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9)
// has the maximum difference 3. Example 2:

// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maximumGap(std::vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }

        auto [min, max] = std::minmax_element(nums.begin(), nums.end());
        if (*min == *max) {
            return 0;
        }

        int gap = std::max(1UL, (*max - *min) / (nums.size() - 1));
        std::vector<std::pair<int, int>> buckets((*max - *min) / gap + 1,
                                                 {-1, -1});

        for (int num : nums) {
            int i = (num - *min) / gap;
            if (buckets[i].first == -1) {
                buckets[i].first = buckets[i].second = num;
            } else {
                buckets[i].first = std::min(buckets[i].first, num);
                buckets[i].second = std::max(buckets[i].second, num);
            }
        }

        int result = 0;
        int prev = *min;
        for (std::pair bucket : buckets) {
            if (bucket.first != -1) {
                result = std::max(result, bucket.first - prev);
                prev = bucket.second;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{3, 6, 9, 1}, 3},
        {{10}, 0},
        {{1, 10000000}, 9999999},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.maximumGap(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
