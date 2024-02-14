#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int maxLength(std::vector<std::string> &arr) {
        int result = 0;
        dfs(arr, "", 0, result);
        return result;
    }

  private:
    void dfs(std::vector<std::string> &arr, std::string curr, int i,
             int &result) {
        bool unique = isUnique(curr);

        if (unique && curr.size() > result) {
            result = curr.size();
        }
        if (i == arr.size() || !unique) {
            return;
        }

        for (int j = i; j < arr.size(); j++) {
            dfs(arr, curr + arr[j], j + 1, result);
        }
    }

    bool isUnique(std::string str) {
        std::unordered_set<char> set(str.begin(), str.end());
        if (str.size() != set.size()) {
            return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::vector<std::string>> tests = {
        {"un", "iq", "ue"},
        {"cha", "r", "act", "ers"},
        {"abcdefghijklmnopqrstuvwxyz"},
    };

    Solution solution;
    for (auto &test : tests) {
        auto result = solution.maxLength(test);
        fmt::print("{}: {}\n", test, result);
    }

    return 0;
}
