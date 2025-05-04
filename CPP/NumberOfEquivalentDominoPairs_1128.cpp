// 1128. Number of Equivalent Domino Pairs
// Difficulty: Easy

// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] =
// [c, d] if and only if either (a == c and b == d), or (a == d and b == c) -
// that is, one domino can be rotated to be equal to another domino.

// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and
// dominoes[i] is equivalent to dominoes[j].

// Example 1:

// Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
// Output: 1

// Example 2:

// Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
// Output: 3

// Constraints:

//     1 <= dominoes.length <= 4 * 104
//     dominoes[i].length == 2
//     1 <= dominoes[i][j] <= 9

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes) {
        int counts[100] = {0};
        int result      = 0;
        for (auto &d : dominoes) {
            int val = std::min(d[0] * 10 + d[1], d[1] * 10 + d[0]);
            result += counts[val];
            counts[val]++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 2}, {2, 1}, {3, 4}, {5, 6}}, 1},
        {{{{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}}}, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numEquivDominoPairs(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
