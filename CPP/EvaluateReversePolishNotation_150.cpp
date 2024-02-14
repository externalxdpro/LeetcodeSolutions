#include <algorithm>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

class Solution {
  public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::stack<long> operands;
        for (std::string &i : tokens) {
            if (i == "+") {
                int two = operands.top();
                operands.pop();
                int one = operands.top();
                operands.pop();
                operands.push(one + two);
            } else if (i == "-") {
                int two = operands.top();
                operands.pop();
                int one = operands.top();
                operands.pop();
                operands.push(one - two);
            } else if (i == "*") {
                int two = operands.top();
                operands.pop();
                int one = operands.top();
                operands.pop();
                operands.push(one * two);

            } else if (i == "/") {
                int two = operands.top();
                operands.pop();
                int one = operands.top();
                operands.pop();
                operands.push(one / two);
            } else {
                operands.push(std::stol(i));
            }
        }

        return operands.top();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, int>> tests = {
        {{"2", "1", "+", "3", "*"}, 9},
        {{"4", "13", "5", "/", "+"}, 6},
        {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"},
         22},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.evalRPN(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
