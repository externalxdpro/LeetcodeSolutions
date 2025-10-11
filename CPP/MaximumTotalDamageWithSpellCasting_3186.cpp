// 3186. Maximum Total Damage With Spell Casting
// Difficulty: Medium

// A magician has various spells.

// You are given an array power, where each element represents the damage of a
// spell. Multiple spells can have the same damage value.

// It is a known fact that if a magician decides to cast a spell with a damage
// of power[i], they cannot cast any spell with a damage of power[i] - 2,
// power[i] - 1, power[i] + 1, or power[i] + 2.

// Each spell can be cast only once.

// Return the maximum possible total damage that a magician can cast.

// Example 1:

// Input: power = [1,1,3,4]

// Output: 6

// Explanation:

// The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with
// damage 1, 1, 4.

// Example 2:

// Input: power = [7,1,6,6]

// Output: 13

// Explanation:

// The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with
// damage 1, 6, 6.

// Constraints:

//     1 <= power.length <= 105
//     1 <= power[i] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    long long maximumTotalDamage(std::vector<int> &power) {
        std::sort(power.begin(), power.end());

        std::vector<std::pair<int, long long>> spell{{power[0], power[0]}};
        for (int i = 1; i < power.size(); i++) {
            if (power[i] != power[i - 1]) {
                spell.emplace_back(power[i], power[i]);
            } else {
                spell.back().second += power[i];
            }
        }

        std::vector<long long> memo(spell.size(), -1);
        return dp(spell, 0, memo);
    }

  private:
    long long dp(std::vector<std::pair<int, long long>> &spell, int i,
                 std::vector<long long> &memo) {
        if (i >= spell.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }

        long long skip = dp(spell, i + 1, memo);

        int j = i + 1;
        for (; j < spell.size() && spell[j].first <= spell[i].first + 2; j++)
            ;
        long long take = spell[i].second + dp(spell, j, memo);

        return memo[i] = std::max(take, skip);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, long long>> tests = {
        {{1, 1, 3, 4}, 6},
        {{7, 1, 6, 6}, 13},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumTotalDamage(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
