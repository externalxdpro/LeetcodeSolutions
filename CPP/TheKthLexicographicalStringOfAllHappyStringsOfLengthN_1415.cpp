// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// Difficulty: Medium

// A happy string is a string that:

//     consists only of letters of the set ['a', 'b', 'c'].
//     s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is
//     1-indexed).

// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings
// and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n
// sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are
// less than k happy strings of length n.

// Example 1:

// Input: n = 1, k = 3
// Output: "c"
// Explanation: The list ["a", "b", "c"] contains all happy strings of length 1.
// The third string is "c".

// Example 2:

// Input: n = 1, k = 4
// Output: ""
// Explanation: There are only 3 happy strings of length 1.

// Example 3:

// Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc",
// "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You
// will find the 9th string = "cab"

// Constraints:

//     1 <= n <= 10
//     1 <= k <= 100

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string getHappyString(int n, int k) {
        std::vector<std::string> strings;
        std::string              temp;
        generate(n, k, temp, strings);
        if (k > strings.size()) {
            return "";
        }
        return strings[k - 1];
    }

  private:
    void generate(int n, int k, std::string &curr,
                  std::vector<std::string> &strings) {
        if (curr.size() == n) {
            strings.push_back(curr);
            return;
        }
        for (char i = 'a'; i <= 'c'; i++) {
            if (!curr.empty() && i == curr.back()) {
                continue;
            }
            curr.push_back(i);
            generate(n, k, curr, strings);
            curr.pop_back();
            if (strings.size() == k) {
                return;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, std::string>> tests = {
        {{1, 3}, "c"},
        {{1, 4}, ""},
        {{3, 9}, "cab"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.getHappyString(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
