// 874. Walking Robot Simulation
// Difficulty: Medium

// A robot on an infinite XY-plane starts at point (0, 0) facing north. The
// robot can receive a sequence of these three possible types of commands:
//     -2: Turn left 90 degrees.
//     -1: Turn right 90 degrees.
//     1 <= k <= 9: Move forward k units, one unit at a time.
// Some of the grid squares are obstacles. The ith obstacle is at grid point
// obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will
// instead stay in its current location and move on to the next command.
// Return the maximum Euclidean distance that the robot ever gets from the
// origin squared (i.e. if the distance is 5, return 25).

// Note:
//     North means +Y direction.
//     East means +X direction.
//     South means -Y direction.
//     West means -X direction.
//     There can be obstacle in [0,0].

// Example 1:
// Input: commands = [4,-1,3], obstacles = []
// Output: 25
// Explanation: The robot starts at (0, 0):
// 1. Move north 4 units to (0, 4).
// 2. Turn right.
// 3. Move east 3 units to (3, 4).
// The furthest point the robot ever gets from the origin is (3, 4), which
// squared is 32 + 42 = 25 units away.

// Example 2:
// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// Output: 65
// Explanation: The robot starts at (0, 0):
// 1. Move north 4 units to (0, 4).
// 2. Turn right.
// 3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at
// (1, 4).
// 4. Turn left.
// 5. Move north 4 units to (1, 8).
// The furthest point the robot ever gets from the origin is (1, 8), which
// squared is 12 + 82 = 65 units away.

// Example 3:
// Input: commands = [6,-1,-1,6], obstacles = []
// Output: 36
// Explanation: The robot starts at (0, 0):
// 1. Move north 6 units to (0, 6).
// 2. Turn right.
// 3. Turn right.
// 4. Move south 6 units to (0, 0).
// The furthest point the robot ever gets from the origin is (0, 6), which
// squared is 62 = 36 units away.

// Constraints:
//     1 <= commands.length <= 10^4
//     commands[i] is either -2, -1, or an integer in the range [1, 9].
//     0 <= obstacles.length <= 10^4
//     -3 * 10^4 <= xi, yi <= 3 * 10^4
//     The answer is guaranteed to be less than 2^31.

#include <algorithm>
#include <array>
#include <fmt/ranges.h>
#include <set>
#include <vector>

class Solution {
  public:
    int robotSim(std::vector<int>              &commands,
                 std::vector<std::vector<int>> &obstacles) {
        std::set<std::pair<int, int>> obs;
        for (auto i : obstacles) {
            obs.emplace(i[0], i[1]);
        }

        const std::array<std::pair<int, int>, 4> dirs = {
            {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
        int       dirI = 0;
        std::pair curr = {0, 0};
        int       max  = 0;
        for (int cmd : commands) {
            if (cmd == -2) {
                dirI = dirI == 0 ? 3 : dirI - 1;
            } else if (cmd == -1) {
                dirI = dirI == 3 ? 0 : dirI + 1;
            } else {
                std::pair<int, int> dir = dirs[dirI];
                for (int k = 0; k < cmd; k++) {
                    std::pair<int, int> next = {curr.first + dir.first,
                                                curr.second + dir.second};
                    if (obs.contains(next)) {
                        break;
                    }
                    curr = next;
                }
                max = std::max(max, curr.first * curr.first +
                                        curr.second * curr.second);
            }
        }

        return max;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<int>, std::vector<std::vector<int>>>, int>>
        tests = {
            {{{4, -1, 3}, {}}, 25},
            {{{4, -1, 4, -2, 4}, {{2, 4}}}, 65},
            {{{6, -1, -1, 6}, {}}, 36},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.robotSim(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
