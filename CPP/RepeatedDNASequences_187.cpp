// 187. Repeated DNA Sequences
// Difficulty: Medium

// The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
// 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the
// DNA.

// Given a string s that represents a DNA sequence, return all the
// 10-letter-long sequences (substrings) that occur more than once in a DNA
// molecule. You may return the answer in any order.

// Example 1:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]
// Example 2:

// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]

// Constraints:

// 1 <= s.length <= 105
// s[i] is either 'A', 'C', 'G', or 'T'.

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::string> findRepeatedDnaSequences(std::string &s) {
        if (s.size() <= 10) {
            return {};
        }

        std::string curr = s.substr(0, 10);
        std::unordered_map<std::string, int> seen{{curr, 1}};
        for (size_t i = 10; i < s.size(); i++) {
            curr.erase(0, 1);
            curr.push_back(s[i]);
            seen[curr]++;
        }

        std::vector<std::string> result;
        for (auto &[k, v] : seen) {
            if (v > 1) {
                result.push_back(k);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::vector<std::string>>> tests = {
        {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", {"AAAAACCCCC", "CCCCCAAAAA"}},
        {"AAAAAAAAAAAAA", {"AAAAAAAAAA"}},
    };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findRepeatedDnaSequences(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
