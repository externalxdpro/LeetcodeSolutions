#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();

        std::vector<std::vector<int>> memo(n, std::vector(m, 0));
        for (size_t i = 0; i < n; i++) {
            memo[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        for (size_t j = 0; j < m; j++) {
            memo[0][j] = matrix[0][j] == '1' ? 1 : 0;
        }

        for (size_t i = 1; i < n; i++) {
            for (size_t j = 1; j < m; j++) {
                if (matrix[i][j] == '1') {
                    memo[i][j] = std::min({memo[i - 1][j], memo[i][j - 1],
                                           memo[i - 1][j - 1]}) +
                                 1;
                }
            }
        }

        int max = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                max = std::max(max, memo[i][j] * memo[i][j]);
            }
        }
        return max;
    }
};

// code_end
