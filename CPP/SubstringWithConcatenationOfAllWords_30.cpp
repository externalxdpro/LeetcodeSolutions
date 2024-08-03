#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int> findSubstring(std::string               s,
                                   std::vector<std::string> &words) {
        if (words[0].size() > s.size()) {
            return {};
        }

        std::unordered_map<std::string, int> map;
        std::vector<int>                     result;
        const int                            length = words[0].size();

        for (std::string &word : words) {
            map[word]++;
        }

        for (int offset = 0; offset < length; offset++) {
            int                                  size = 0;
            std::unordered_map<std::string, int> seen;

            for (int i = offset; i <= s.size() - length; i += length) {
                std::string substr = s.substr(i, length);

                if (map.find(substr) == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                seen[substr]++;
                size++;

                while (seen[substr] > map.find(substr)->second) {
                    std::string first =
                        s.substr(i - (size - 1) * length, length);
                    seen[first]--;
                    size--;
                }

                if (size == words.size()) {
                    result.push_back(i - (size - 1) * length);
                }
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
