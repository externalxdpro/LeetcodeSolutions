// Difficulty: Hard
// You are given a 0-indexed integer array nums, and you are allowed to traverse
// between its indices. You can traverse between index i and index j, i != j, if
// and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common
// divisor.
// Your task is to determine if for every pair of indices i and j in nums, where
// i < j, there exists a sequence of traversals that can take us from i to j.
// Return true if it is possible to traverse between all such pairs of indices,
// or false otherwise.

// Example 1:
// Input: nums = [2,3,6]
// Output: true
// Explanation: In this example, there are 3 possible pairs of indices: (0, 1),
// (0, 2), and (1, 2). To go from index 0 to index 1, we can use the sequence of
// traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because
// gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to
// index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1. To go from index 0
// to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6)
// = 2 > 1. Likewise, to go from index 1 to index 2, we can just go directly
// because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.

// Example 2:
// Input: nums = [3,9,5]
// Output: false
// Explanation: No sequence of traversals can take us from index 0 to index 2 in
// this example. So, we return false.

// Example 3:
// Input: nums = [4,3,12,8]
// Output: true
// Explanation: There are 6 possible pairs of indices to traverse between: (0,
// 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of
// traversals exists for each pair, so we return true.

// Constraints:
//     1 <= nums.length <= 10^5
//     1 <= nums[i] <= 10^5

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool canTraverseAllPairs(std::vector<int> &nums) {
        if (nums.size() == 1) {
            return true;
        }

        std::unordered_set<int> set(nums.begin(), nums.end());
        if (set.contains(1)) {
            return false;
        }

        int max = std::ranges::max(set);

        std::vector<int>              primes = sieve(max);
        std::vector<int>              numState(max + 1, 0);
        std::vector<std::vector<int>> commonFactors(max + 1,
                                                    std::vector<int>());
        buildCommonFactorPath(set, max, primes, numState, commonFactors);

        for (int i : set) {
            if (numState[i] == 1) {
                int currSize = 0;
                dfs(i, numState, commonFactors, currSize);
                if (currSize == set.size()) {
                    return true;
                }
            }
        }

        return false;
    }

  private:
    std::vector<int> sieve(int n) {
        std::vector<int> A(n + 1, true);

        int limit = std::sqrt(n) + 1;
        for (int i = 2; i <= limit; i++) {
            if (A[i]) {
                for (int j = i * i; j <= n; j += i) {
                    A[j] = false;
                }
            }
        }

        std::vector<int> primes;
        primes.reserve((int)log(n));
        for (int i = 2; i < A.size(); i++) {
            if (A[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    void buildCommonFactorPath(std::unordered_set<int> &nums, int n,
                               std::vector<int>              &primes,
                               std::vector<int>              &numState,
                               std::vector<std::vector<int>> &commonFactors) {
        for (int num : nums) {
            numState[num] = 1;
        }
        for (int prime : primes) {
            if (numState[prime] != 1) {
                numState[prime] = -1;
            }

            for (int i = prime * 2; i <= n; i += prime) {
                if (numState[i] == 1) {
                    commonFactors[i].push_back(prime);
                    commonFactors[prime].push_back(i);
                }
            }
        }
    }

    void dfs(int i, std::vector<int> &numState,
             std::vector<std::vector<int>> &commonFactors, int &currSize) {
        if (numState[i] == 1 && i != 1) {
            currSize++;
        }
        numState[i] = 2;

        for (int factor : commonFactors[i]) {
            if (numState[factor] == 1 || numState[factor] == -1) {
                dfs(factor, numState, commonFactors, currSize);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{2, 3, 6}, true}, {{3, 9, 5}, false}, {{4, 3, 12, 8}, true},
        {{1, 1}, false},   {{30, 30}, true},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.canTraverseAllPairs(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
