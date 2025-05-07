// 3341. Find Minimum Time to Reach Last Room I
// Difficulty: Medium

// There is a dungeon with n x m rooms arranged as a grid.

// You are given a 2D array moveTime of size n x m, where moveTime[i][j]
// represents the minimum time in seconds when you can start moving to that
// room. You start from the room (0, 0) at time t = 0 and can move to an
// adjacent room. Moving between adjacent rooms takes exactly one second.

// Return the minimum time to reach the room (n - 1, m - 1).

// Two rooms are adjacent if they share a common wall, either horizontally or
// vertically.

// Example 1:

// Input: moveTime = [[0,4],[4,4]]

// Output: 6

// Explanation:

// The minimum time required is 6 seconds.

//     At time t == 4, move from room (0, 0) to room (1, 0) in one second.
//     At time t == 5, move from room (1, 0) to room (1, 1) in one second.

// Example 2:

// Input: moveTime = [[0,0,0],[0,0,0]]

// Output: 3

// Explanation:

// The minimum time required is 3 seconds.

//     At time t == 0, move from room (0, 0) to room (1, 0) in one second.
//     At time t == 1, move from room (1, 0) to room (1, 1) in one second.
//     At time t == 2, move from room (1, 1) to room (1, 2) in one second.

// Example 3:

// Input: moveTime = [[0,1],[1,2]]

// Output: 3

// Constraints:

//     2 <= n == moveTime.length <= 50
//     2 <= m == moveTime[i].length <= 50
//     0 <= moveTime[i][j] <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <queue>
#include <vector>

// using namespace std;

// using int3            = tuple<int, int, int>; // (time, i, j)
// const static int d[5] = {0, 1, 0, -1, 0};
// class Solution {
//   public:
//     inline static bool isOutside(int i, int j, int n, int m) {
//         return i < 0 || i >= n || j < 0 || j >= m;
//     }

//     static int minTimeToReach(vector<vector<int>> &moveTime) {
//         int                 n = moveTime.size(), m = moveTime[0].size();
//         vector<vector<int>> time(n, vector<int>(m, INT_MAX));
//         priority_queue<int3, vector<int3>, greater<int3>> pq;

//         // Start at (0, 0) with time 0
//         pq.emplace(0, 0, 0);
//         time[0][0] = 0;

//         while (!pq.empty()) {
//             auto [t, i, j] = pq.top();
//             pq.pop();

//             // reach the destination
//             if (i == n - 1 && j == m - 1)
//                 return t;

//             // Traverse all four directions
//             for (int a = 0; a < 4; a++) {
//                 int r = i + d[a], s = j + d[a + 1];
//                 if (isOutside(r, s, n, m))
//                     continue;

//                 // minimum time to reach (r, s)
//                 int nextTime = max(t, moveTime[r][s]) + 1; // Wait if
//                 necessary

//                 // update if this path having quicker time
//                 if (nextTime < time[r][s]) {
//                     time[r][s] = nextTime;
//                     pq.emplace(nextTime, r, s);
//                 }
//             }
//         }

//         return -1; // never reach
//     }
// };

class Solution {
    using state       = std::tuple<int, int, int>;
    const int DIRS[5] = {0, 1, 0, -1, 0};

  public:
    int minTimeToReach(std::vector<std::vector<int>> &moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        std::vector<std::vector<int>> time(
            n, std::vector(m, std::numeric_limits<int>::max()));
        std::priority_queue<state, std::vector<state>, std::greater<state>> pq;

        pq.emplace(0, 0, 0);
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1) {
                return t;
            }

            for (int d = 0; d < 4; d++) {
                int di = i + DIRS[d], dj = j + DIRS[d + 1];
                if (!inBounds(di, dj, n, m)) {
                    continue;
                }
                int dt = std::max(t, moveTime[di][dj]) + 1;
                if (dt < time[di][dj]) {
                    time[di][dj] = dt;
                    pq.emplace(dt, di, dj);
                }
            }
        }

        return -1;
    }

  private:
    bool inBounds(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::vector<int>>, int>> tests = {
        {{{0, 4}, {4, 4}}, 6},
        {{{0, 0, 0}, {0, 0, 0}}, 3},
        {{{0, 1}, {1, 2}}, 3},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minTimeToReach(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
