// 726. Number of Atoms
// Difficulty: Hard

// Given a string formula representing a chemical formula, return the count of
// each atom.
// The atomic element always starts with an uppercase character, then zero or
// more lowercase letters, representing the name.
// One or more digits representing that element's count may follow if the count
// is greater than 1. If the count is 1, no digits will follow.
//     For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
// Two formulas are concatenated together to produce another formula.
//     For example, "H2O2He3Mg4" is also a formula.
// A formula placed in parentheses, and a count (optionally added) is also a
// formula.
//     For example, "(H2O2)" and "(H2O2)3" are formulas.
// Return the count of all elements as a string in the following form: the first
// name (in sorted order), followed by its count (if that count is more than 1),
// followed by the second name (in sorted order), followed by its count (if that
// count is more than 1), and so on.
// The test cases are generated so that all the values in the output fit in a
// 32-bit integer.

// Example 1:
// Input: formula = "H2O"
// Output: "H2O"
// Explanation: The count of elements are {'H': 2, 'O': 1}.

// Example 2:
// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
// Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

// Example 3:
// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
// Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.

// Constraints:
//     1 <= formula.length <= 1000
//     formula consists of English letters, digits, '(', and ')'.
//     formula is always valid.

#include <algorithm>
#include <cctype>
#include <fmt/ranges.h>
#include <map>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string countOfAtoms(std::string formula) {
        int                                              len = formula.size();
        std::stack<std::unordered_map<std::string, int>> stack{{{}}};

        int i = 0;
        while (i < len) {
            if (formula[i] == '(') {
                stack.push({});
                i++;
            } else if (formula[i] == ')') {
                auto top = stack.top();
                stack.pop();
                i++;
                int beg = i;
                while (i < len && std::isdigit(formula[i])) {
                    i++;
                }
                int count =
                    beg < i ? std::stoi(formula.substr(beg, i - beg)) : 1;
                for (auto &[k, _] : top) {
                    stack.top()[k] += top[k] * count;
                }
            } else {
                int beg = i;
                i++;
                while (i < len && std::islower(formula[i])) {
                    i++;
                }
                std::string elem = formula.substr(beg, i - beg);
                beg              = i;
                while (i < len && std::isdigit(formula[i])) {
                    i++;
                }
                int count =
                    beg < i ? std::stoi(formula.substr(beg, i - beg)) : 1;
                stack.top()[elem] += count;
            }
        }

        std::map<std::string, int> map;
        std::stringstream          result;

        while (!stack.empty()) {
            for (auto &[k, v] : stack.top()) {
                map[k] += v;
            }
            stack.pop();
        }

        for (auto &[k, v] : map) {
            result << k;
            if (v > 1) {
                result << v;
            }
        }

        return result.str();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"H2O", "H2O"},
        {"Mg(OH)2", "H2MgO2"},
        {"K4(ON(SO3)2)2", "K4N2O14S4"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.countOfAtoms(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
