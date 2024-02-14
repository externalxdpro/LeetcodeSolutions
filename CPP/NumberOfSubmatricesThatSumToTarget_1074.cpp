#include <algorithm>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>> &matrix,
                              int                            target) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int count = 0;
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = i; j < matrix[0].size(); j++) {
                std::unordered_map<int, int> map;
                map[0] = 1;

                int sum = 0;
                for (int k = 0; k < matrix.size(); k++) {
                    sum += matrix[k][j];
                    if (i > 0) {
                        sum -= matrix[k][i - 1];
                    }

                    count += map[sum - target];
                    map[sum]++;
                }
            }
        }

        return count;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}}, 0},
        {{{1, -1}, {-1, 1}}, 0},
        {{{904}}, 0},
    };

    Solution solution;
    for (auto &test : tests) {
        fmt::print("{}: ", test);
        auto result = solution.numSubmatrixSumTarget(test.first, test.second);
        fmt::print("{}\n", result);
    }

    return 0;
}
