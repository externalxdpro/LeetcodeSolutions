// Difficulty: Hard
// Given two strings s and t of lengths m and n respectively, return the minimum
// window substring of s such that every character in t (including duplicates)
// is included in the window. If there is no such substring, return the empty
// string "".
// The testcases will be generated such that the answer is unique.

// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
// from string t.

// Example 2:
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// Constraints:
//     m == s.length
//     n == t.length
//     1 <= m, n <= 10^5
//     s and t consist of uppercase and lowercase English letters.

// Follow up: Could you find an algorithm that runs in O(m + n) time?

#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string minWindow(std::string s, std::string t) {
        std::string minStr = "";

        std::unordered_map<char, int> occurencesT;
        for (char c : t) {
            occurencesT[c]++;
        }

        std::unordered_map<char, int> occurences;
        int                           l = 0;
        int                           r = 0;
        occurences[s[0]]++;

        while (l <= r && l < s.size() && r < s.size()) {
            bool bad = false;
            for (auto &[k, v] : occurencesT) {
                if (occurences[k] < v) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                while (occurences[s[l]] > occurencesT[s[l]]) {
                    occurences[s[l]]--;
                    l++;
                }
                if ((minStr.empty() || r - l + 1 < minStr.size())) {
                    std::string temp(s.begin() + l, s.begin() + r + 1);
                    minStr = temp;
                    occurences[s[l]]--;
                    l++;
                    continue;
                }
            }
            r++;
            occurences[s[r]]++;
        }

        return minStr;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, std::string>, std::string>>
        tests = {
            {{"ADOBECODEBANC", "ABC"}, "BANC"},
            {{"a", "a"}, "a"},
            {{"a", "aa"}, ""},
            {{"bbaa", "aba"}, "baa"},
            {{"aaaaaaaaaaaabbbbbcdd", "abcdd"}, "abbbbbcdd"},
            {{"wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtc"
              "wwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvt"
              "bphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzu"
              "rmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsm"
              "lanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwql"
              "nsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdij"
              "rnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnf"
              "tnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydha"
              "lrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewba"
              "mwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveey"
              "cpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvj"
              "vzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfio"
              "iebidxdzfpumyon",
              "ozgzyywxvtublcl"},
             "tcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanl"},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minWindow(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
