// 2551. Put Marbles in Bags
// Difficulty: Hard

// You have k bags. You are given a 0-indexed integer array weights where
// weights[i] is the weight of the ith marble. You are also given the integer k.

// Divide the marbles into the k bags according to the following rules:

//     No bag is empty.
//     If the ith marble and jth marble are in a bag, then all marbles with an
//     index between the ith and jth indices should also be in that same bag. If
//     a bag consists of all the marbles with an index from i to j inclusively,
//     then the cost of the bag is weights[i] + weights[j].

// The score after distributing the marbles is the sum of the costs of all the k
// bags.

// Return the difference between the maximum and minimum scores among marble
// distributions.

// Example 1:

// Input: weights = [1,3,5,1], k = 2
// Output: 4
// Explanation:
// The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1)
// = 6. The distribution [1,3],[5,1], results in the maximal score of (1+3) +
// (5+1) = 10. Thus, we return their difference 10 - 6 = 4.

// Example 2:

// Input: weights = [1, 3], k = 2
// Output: 0
// Explanation: The only distribution possible is [1],[3].
// Since both the maximal and minimal score are the same, we return 0.

// Constraints:

//     1 <= k <= weights.length <= 105
//     1 <= weights[i] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    long long putMarbles(std::vector<int> &weights, int k) {
        std::vector<int> pairs(weights.size() - 1);
        for (int i = 0; i < weights.size() - 1; i++) {
            pairs[i] = weights[i] + weights[i + 1];
        }
        std::ranges::sort(pairs);

        long long result = 0;
        for (int i = 0; i < k - 1; i++) {
            result += pairs[weights.size() - 2 - i] - pairs[i];
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, long long>> tests =
        {
            {{{1, 3, 5, 1}, {2}}, 4},
            {{{1, 3}, 2}, 0},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.putMarbles(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
