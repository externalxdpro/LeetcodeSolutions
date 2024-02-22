// Difficulty: Easy
// In a town, there are n people labeled from 1 to n. There is a rumor that one
// of these people is secretly the town judge.
// If the town judge exists, then:
//     The town judge trusts nobody.
//     Everybody (except for the town judge) trusts the town judge.
//     There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the
// person labeled ai trusts the person labeled bi. If a trust relationship does
// not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be
// identified, or return -1 otherwise.

// Example 1:
// Input: n = 2, trust = [[1,2]]
// Output: 2

// Example 2:
// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3

// Example 3:
// Input: n = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1

// Constraints:
//     1 <= n <= 1000
//     0 <= trust.length <= 10^4
//     trust[i].length == 2
//     All the pairs of trust are unique.
//     ai != bi
//     1 <= ai, bi <= n

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int findJudge(int n, std::vector<std::vector<int>> &trust) {
        std::unordered_map<int, std::vector<int>> trusts;
        std::unordered_map<int, int>              trustCounts;

        for (int i = 1; i <= n; i++) {
            trusts[i] = {};
        }

        for (auto i : trust) {
            trusts[i[0]].push_back(i[1]);
            trustCounts[i[1]]++;
        }

        for (auto i : trusts) {
            if (i.second.empty() && trustCounts[i.first] == n - 1) {
                return i.first;
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>, int>>
        tests = {
            {{2, {{1, 2}}}, 2},
            {{3, {{1, 3}, {2, 3}}}, 3},
            {{3, {{1, 3}, {2, 3}, {3, 1}}}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findJudge(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
