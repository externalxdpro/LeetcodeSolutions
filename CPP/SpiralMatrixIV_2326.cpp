// 2326. Spiral Matrix IV
// Difficulty: Medium

// You are given two integers m and n, which represent the dimensions of a
// matrix.
// You are also given the head of a linked list of integers.
// Generate an m x n matrix that contains the integers in the linked list
// presented in spiral order (clockwise), starting from the top-left of the
// matrix. If there are remaining empty spaces, fill them with -1.
// Return the generated matrix.

// Example 1:
// Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
// Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
// Explanation: The diagram above shows how the values are printed in the
// matrix. Note that the remaining spaces in the matrix are filled with -1.

// Example 2:
// Input: m = 1, n = 4, head = [0,1,2]
// Output: [[0,1,2,-1]]
// Explanation: The diagram above shows how the values are printed from left to
// right in the matrix. The last space in the matrix is set to -1.

// Constraints:
//     1 <= m, n <= 10^5
//     1 <= m * n <= 10^5
//     The number of nodes in the list is in the range [1, m * n].
//     0 <= Node.val <= 1000

#include "_LinkedList.hpp"

#include <array>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        std::vector<std::vector<int>>            result(m, std::vector(n, -1));
        const std::array<std::pair<int, int>, 4> dirs{
            {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
        int diri = 0;
        int i = 0, j = 0;
        while (head != nullptr) {
            result[i][j] = head->val;
            if (head->next == nullptr) {
                break;
            }
            auto &dir = dirs[diri];
            int   ni = i + dir.first, nj = j + dir.second;
            if (ni < 0 || ni >= m || nj < 0 || nj >= n ||
                result[ni][nj] != -1) {
                diri = (diri + 1) % 4;
                continue;
            }
            head = head->next;
            i = ni, j = nj;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<int, int, std::vector<int>>,
                          std::vector<std::vector<int>>>>
        tests = {{{3, 5, {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0}},
                  {{3, 0, 2, 6, 8}, {5, 0, -1, -1, 1}, {5, 2, 4, 9, 7}}},
                 {{1, 4, {0, 1, 2}}, {{0, 1, 2, -1}}},
                 {{10, 1, {8, 24, 5, 21, 10, 11, 11, 12, 6, 17}},
                  {{8}, {24}, {5}, {21}, {10}, {11}, {11}, {12}, {6}, {17}}}};

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.spiralMatrix(std::get<0>(test), std::get<1>(test),
                                  toLinkedList(std::get<2>(test)));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
