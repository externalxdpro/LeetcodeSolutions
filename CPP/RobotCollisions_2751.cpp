// 2751. Robot Collisions
// Difficulty: Hard

// There are n 1-indexed robots, each having a position on a line, health, and
// movement direction.
// You are given 0-indexed integer arrays positions, healths, and a string
// directions (directions[i] is either 'L' for left or 'R' for right). All
// integers in positions are unique.
// All robots start moving on the line simultaneously at the same speed in their
// given directions. If two robots ever share the same position while moving,
// they will collide.
// If two robots collide, the robot with lower health is removed from the line,
// and the health of the other robot decreases by one. The surviving robot
// continues in the same direction it was going. If both robots have the same
// health, they are both removed from the line.
// Your task is to determine the health of the robots that survive the
// collisions, in the same order that the robots were given, i.e. final heath of
// robot 1 (if survived), final health of robot 2 (if survived), and so on. If
// there are no survivors, return an empty array.
// Return an array containing the health of the remaining robots (in the order
// they were given in the input), after no further collisions can occur.
// Note: The positions may be unsorted.

// Example 1:
// Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions =
// "RRRRR" Output: [2,17,9,15,10] Explanation: No collision occurs in this
// example, since all robots are moving in the same direction. So, the health of
// the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

// Example 2:
// Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
// Output: [14]
// Explanation: There are 2 collisions in this example. Firstly, robot 1 and
// robot 2 will collide, and since both have the same health, they will be
// removed from the line. Next, robot 3 and robot 4 will collide and since robot
// 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1
// = 14. Only robot 3 remains, so we return [14].

// Example 3:
// Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
// Output: []
// Explanation: Robot 1 and robot 2 will collide and since both have the same
// health, they are both removed. Robot 3 and 4 will collide and since both have
// the same health, they are both removed. So, we return an empty array, [].

// Constraints:
//     1 <= positions.length == healths.length == directions.length == n <= 10^5
//     1 <= positions[i], healths[i] <= 10^9
//     directions[i] == 'L' or directions[i] == 'R'
//     All values in positions are distinct

#include <algorithm>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

class Solution {
  public:
    std::vector<int> survivedRobotsHealths(std::vector<int> &positions,
                                           std::vector<int> &healths,
                                           std::string       directions) {
        std::vector<int>   stack;
        std::vector<tuple> robots(positions.size());

        for (int i = 0; i < positions.size(); i++) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }
        std::sort(robots.begin(), robots.end(),
                  [](tuple a, tuple b) { return a.pos < b.pos; });

        for (int i = 0; i < positions.size(); i++) {
            if (robots[i].dir == 'L') {
                while (!stack.empty() && robots[stack.back()].dir == 'R' &&
                       robots[stack.back()].hp < robots[i].hp) {
                    stack.pop_back();
                    robots[i].hp--;
                }
                if (stack.empty() || robots[stack.back()].dir == 'L') {
                    stack.push_back(i);
                } else if (!stack.empty() &&
                           robots[stack.back()].hp == robots[i].hp) {
                    stack.pop_back();
                } else if (!stack.empty() &&
                           robots[stack.back()].hp > robots[i].hp) {
                    robots[stack.back()].hp--;
                }
            } else {
                stack.push_back(i);
            }
        }

        std::sort(stack.begin(), stack.end(), [robots](int a, int b) {
            return robots[a].origI < robots[b].origI;
        });
        std::transform(stack.begin(), stack.end(), stack.begin(),
                       [robots](int i) { return robots[i].hp; });

        return stack;
    }

  private:
    struct tuple {
        int pos;
        int hp;
        int dir;
        int origI;
    };
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::tuple<std::vector<int>, std::vector<int>, std::string>,
                  std::vector<int>>>
        tests = {
            {{{5, 4, 3, 2, 1}, {2, 17, 9, 15, 10}, "RRRRR"},
             {2, 17, 9, 15, 10}},
            {{{3, 5, 2, 6}, {10, 10, 15, 12}, "RLRL"}, {14}},
            {{{1, 2, 5, 6}, {10, 10, 11, 11}, "RLRL"}, {}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.survivedRobotsHealths(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
