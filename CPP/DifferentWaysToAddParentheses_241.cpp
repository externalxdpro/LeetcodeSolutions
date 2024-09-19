// 241. Different Ways to Add Parentheses
// Difficulty: Medium

// Given a string expression of numbers and operators, return all possible
// results from computing all the different possible ways to group numbers and
// operators. You may return the answer in any order.
// The test cases are generated such that the output values fit in a 32-bit
// integer and the number of different results does not exceed 104.

// Example 1:
// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0
// (2-(1-1)) = 2

// Example 2:
// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10

// Constraints:
//     1 <= expression.length <= 20
//     expression consists of digits and the operator '+', '-', and '*'.
//     All the integer values in the input expression are in the range [0, 99].
//     The integer values in the input expression do not have a leading '-' or
//     '+' denoting the sign.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        return recurse(expression, 0, expression.size() - 1);
    }

  private:
    bool isNum(char c) { return c >= '0' && c <= '9'; }

    std::vector<int> recurse(std::string &exp, int i, int j) {
        if (i == j) {
            return {exp[i] - '0'};
        }
        if (j - i == 1 && isNum(exp[i]) && isNum(exp[j])) {
            return {(exp[i] - '0') * 10 + exp[j] - '0'};
        }

        std::vector<int> result;
        for (int k = i + 1; k < j; k++) {
            if (isNum(exp[k])) {
                continue;
            }
            std::vector<int> l = recurse(exp, i, k - 1),
                             r = recurse(exp, k + 1, j);

            for (int x : l) {
                for (int y : r) {
                    if (exp[k] == '*') {
                        result.push_back(x * y);
                    } else if (exp[k] == '+') {
                        result.push_back(x + y);
                    } else if (exp[k] == '-') {
                        result.push_back(x - y);
                    }
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::vector<int>>> tests = {
        {"2-1-1", {2, 0}},
        {"2*3-4*5", {-34, -10, -14, -10, 10}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.diffWaysToCompute(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
