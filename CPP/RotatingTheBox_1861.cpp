// 1861. Rotating the Box
// Difficulty: Medium

// You are given an m x n matrix of characters box representing a side-view of a
// box. Each cell of the box is one of the following:

//     A stone '#'
//     A stationary obstacle '*'
//     Empty '.'

// The box is rotated 90 degrees clockwise, causing some of the stones to fall
// due to gravity. Each stone falls down until it lands on an obstacle, another
// stone, or the bottom of the box. Gravity does not affect the obstacles'
// positions, and the inertia from the box's rotation does not affect the
// stones' horizontal positions.

// It is guaranteed that each stone in box rests on an obstacle, another stone,
// or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described
// above.

// Example 1:

// Input: box = [["#",".","#"]]
// Output: [["."],
//          ["#"],
//          ["#"]]

// Example 2:

// Input: box = [["#",".","*","."],
//               ["#","#","*","."]]
// Output: [["#","."],
//          ["#","#"],
//          ["*","*"],
//          [".","."]]

// Example 3:

// Input: box = [["#","#","*",".","*","."],
//               ["#","#","#","*",".","."],
//               ["#","#","#",".","#","."]]
// Output: [[".","#","#"],
//          [".","#","#"],
//          ["#","#","*"],
//          ["#","*","."],
//          ["#",".","*"],
//          ["#",".","."]]

// Constraints:

//     m == box.length
//     n == box[i].length
//     1 <= m, n <= 500
//     box[i][j] is either '#', '*', or '.'.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<char>>
    rotateTheBox(const std::vector<std::vector<char>> &box) {
        std::vector<std::vector<char>> result(box[0].size(),
                                              std::vector(box.size(), '.'));

        for (int i = 0; i < box[0].size(); i++) {
            for (int j = 0; j < box.size(); j++) {
                result[i][j] = box[box.size() - j - 1][i];
            }
        }

        for (int j = 0; j < box.size(); j++) {
            int place = box[0].size() - 1;
            for (int i = box[0].size() - 1; i >= 0; i--) {
                if (result[i][j] == '#') {
                    result[i][j]     = '.';
                    result[place][j] = '#';
                    place--;
                }
                if (result[i][j] == '*') {
                    place = i - 1;
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<char>>,
                          std::vector<std::vector<char>>>>
        tests = {
            {{{'#', '.', '#'}}, {{'.'}, {'#'}, {'#'}}},
            {{{'#', '.', '*', '.'}, {'#', '#', '*', '.'}},
             {{'#', '.'}, {'#', '#'}, {'*', '*'}, {'.', '.'}}},
            {{{'#', '#', '*', '.', '*', '.'},
              {'#', '#', '#', '*', '.', '.'},
              {'#', '#', '#', '.', '#', '.'}},
             {{'.', '#', '#'},
              {'.', '#', '#'},
              {'#', '#', '*'},
              {'#', '*', '.'},
              {'#', '.', '*'},
              {'#', '.', '.'}}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.rotateTheBox(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
