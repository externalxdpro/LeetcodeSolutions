// 2040. Kth Smallest Product of Two Sorted Arrays
// Difficulty: Hard

// Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an
// integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j]
// where 0 <= i < nums1.length and 0 <= j < nums2.length.

// Example 1:

// Input: nums1 = [2,5], nums2 = [3,4], k = 2
// Output: 8
// Explanation: The 2 smallest products are:
// - nums1[0] * nums2[0] = 2 * 3 = 6
// - nums1[0] * nums2[1] = 2 * 4 = 8
// The 2nd smallest product is 8.

// Example 2:

// Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
// Output: 0
// Explanation: The 6 smallest products are:
// - nums1[0] * nums2[1] = (-4) * 4 = -16
// - nums1[0] * nums2[0] = (-4) * 2 = -8
// - nums1[1] * nums2[1] = (-2) * 4 = -8
// - nums1[1] * nums2[0] = (-2) * 2 = -4
// - nums1[2] * nums2[0] = 0 * 2 = 0
// - nums1[2] * nums2[1] = 0 * 4 = 0
// The 6th smallest product is 0.

// Example 3:

// Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
// Output: -6
// Explanation: The 3 smallest products are:
// - nums1[0] * nums2[4] = (-2) * 5 = -10
// - nums1[0] * nums2[3] = (-2) * 4 = -8
// - nums1[4] * nums2[0] = 2 * (-3) = -6
// The 3rd smallest product is -6.

// Constraints:

//     1 <= nums1.length, nums2.length <= 5 * 104
//     -105 <= nums1[i], nums2[j] <= 105
//     1 <= k <= nums1.length * nums2.length
//     nums1 and nums2 are sorted.

#include <algorithm>
#include <fmt/ranges.h>
#include <tuple>
#include <vector>

class Solution {
  public:
    long long kthSmallestProduct(std::vector<int> &nums1,
                                 std::vector<int> &nums2, long long k) {
        int len1 = nums1.size(), len2 = nums2.size();
        int neg1 = std::ranges::count_if(nums1, [](int i) { return i < 0; });
        int neg2 = std::ranges::count_if(nums2, [](int i) { return i < 0; });
        long long l = -1e10, r = 1e10;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long total = 0;

            int i = 0, j = neg2 - 1;
            while (i < neg1 && j >= 0) {
                if ((long long)nums1[i] * nums2[j] > m) {
                    i++;
                } else {
                    total += neg1 - i;
                    j--;
                }
            }

            i = neg1, j = len2 - 1;
            while (i < len1 && j >= neg2) {
                if ((long long)nums1[i] * nums2[j] > m) {
                    j--;
                } else {
                    total += j - neg2 + 1;
                    i++;
                }
            }

            i = 0, j = neg2;
            while (i < neg1 && j < len2) {
                if ((long long)nums1[i] * nums2[j] > m) {
                    j++;
                } else {
                    total += len2 - j;
                    i++;
                }
            }

            i = neg1, j = 0;
            while (i < len1 && j < neg2) {
                if ((long long)nums1[i] * nums2[j] > m) {
                    i++;
                } else {
                    total += len1 - i;
                    j++;
                }
            }

            if (total < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::tuple<std::vector<int>, std::vector<int>, long long>, long long>>
        tests = {
            {{{2, 5}, {3, 4}, 2}, 8},
            {{{-4, -2, 0, 3}, {2, 4}, 6}, 0},
            {{{-2, -1, 0, 1, 2}, {-3, -1, 2, 4, 5}, 3}, -6},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.kthSmallestProduct(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
