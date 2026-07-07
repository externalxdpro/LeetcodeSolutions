// 188. Best Time to Buy and Sell Stock IV
// Difficulty: Hard

// You are given an integer array prices where prices[i] is the price of a given
// stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k
// transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you
// must sell the stock before you buy again).

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
// 4-2 = 2. Example 2:

// Input: k = 2, prices = [3,2,6,5,0,3]
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
// 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit
// = 3-0 = 3.

// Constraints:

// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000

#include <algorithm>
#include <fmt/ranges.h>
#include <map>
#include <tuple>
#include <vector>

class Solution {
    std::map<std::tuple<int, int, int>, int> memo;

  public:
    int maxProfit(int k, std::vector<int> &prices) {
        return dp(prices, 0, true, k);
    }

  private:
    int dp(std::vector<int> &prices, size_t i, bool buy, int num) {
        if (i == prices.size() || num == 0) {
            return 0;
        }
        if (memo.contains({i, buy, num})) {
            return memo[{i, buy, num}];
        }
        int skip, take;
        if (buy) {
            skip = dp(prices, i + 1, true, num);
            take = dp(prices, i + 1, false, num) - prices[i];
        } else {
            skip = dp(prices, i + 1, false, num);
            take = dp(prices, i + 1, true, num - 1) + prices[i];
        }
        return memo[{i, buy, num}] = std::max(skip, take);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<int>>, int>> tests = {
        {{2, {2, 4, 1}}, 2},
        {{2, {3, 2, 6, 5, 0, 3}}, 7},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.maxProfit(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
