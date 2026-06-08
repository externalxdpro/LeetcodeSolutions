// 123. Best Time to Buy and Sell Stock III
// Difficulty: Hard

// You are given an array prices where prices[i] is the price of a given stock
// on the ith day.

// Find the maximum profit you can achieve. You may complete at most two
// transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you
// must sell the stock before you buy again).

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
// 3-0 = 3. Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit
// = 4-1 = 3. Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
// 5-1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later,
// as you are engaging multiple transactions at the same time. You must sell
// before buying again. Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    int memo[100002][2][2];

  public:
    int maxProfit(std::vector<int> &prices) {
        std::memset(memo, -1, sizeof(memo));
        return dp(prices, 0, true, 0);
    }

  private:
    int dp(std::vector<int> &prices, int i, bool buy, int num) {
        if (i == prices.size() || num == 2) {
            return 0;
        }
        if (memo[i][buy][num] != -1) {
            return memo[i][buy][num];
        }
        int skip, take;
        if (buy) {
            skip = dp(prices, i + 1, true, num);
            take = dp(prices, i + 1, false, num) - prices[i];
        } else {
            skip = dp(prices, i + 1, false, num);
            take = dp(prices, i + 1, true, num + 1) + prices[i];
        }
        return memo[i][buy][num] = std::max(skip, take);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{3, 3, 5, 0, 0, 3, 1, 4}, 6},
        {{1, 2, 3, 4, 5}, 4},
        {{7, 6, 4, 3, 1}, 0},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.maxProfit(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
