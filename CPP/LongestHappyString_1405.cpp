// 1405. Longest Happy String
// Difficulty: Medium

// A string s is called happy if it satisfies the following conditions:

//     s only contains the letters 'a', 'b', and 'c'.
//     s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//     s contains at most a occurrences of the letter 'a'.
//     s contains at most b occurrences of the letter 'b'.
//     s contains at most c occurrences of the letter 'c'.

// Given three integers a, b, and c, return the longest possible happy string.
// If there are multiple longest happy strings, return any of them. If there is
// no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.

// Example 2:

// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.

// Constraints:

//     0 <= a, b, c <= 100
//     a + b + c > 0

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    std::string longestDiverseString(int a, int b, int c) {
        std::priority_queue<std::pair<int, char>> pq;
        if (a > 0) {
            pq.emplace(a, 'a');
        }
        if (b > 0) {
            pq.emplace(b, 'b');
        }
        if (c > 0) {
            pq.emplace(c, 'c');
        }

        std::string result;

        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();
            if (result.size() >= 2 && result.back() == c &&
                *(result.rbegin() + 1) == c) {
                if (pq.empty()) {
                    break;
                }

                auto temp = pq.top();
                pq.pop();
                result += temp.second;
                if (temp.first - 1 > 0) {
                    pq.emplace(temp.first - 1, temp.second);
                }
            } else {
                count--;
                result += c;
            }

            if (count > 0) {
                pq.emplace(count, c);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::array<int, 3>, std::string>> tests = {
        {{1, 1, 7}, "ccbccacc"},
        {{7, 1, 0}, "aabaa"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.longestDiverseString(test[0], test[1], test[2]);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
