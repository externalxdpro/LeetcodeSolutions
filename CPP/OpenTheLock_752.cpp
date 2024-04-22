// [752] Open the Lock
// Medium

// You have a lock in front of you with 4 circular wheels. Each wheel has 10
// slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can
// rotate freely and wrap around: for example we can turn '9' to be '0', or '0'
// to be '9'. Each move consists of turning one wheel one slot.
// The lock initially starts at '0000', a string representing the state of the 4
// wheels.
// You are given a list of deadends dead ends, meaning if the lock displays any
// of these codes, the wheels of the lock will stop turning and you will be
// unable to open it.
// Given a target representing the value of the wheels that will unlock the
// lock, return the minimum total number of turns required to open the lock, or
// -1 if it is impossible.

// Example 1:
// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation:
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" ->
// "1201" -> "1202" -> "0202". Note that a sequence like "0000" -> "0001" ->
// "0002" -> "0102" -> "0202" would be invalid, because the wheels of the lock
// become stuck after the display becomes the dead end "0102".

// Example 2:
// Input: deadends = ["8888"], target = "0009"
// Output: 1
// Explanation: We can turn the last wheel in reverse to move from "0000" ->
// "0009".

// Example 3:
// Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
// target = "8888" Output: -1 Explanation: We cannot reach the target without
// getting stuck.

// Constraints:
//     1 <= deadends.length <= 500
//     deadends[i].length == 4
//     target.length == 4
//     target will not be in the list deadends.
//     target and deadends[i] consist of digits only.

#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int openLock(std::vector<std::string> &deadends, std::string target) {
        if (target == "0000") {
            return 0;
        }

        std::queue<int> q({0});
        bool            seen[10000] = {false};
        for (const std::string &d : deadends) {
            seen[std::stoi(d)] = true;
        }
        if (seen[0]) {
            return -1;
        }
        int t = std::stoi(target);

        for (int res = 1; q.size(); res++) {
            for (int size = q.size(); size > 0; size--) {
                int front = q.front();
                q.pop();
                for (int i = 1; i < 10000; i *= 10) {
                    int mask   = front % (i * 10) / i;
                    int masked = front - (mask * i);
                    for (int j = 1; j < 10; j += 8) {
                        int next = masked + (mask + j) % 10 * i;
                        if (seen[next]) {
                            continue;
                        }
                        if (next == t) {
                            return res;
                        }
                        seen[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::tuple<std::vector<std::string>, std::string>, int>>
        tests = {
            {{{"0201", "0101", "0102", "1212", "2002"}, "0202"}, 6},
            {{{"8888"}, "0009"}, 1},
            {{{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"},
              "8888"},
             -1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.openLock(std::get<0>(test), std::get<1>(test));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
