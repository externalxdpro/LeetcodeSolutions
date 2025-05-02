// 838. Push Dominoes
// Difficulty: Medium

// There are n dominoes in a line, and we place each domino vertically upright.
// In the beginning, we simultaneously push some of the dominoes either to the
// left or to the right.

// After each second, each domino that is falling to the left pushes the
// adjacent domino on the left. Similarly, the dominoes falling to the right
// push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays
// still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino
// expends no additional force to a falling or already fallen domino.

// You are given a string dominoes representing the initial state where:

//     dominoes[i] = 'L', if the ith domino has been pushed to the left,
//     dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//     dominoes[i] = '.', if the ith domino has not been pushed.

// Return a string representing the final state.

// Example 1:

// Input: dominoes = "RR.L"
// Output: "RR.L"
// Explanation: The first domino expends no additional force on the second
// domino.

// Example 2:

// Input: dominoes = ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."

// Constraints:

//     n == dominoes.length
//     1 <= n <= 105
//     dominoes[i] is either 'L', 'R', or '.'.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string pushDominoes(std::string dominoes) {
        std::vector<int> forces(dominoes.size());
        int              force = 0;
        for (int i = dominoes.size() - 1; i >= 0; i--) {
            char curr = dominoes[i];
            if (curr == 'L') {
                force = dominoes.size();
            } else if (curr == 'R') {
                force = 0;
            } else {
                force -= force > 0;
            }
            forces[i] = force;
        }
        force = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            char &curr = dominoes[i];
            if (curr == 'L') {
                force = 0;
            } else if (curr == 'R') {
                force = dominoes.size();
            } else {
                force -= force > 0;
                if (force > forces[i]) {
                    curr = 'R';
                } else if (force < forces[i]) {
                    curr = 'L';
                }
            }
        }
        return dominoes;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"RR.L", "RR.L"},
        {".L.R...LR..L..", "LL.RR.LLRRLL.."},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.pushDominoes(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
