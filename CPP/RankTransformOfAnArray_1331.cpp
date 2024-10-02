// 1331. Rank Transform of an Array
// Difficulty: Easy

// Given an array of integers arr, replace each element with its rank.

// The rank represents how large the element is. The rank has the following
// rules:

//     Rank is an integer starting from 1.
//     The larger the element, the larger the rank. If two elements are equal,
//     their rank must be the same. Rank should be as small as possible.

// Example 1:

// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Explanation: 40 is the largest element. 10 is the smallest. 20 is the second
// smallest. 30 is the third smallest.

// Example 2:

// Input: arr = [100,100,100]
// Output: [1,1,1]
// Explanation: Same elements share the same rank.

// Example 3:

// Input: arr = [37,12,28,9,100,56,80,5,12]
// Output: [5,3,4,2,8,6,7,1,3]

// Constraints:

//     0 <= arr.length <= 105
//     -109 <= arr[i] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    std::vector<int> arrayRankTransform(std::vector<int> &arr) {
        std::vector<int> idxs(arr.size());
        std::iota(idxs.begin(), idxs.end(), 0);
        std::ranges::sort(idxs, [&](int a, int b) { return arr[a] < arr[b]; });

        std::vector<int> result(arr.size());
        int              currRank = 1;
        for (int i = 0; i < idxs.size(); i++) {
            if (i > 0 && arr[idxs[i]] != arr[idxs[i - 1]]) {
                currRank++;
            }
            result[idxs[i]] = currRank;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{40, 10, 20, 30}, {4, 1, 2, 3}},
        {{100, 100, 100}, {1, 1, 1}},
        {{37, 12, 28, 9, 100, 56, 80, 5, 12}, {5, 3, 4, 2, 8, 6, 7, 1, 3}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.arrayRankTransform(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
