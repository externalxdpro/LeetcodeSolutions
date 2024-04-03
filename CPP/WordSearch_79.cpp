// [79] Word Search
// Medium

// Given an m x n grid of characters board and a string word, return true if
// word exists in the grid. The word can be constructed from letters of
// sequentially adjacent cells, where adjacent cells are horizontally or
// vertically neighboring. The same letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// = "ABCCED" Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// = "SEE" Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// = "ABCB" Output: false

// Constraints:
//     m == board.length
//     n = board[i].length
//     1 <= m, n <= 6
//     1 <= word.length <= 15
//     board and word consists of only lowercase and uppercase English letters.

// Follow up: Could you use search pruning to make your solution faster with a
// larger board?

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool exist(std::vector<std::vector<char>> &board, std::string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (recurse(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool recurse(std::vector<std::vector<char>> &board, std::string &word,
                 int i, int j, int index) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index]) {
            return false;
        }

        char temp   = board[i][j];
        board[i][j] = ' ';

        if (recurse(board, word, i + 1, j, index + 1) ||
            recurse(board, word, i - 1, j, index + 1) ||
            recurse(board, word, i, j + 1, index + 1) ||
            recurse(board, word, i, j - 1, index + 1)) {
            return true;
        }

        board[i][j] = temp;
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::vector<std::vector<char>>, std::string>, bool>>
        tests = {
            {{{{'A', 'B', 'C', 'E'},
               {'S', 'F', 'C', 'S'},
               {'A', 'D', 'E', 'E'}},
              "ABCCED"},
             true},
            {{{{'A', 'B', 'C', 'E'},
               {'S', 'F', 'C', 'S'},
               {'A', 'D', 'E', 'E'}},
              "SEE"},
             true},
            {{{{'A', 'B', 'C', 'E'},
               {'S', 'F', 'C', 'S'},
               {'A', 'D', 'E', 'E'}},
              "ABCB"},
             false},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.exist(test.first, test.second);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
