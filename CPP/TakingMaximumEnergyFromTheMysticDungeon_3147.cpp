// 3147. Taking Maximum Energy From the Mystic Dungeon
// Difficulty: Medium

// In a mystic dungeon, n magicians are standing in a line. Each magician has an
// attribute that gives you energy. Some magicians can give you negative energy,
// which means taking energy from you.

// You have been cursed in such a way that after absorbing energy from magician
// i, you will be instantly transported to magician (i + k). This process will
// be repeated until you reach the magician where (i + k) does not exist.

// In other words, you will choose a starting point and then teleport with k
// jumps until you reach the end of the magicians' sequence, absorbing all the
// energy during the journey.

// You are given an array energy and an integer k. Return the maximum possible
// energy you can gain.

// Note that when you are reach a magician, you must take energy from them,
// whether it is negative or positive energy.

// Example 1:

// Input: energy = [5,2,-10,-5,1], k = 3

// Output: 3

// Explanation: We can gain a total energy of 3 by starting from magician 1
// absorbing 2 + 1 = 3.

// Example 2:

// Input: energy = [-2,-3,-1], k = 2

// Output: -1

// Explanation: We can gain a total energy of -1 by starting from magician 2.

// Constraints:

//     1 <= energy.length <= 105
//     -1000 <= energy[i] <= 1000
//     1 <= k <= energy.length - 1

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    int maximumEnergy(std::vector<int> &energy, int k) {
        int result = INT_MIN;
        for (size_t i = energy.size() - k; i < energy.size(); i++) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += energy[j];
                result = std::max(result, sum);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{5, 2, -1, -5, 1}, 3}, 3},
        {{{-2, -3, -1}, 2}, -1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumEnergy(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
