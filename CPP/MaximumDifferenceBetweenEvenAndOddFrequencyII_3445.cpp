// 3445. Maximum Difference Between Even and Odd Frequency II
// Difficulty: Hard

// You are given a string s and an integer k. Your task is to find the maximum
// difference between the frequency of two characters, freq[a] - freq[b], in a

// subs of s, such that:

//     subs has a size of at least k.
//     Character a has an odd frequency in subs.
//     Character b has an even frequency in subs.

// Return the maximum difference.

// Note that subs can contain more than 2 distinct characters.

// Example 1:

// Input: s = "12233", k = 4

// Output: -1

// Explanation:

// For the substring "12233", the frequency of '1' is 1 and the frequency of '3'
// is 2. The difference is 1 - 2 = -1.

// Example 2:

// Input: s = "1122211", k = 3

// Output: 1

// Explanation:

// For the substring "11222", the frequency of '2' is 3 and the frequency of '1'
// is 2. The difference is 3 - 2 = 1.

// Example 3:

// Input: s = "110", k = 3

// Output: -1

// Constraints:

//     3 <= s.length <= 3 * 104
//     s consists only of digits '0' to '4'.
//     The input is generated that at least one substring has a character with
//     an even frequency and a character with an odd frequency. 1 <= k <=
//     s.length

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maxDifference(std::string s, int k) {
        int result = INT_MIN;

        for (char a = '0'; a <= '4'; a++) {
            for (char b = '0'; b <= '4'; b++) {
                if (a == b) {
                    continue;
                }
                std::vector<std::vector<int>> seen(2, std::vector(2, INT_MAX));
                std::vector<int> parityA{0}, parityB{0};
                int j = 0;
                for (int i = 0; i < s.size(); i++) {
                    parityA.push_back(parityA.back());
                    parityB.push_back(parityB.back());

                    if (s[i] == a) {
                        parityA.back()++;
                    } else if (s[i] == b) {
                        parityB.back()++;
                    }

                    while (j <= i - k + 1 && parityA[j] < parityA.back() &&
                           parityB[j] < parityB.back()) {
                        int keyA = parityA[j] % 2, keyB = parityB[j] % 2;
                        int diff = parityA[j] - parityB[j];
                        seen[keyA][keyB] = std::min(seen[keyA][keyB], diff);
                        j++;
                    }

                    int keyA = 1 - parityA.back() % 2;
                    int keyB = parityB.back() % 2;
                    int diff = parityA.back() - parityB.back();
                    if (seen[keyA][keyB] != INT_MAX) {
                        result = std::max(result, diff - seen[keyA][keyB]);
                    }
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, int>> tests = {
        {{"12233", 4}, -1},
        {{"1122211", 3}, 1},
        {{"110", 3}, -1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxDifference(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
