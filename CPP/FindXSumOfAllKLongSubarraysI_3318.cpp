// 3318. Find X-Sum of All K-Long Subarrays I
// Difficulty: Easy

// You are given an array nums of n integers and two integers k and x.

// The x-sum of an array is calculated by the following procedure:

//     Count the occurrences of all elements in the array.
//     Keep only the occurrences of the top x most frequent elements. If two
//     elements have the same number of occurrences, the element with the bigger
//     value is considered more frequent. Calculate the sum of the resulting
//     array.

// Note that if an array has less than x distinct elements, its x-sum is the sum
// of the array.

// Return an integer array answer of length n - k + 1 where answer[i] is the
// x-sum of the

// nums[i..i + k - 1].

// Example 1:

// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

// Output: [6,10,12]

// Explanation:

//     For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in
//     the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2. For subarray [1,
//     2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting
//     array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array
//     since it is bigger than 3 and 1 which occur the same number of times. For
//     subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the
//     resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.

// Example 2:

// Input: nums = [3,8,7,8,7,5], k = 2, x = 2

// Output: [11,15,15,15,12]

// Explanation:

// Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k -
// 1].

// Constraints:

//     1 <= n == nums.length <= 50
//     1 <= nums[i] <= 50
//     1 <= x <= k <= nums.length

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> findXSum(std::vector<int> &nums, int k, int x) {
        const int n = nums.size();
        std::vector<int> result(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) {
            result[i] = xsum(nums, k, x, i);
        }
        return result;
    }

  private:
    int xsum(std::vector<int> &nums, int k, int x, int i) {
        std::unordered_map<int, int> freqs;
        for (int j = i; j < i + k; j++) {
            freqs[nums[j]]++;
        }
        std::vector<std::pair<int, int>> temp(freqs.begin(), freqs.end());
        std::sort(temp.begin(), temp.end(), [](auto a, auto b) {
            return a.second == b.second ? a.first > b.first
                                        : a.second > b.second;
        });

        int result = 0;
        for (int i = 0; i < std::min((int)temp.size(), x); i++) {
            result += temp[i].first * temp[i].second;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::tuple<std::vector<int>, int, int>, std::vector<int>>>
        tests = {
            {{{1, 1, 2, 2, 3, 4, 2, 3}, 6, 2}, {6, 10, 12}},
            {{{3, 8, 7, 8, 7, 5}, 2, 2}, {11, 15, 15, 15, 12}},
            {{{9, 2, 2}, 3, 3}, {13}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findXSum(std::get<0>(test), std::get<1>(test),
                                        std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
