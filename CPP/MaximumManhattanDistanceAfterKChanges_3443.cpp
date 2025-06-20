// 3443. Maximum Manhattan Distance After K Changes
// Difficulty: Medium

// You are given a string s consisting of the characters 'N', 'S', 'E', and 'W',
// where s[i] indicates movements in an infinite grid:

//     'N' : Move north by 1 unit.
//     'S' : Move south by 1 unit.
//     'E' : Move east by 1 unit.
//     'W' : Move west by 1 unit.

// Initially, you are at the origin (0, 0). You can change at most k characters
// to any of the four directions.

// Find the maximum Manhattan distance from the origin that can be achieved at
// any time while performing the movements in order. The Manhattan Distance
// between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

// Example 1:

// Input: s = "NWSE", k = 1

// Output: 3

// Explanation:

// Change s[2] from 'S' to 'N'. The string s becomes "NWNE".
// Movement	Position (x, y)	Manhattan Distance	Maximum
// s[0] == 'N'	(0, 1)	0 + 1 = 1	1
// s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
// s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
// s[3] == 'E'	(0, 2)	0 + 2 = 2	3

// The maximum Manhattan distance from the origin that can be achieved is 3.
// Hence, 3 is the output.

// Example 2:

// Input: s = "NSWWEW", k = 3

// Output: 6

// Explanation:

// Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes
// "NNWWWW".

// The maximum Manhattan distance from the origin that can be achieved is 6.
// Hence, 6 is the output.

// Constraints:

//     1 <= s.length <= 105
//     0 <= k <= s.length
//     s consists of only 'N', 'S', 'E', and 'W'.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maxDistance(std::string str, int k) {
        int n = 0, w = 0, s = 0, e = 0;
        int result = 0;
        for (char c : str) {
            if (c == 'N') {
                n++;
            } else if (c == 'W') {
                w++;
            } else if (c == 'S') {
                s++;
            } else {
                e++;
            }

            int ns = std::min({n, s, k});
            int we = std::min({w, e, k - ns});

            result = std::max(result, dist(n, s, ns) + dist(w, e, we));
        }
        return result;
    }

  private:
    int dist(int dir1, int dir2, int min) {
        return std::abs(dir1 - dir2) + min * 2;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, int>> tests = {
        {{"NWSE", 1}, 3},
        {{"NSWWEW", 3}, 6},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxDistance(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
