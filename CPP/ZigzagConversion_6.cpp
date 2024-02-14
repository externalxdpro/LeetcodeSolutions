#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    std::string convert(std::string s, int numRows) {
        std::vector<std::string> rows(numRows);

        int i = 0;
        while (i < s.size()) {
            for (int rowI = 0; rowI < numRows && i < s.size(); rowI++) {
                rows[rowI] += s[i];
                i++;
            }
            for (int rowI = numRows - 2; rowI > 0 && i < s.size(); rowI--) {
                rows[rowI] += s[i];
                i++;
            }
        }

        return std::accumulate(rows.begin(), rows.end(), std::string());
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, std::string>> tests = {
        {{"PAYPALISHIRING", 3}, "PAHNAPLSIIGYIR"},
        {{"PAYPALISHIRING", 4}, "PINALSIGYAHRPI"},
        {{"A", 1}, "A"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.convert(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
