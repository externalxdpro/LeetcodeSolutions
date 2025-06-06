// 781. Rabbits in Forest
// Difficulty: Medium

// There is a forest with an unknown number of rabbits. We asked n rabbits "How
// many rabbits have the same color as you?" and collected the answers in an
// integer array answers where answers[i] is the answer of the ith rabbit.

// Given the array answers, return the minimum number of rabbits that could be
// in the forest.

// Example 1:

// Input: answers = [1,1,2]
// Output: 5
// Explanation:
// The two rabbits that answered "1" could both be the same color, say red.
// The rabbit that answered "2" can't be red or the answers would be
// inconsistent. Say the rabbit that answered "2" was blue. Then there should be
// 2 other blue rabbits in the forest that didn't answer into the array. The
// smallest possible number of rabbits in the forest is therefore 5: 3 that
// answered plus 2 that didn't.

// Example 2:

// Input: answers = [10,10,10]
// Output: 11

// Constraints:

//     1 <= answers.length <= 1000
//     0 <= answers[i] < 1000

#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int numRabbits(std::vector<int> &answers) {
        std::unordered_map<int, int> counts;
        for (int num : answers) {
            counts[num]++;
        }

        int result = 0;
        for (auto &[num, count] : counts) {
            result += std::ceil((double)count / (num + 1)) * (num + 1);
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, int>> tests = {
        {{1, 1, 2}, 5},
        {{10, 10, 10}, 11},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numRabbits(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
