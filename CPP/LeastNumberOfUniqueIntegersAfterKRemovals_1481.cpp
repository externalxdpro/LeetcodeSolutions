// Difficulty: Medium
// Given an array of integers arr and an integer k. Find the least number of
// unique integers after removing exactly k elements.

// Example 1:
// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.

// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3
// will be left.

// Constraints:
//     1 <= arr.length <= 10^5
//     1 <= arr[i] <= 10^9
//     0 <= k <= arr.length

#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int findLeastNumOfUniqueInts(std::vector<int> &arr, int k) {
        std::unordered_map<int, int> occ;
        for (int i : arr) {
            occ[i]++;
        }

        std::map<int, std::unordered_set<int>> rev;
        for (auto [k, v] : occ) {
            rev[v].insert(k);
        }

        auto it = rev.begin();
        while (it != rev.end() && k > 0) {
            it->second.erase(it->second.begin());
            k -= it->first;

            if (it->second.empty()) {
                it++;
            }
        }

        int sum = 0;
        for (auto &[k, v] : rev) {
            sum += v.size();
        }

        if (k < 0) {
            sum++;
        }
        return sum;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{5, 5, 4}, 1}, 1},
        {{{4, 3, 1, 1, 3, 3, 2}, 3}, 2},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.findLeastNumOfUniqueInts(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
