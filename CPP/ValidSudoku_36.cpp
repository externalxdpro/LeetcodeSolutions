// Difficulty: Medium

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
// validated according to the following rules:
//     Each row must contain the digits 1-9 without repetition.
//     Each column must contain the digits 1-9 without repetition.
//     Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
//     without repetition.

// Note:
//     A Sudoku board (partially filled) could be valid but is not necessarily
//     solvable. Only the filled cells need to be validated according to the
//     mentioned rules.

// Example 1:
// Input: board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true

// Example 2:
// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner
// being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
// is invalid.

// Constraints:
//     board.length == 9
//     board[i].length == 9
//     board[i][j] is a digit 1-9 or '.'.

#include <iostream>
#include <map>
#include <utility>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
    const int BOARD_DIMS = 9;
    // rows
    for (auto i : board) {
        std::map<char, int> found;
        for (auto j : i) {
            if (j == '.')
                continue;
            if (found[j])
                return false;
            found[j]++;
        }
    }

    // columns
    for (int j = 0; j < BOARD_DIMS; j++) {
        std::map<char, int> found;
        for (int i = 0; i < BOARD_DIMS; i++) {
            if (board[i][j] == '.')
                continue;
            if (found[board[i][j]])
                return false;
            found[board[i][j]]++;
        }
    }

    // sub-boxes
    std::vector<int> pos = {0, 3, 6, 9};

    for (int rowStart = 0; rowStart < pos.size() - 1; rowStart++) {
        for (int colStart = 0; colStart < pos.size() - 1; colStart++) {
            std::map<char, int> found;
            for (int i = pos[rowStart]; i < pos[rowStart + 1]; i++) {
                for (int j = pos[colStart]; j < pos[colStart + 1]; j++) {
                    if (board[i][j] == '.')
                        continue;
                    if (found[board[i][j]])
                        return false;
                    found[board[i][j]]++;
                }
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<std::vector<char>>> tests = {
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
        {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
    };

    for (auto test : tests) {
        std::cout << isValidSudoku(test) << std::endl;
    }

    return 0;
}
