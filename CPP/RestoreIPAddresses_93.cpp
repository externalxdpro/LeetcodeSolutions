// 93. Restore IP Addresses
// Difficulty: Medium

// A valid IP address consists of exactly four integers separated by single
// dots. Each integer is between 0 and 255 (inclusive) and cannot have leading
// zeros.
//     For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
//     "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
//     addresses.
// Given a string s containing only digits, return all possible valid IP
// addresses that can be formed by inserting dots into s. You are not allowed to
// reorder or remove any digits in s. You may return the valid IP addresses in
// any order.

// Example 1:
// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]

// Example 2:
// Input: s = "0000"
// Output: ["0.0.0.0"]

// Example 3:
// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

// Constraints:
//     1 <= s.length <= 20
//     s consists of digits only.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<int>         dots;
        std::vector<std::string> result;
        recurse(s, 0, dots, result);
        return result;
    }

  private:
    void recurse(const std::string &s, int i, std::vector<int> &dots,
                 std::vector<std::string> &result) {
        int remLen  = s.size() - i;
        int remDots = 4 - dots.size();

        if (remLen > remDots * 3 || remLen < remDots) {
            return;
        }
        if (dots.size() == 3) {
            if (valid(s, i, remLen)) {
                std::string temp;
                int         last = 0;
                for (int dot : dots) {
                    temp.append(s.substr(last, dot));
                    last += dot;
                    temp.push_back('.');
                }
                temp.append(s.substr(i));
                result.push_back(temp);
            }
            return;
        }

        for (int j = 1; j <= 3 && j <= remLen; j++) {
            dots.push_back(j);
            if (valid(s, i, j)) {
                recurse(s, i + j, dots, result);
            }
            dots.pop_back();
        }
    }

    bool valid(const std::string &s, int i, int len) {
        return len == 1 ||
               (s[i] != '0' && (len < 3 || s.substr(i, len) <= "255"));
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::vector<std::string>>> tests = {
        {"25525511135", {"255.255.11.135", "255.255.111.35"}},
        {"0000", {"0.0.0.0"}},
        {"101023",
         {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.restoreIpAddresses(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
