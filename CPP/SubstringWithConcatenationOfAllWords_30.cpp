#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<int> findSubstring(std::string               s,
                                   std::vector<std::string> &words) {
        if (s.size() < words[0].size() * words.size()) {
            return {};
        }

        std::unordered_set<std::string> substrings;
        std::vector<std::string>        temp = words;
        do {
            substrings.insert(
                std::accumulate(temp.begin(), temp.end(), std::string()));
            std::ranges::next_permutation(temp);
        } while (temp != words);

        std::vector<int> result;
        int              len = words[0].size() * words.size();

        for (int i = 0; i <= s.size() - words[0].size() * words.size(); i++) {
            if (substrings.contains(s.substr(i, len))) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::vector<std::string>>> tests = {
        {"barfoothefoobarman", {"foo", "bar"}},
        {"wordgoodgoodgoodbestword", {"word", "good", "best", "word"}},
        {"barfoofoobarthefoobarman", {"bar", "foo", "the"}},
        {"wordgoodgoodgoodbestword", {"word", "good", "best", "good"}},
        {"a", {"a", "a"}},
    };

    Solution solution;
    for (auto test : tests) {
        fmt::print("{}: {}\n", test,
                   solution.findSubstring(test.first, test.second));
    }

    return 0;
}
