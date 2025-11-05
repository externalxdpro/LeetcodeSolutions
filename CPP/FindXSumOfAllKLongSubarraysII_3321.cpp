// 3321. Find X-Sum of All K-Long Subarrays II
// Difficulty: Hard

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

//     nums.length == n
//     1 <= n <= 105
//     1 <= nums[i] <= 109
//     1 <= x <= k <= nums.length

#include <algorithm>
#include <fmt/ranges.h>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
    std::unordered_map<int, int> freq;
    std::set<std::pair<int, int>> top;
    std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> rest;
    long long currSum = 0;

  public:
    std::vector<long long> findXSum(std::vector<int> &nums, int k, int x) {
        const int n = nums.size();
        freq.reserve(n);
        std::vector<long long> result(n - k + 1);

        for (int i = 0; i < k; i++) {
            insert(nums[i], x);
        }
        result[0] = currSum;

        for (int l = 1, r = k; r < n; l++, r++) {
            remove(nums[l - 1], x);
            insert(nums[r], x);
            result[l] = currSum;
        }

        return result;
    }

  private:
    void insert(int v, int x) {
        int &f = freq[v];
        if (f) {
            auto it = top.find({f, v});
            if (it != top.end()) {
                top.erase(it);
                currSum -= 1LL * f * v;
            } else {
                rest.erase({f, v});
            }
        }

        top.emplace(++f, v);
        currSum += 1LL * f * v;

        if ((int)top.size() > x) {
            auto it = top.begin();
            currSum -= 1LL * it->first * it->second;
            rest.insert(*it);
            top.erase(it);
        }
    }

    void remove(int v, int x) {
        int &f = freq[v];
        if (f == 0) {
            return;
        }
        auto it = top.find({f, v});
        if (it != top.end()) {
            top.erase(it);
            currSum -= 1LL * f * v;
        } else {
            rest.erase({f, v});
        }

        if (--f == 0) {
            freq.erase(v);
        } else {
            rest.emplace(f, v);
        }

        if ((int)top.size() < x && !rest.empty()) {
            auto it = rest.begin();
            currSum += 1LL * it->first * it->second;
            top.insert(*it);
            rest.erase(it);
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>,
                          std::vector<long long>>>
        tests = {
            {{{1, 1, 2, 2, 3, 4, 2, 3}, 6, 2}, {6, 10, 12}},
            {{{3, 8, 7, 8, 7, 5}, 2, 2}, {11, 15, 15, 15, 12}},
            {{{9, 2, 2}, 3, 3}, {13}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findXSum(std::get<0>(test), std::get<1>(test),
                                        std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
