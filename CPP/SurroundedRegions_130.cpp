// 130. Surrounded Regions
// Difficulty: Medium

// You are given an m x n matrix board containing letters 'X' and 'O', capture
// regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: A region is surrounded if none of the 'O' cells in that region are
// on the edge of the board. Such regions are completely enclosed by 'X' cells.
// To capture a surrounded region, replace all 'O's with 'X's in-place within
// the original board. You do not need to return anything.

// Example 1:

// Input: board =
// [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output:
// [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:

// In the above diagram, the bottom region is not captured because it is on the
// edge of the board and cannot be surrounded.

// Example 2:

// Input: board = [["X"]]

// Output: [["X"]]

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    void solve(std::vector<std::vector<char>> &board) {
        for (size_t i = 0; i < board.size(); i++) {
            dfs(board, i, 0);
            dfs(board, i, board[i].size() - 1);
        }
        for (size_t j = 0; j < board[0].size(); j++) {
            dfs(board, 0, j);
            dfs(board, board.size() - 1, j);
        }

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }

  private:
    void dfs(std::vector<std::vector<char>> &board, size_t i, size_t j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return;
        }
        if (board[i][j] == 'S' || board[i][j] == 'X') {
            return;
        }
        board[i][j] = 'S';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<char>>,
                          std::vector<std::vector<char>>>>
        tests = {
            {{{'X', 'X', 'X', 'X'},
              {'X', 'O', 'O', 'X'},
              {'X', 'X', 'O', 'X'},
              {'X', 'O', 'X', 'X'}},
             {{'X', 'X', 'X', 'X'},
              {'X', 'X', 'X', 'X'},
              {'X', 'X', 'X', 'X'},
              {'X', 'O', 'X', 'X'}}},
            {{{'X'}}, {{'X'}}},
            {{{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}},
             {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto tmp = test;
        solution.solve(test);
        fmt::println("{} {}: {}", test == ans ? "✅" : "❌", tmp, test);
    }

    return 0;
}
