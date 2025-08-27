// 3459. Length of Longest V-Shaped Diagonal Segment
// Difficulty: Hard

// You are given a 2D integer matrix grid of size n x m, where each element is
// either 0, 1, or 2.

// A V-shaped diagonal segment is defined as:

//     The segment starts with 1.
//     The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
//     The segment:
//         Starts along a diagonal direction (top-left to bottom-right,
//         bottom-right to top-left, top-right to bottom-left, or bottom-left to
//         top-right). Continues the sequence in the same diagonal direction.
//         Makes at most one clockwise 90-degree turn to another diagonal
//         direction while maintaining the sequence.

// Return the length of the longest V-shaped diagonal segment. If no valid
// segment exists, return 0.

// Example 1:

// Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

// Output: 5

// Explanation:

// The longest V-shaped diagonal segment has a length of 5 and follows these
// coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at
// (2,4), and continues as (3,3) → (4,2).

// Example 2:

// Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

// Output: 4

// Explanation:

// The longest V-shaped diagonal segment has a length of 4 and follows these
// coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and
// continues as (2,1) → (1,0).

// Example 3:

// Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]

// Output: 5

// Explanation:

// The longest V-shaped diagonal segment has a length of 5 and follows these
// coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).

// Example 4:

// Input: grid = [[1]]

// Output: 1

// Explanation:

// The longest V-shaped diagonal segment has a length of 1 and follows these
// coordinates: (0,0).

// Constraints:

//     n == grid.length
//     m == grid[i].length
//     1 <= n, m <= 500
//     grid[i][j] is either 0, 1 or 2.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
    int n, m;
    std::pair<int, int> dirs[4] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

  public:
    int lenOfVDiagonal(std::vector<std::vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        int memo[501][501][4][2];
        memset(memo, -1, sizeof(memo));

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        result = std::max(
                            result,
                            recurse(grid, i, j, dir, true, 2, memo) + 1);
                    }
                }
            }
        }
        return result;
    }

  private:
    int recurse(std::vector<std::vector<int>> &grid, int i, int j, int dir,
                bool turn, int target, int memo[501][501][4][2]) {
        int di = i + dirs[dir].first, dj = j + dirs[dir].second;
        if (di < 0 || di >= n || dj < 0 || dj >= m || grid[di][dj] != target) {
            return 0;
        }
        if (memo[di][dj][dir][turn] != -1) {
            return memo[di][dj][dir][turn];
        }

        int max = recurse(grid, di, dj, dir, turn, 2 - target, memo);
        if (turn) {
            max = std::max(max, recurse(grid, di, dj, (dir + 1) % 4, false,
                                        2 - target, memo));
        }
        return memo[di][dj][dir][turn] = max + 1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{2, 2, 1, 2, 2},
          {2, 0, 2, 2, 0},
          {2, 0, 1, 1, 0},
          {1, 0, 2, 2, 2},
          {2, 0, 0, 2, 2}},
         5},
        {{{2, 2, 2, 2, 2},
          {2, 0, 2, 2, 0},
          {2, 0, 1, 1, 0},
          {1, 0, 2, 2, 2},
          {2, 0, 0, 2, 2}},
         4},
        {{{1, 2, 2, 2, 2},
          {2, 2, 2, 2, 0},
          {2, 0, 0, 0, 0},
          {0, 0, 2, 2, 2},
          {2, 0, 0, 2, 0}},
         5},
        {{{1}}, 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.lenOfVDiagonal(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
