// 2179. Count Good Triplets in an Array
// Difficulty: Hard

// You are given two 0-indexed arrays nums1 and nums2 of length n, both of which
// are permutations of [0, 1, ..., n - 1].

// A good triplet is a set of 3 distinct values which are present in increasing
// order by position both in nums1 and nums2. In other words, if we consider
// pos1v as the index of the value v in nums1 and pos2v as the index of the
// value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x,
// y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

// Return the total number of good triplets.

// Example 1:

// Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
// Output: 1
// Explanation:
// There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are
// (2,0,1), (2,0,3), (2,1,3), and (0,1,3). Out of those triplets, only the
// triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good
// triplet.

// Example 2:

// Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
// Output: 4
// Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).

// Constraints:

//     n == nums1.length == nums2.length
//     3 <= n <= 105
//     0 <= nums1[i], nums2[i] <= n - 1
//     nums1 and nums2 are permutations of [0, 1, ..., n - 1].

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    long long goodTriplets(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::unordered_map<int, int> indexes;
        for (int i = 0; i < nums1.size(); i++) {
            indexes[nums1[i]] = i;
        }
        std::vector<int> sorted;
        long long        result = 0;

        for (int num2 : nums2) {
            int i1 = indexes[num2];
            int l  = search(sorted, i1);
            int r  = (nums1.size() - i1 - 1) - (sorted.size() - l);
            result += (long long)l * r;

            int pos = search(sorted, i1);
            sorted.insert(sorted.begin() + pos, i1);
        }
        return result;
    }

  private:
    int search(std::vector<int> &nums, int num) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < num) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::vector<int>, std::vector<int>>, long long>>
        tests = {
            {{{2, 0, 1, 3}, {0, 1, 2, 3}}, 1},
            {{{4, 0, 1, 3, 2}, {4, 1, 0, 2, 3}}, 4},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.goodTriplets(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
