#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int getCommon(std::vector<int> &nums1, std::vector<int> &nums2) {
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 == *it2) {
                return *it1;
            }

            if (*it1 < *it2) {
                it1++;
            } else {
                it2++;
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, std::vector<int>>, int>>
        tests = {
            {{{1, 2, 3}, {2, 4}}, 2},
            {{{1, 2, 3, 6}, {2, 3, 4, 5}}, 2},
            {{{100, 200, 300}, {50, 100, 150, 200}}, 100},
            {{{2, 4, 6, 8, 10}, {1, 3, 5, 7, 9}}, -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.getCommon(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
