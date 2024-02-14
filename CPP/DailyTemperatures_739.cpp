// Difficulty: Medium
// Given an array of integers temperatures represents the daily temperatures,
// return an array answer such that answer[i] is the number of days you have to
// wait after the ith day to get a warmer temperature. If there is no future day
// for which this is possible, keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Constraints:
//     1 <= temperatures.length <= 10^5
//     30 <= temperatures[i] <= 100

#include <algorithm>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

// Brute-force
// class Solution {
//   public:
//     std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
//         std::vector<int> result(temperatures.size(), 0);

//         for (int i = 0; i < temperatures.size(); i++) {
//             for (int j = i + 1; j < temperatures.size(); j++) {
//                 if (temperatures[j] > temperatures[i]) {
//                     result[i] = j - i;
//                     break;
//                 }
//             }
//         }

//         return result;
//     }
// };

// Optimized w/ stack
class Solution {
  public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int>  indices;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!indices.empty() &&
                   temperatures[indices.top()] < temperatures[i]) {
                result[indices.top()] = i - indices.top();
                indices.pop();
            }
            indices.push(i);
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}},
        {{30, 40, 50, 60}, {1, 1, 1, 0}},
        {{30, 60, 90}, {1, 1, 0}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.dailyTemperatures(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
