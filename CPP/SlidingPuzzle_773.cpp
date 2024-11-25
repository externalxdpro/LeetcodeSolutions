// 773. Sliding Puzzle
// Difficulty: Hard

// On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty
// square represented by 0. A move consists of choosing 0 and a 4-directionally
// adjacent number and swapping it.

// The state of the board is solved if and only if the board is
// [[1,2,3],[4,5,0]].

// Given the puzzle board board, return the least number of moves required so
// that the state of the board is solved. If it is impossible for the state of
// the board to be solved, return -1.

// Example 1:

// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.

// Example 2:

// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.

// Example 3:

// Input: board = [[4,1,2],[5,0,3]]
// Output: 5
// Explanation: 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]

// Constraints:

//     board.length == 2
//     board[i].length == 3
//     0 <= board[i][j] <= 5
//     Each value board[i][j] is unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int slidingPuzzle(const std::vector<std::vector<int>> &board) {
        std::vector<std::vector<int>> dirs{{1, 3}, {0, 2, 4}, {1, 5},
                                           {0, 4}, {1, 3, 5}, {2, 4}};

        std::string target = "123450";
        std::string curr;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                curr.push_back(board[i][j] + '0');
            }
        }

        std::unordered_set<std::string> visited{curr};
        std::queue<std::string>         q{{curr}};
        int                             result = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                std::string front = q.front();
                q.pop();

                if (front == target) {
                    return result;
                }

                int pos = front.find('0');
                for (int dir : dirs[pos]) {
                    std::string next = front;
                    std::swap(next[pos], next[dir]);

                    if (visited.contains(next)) {
                        continue;
                    }

                    visited.insert(next);
                    q.push(next);
                }
            }
            result++;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{1, 2, 3}, {4, 0, 5}}, 1},
        {{{1, 2, 3}, {5, 4, 0}}, -1},
        {{{4, 1, 2}, {5, 0, 3}}, 5},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.slidingPuzzle(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
