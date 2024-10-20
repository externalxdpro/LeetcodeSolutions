// 1106. Parsing A Boolean Expression
// Difficulty: Hard

// A boolean expression is an expression that evaluates to either true or false.
// It can be in one of the following shapes:

//     't' that evaluates to true.
//     'f' that evaluates to false.
//     '!(subExpr)' that evaluates to the logical NOT of the inner expression
//     subExpr.
//     '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND
//     of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
//     '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR
//     of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.

// Given a string expression that represents a boolean expression, return the
// evaluation of that expression.

// It is guaranteed that the given expression is valid and follows the given
// rules.

// Example 1:

// Input: expression = "&(|(f))"
// Output: false
// Explanation:
// First, evaluate |(f) --> f. The expression is now "&(f)".
// Then, evaluate &(f) --> f. The expression is now "f".
// Finally, return false.

// Example 2:

// Input: expression = "|(f,f,f,t)"
// Output: true
// Explanation: The evaluation of (false OR false OR false OR true) is true.

// Example 3:

// Input: expression = "!(&(f,t))"
// Output: true
// Explanation:
// First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression
// is now "!(f)". Then, evaluate !(f) --> NOT false --> true. We return true.

// Constraints:

//     1 <= expression.length <= 2 * 104
//     expression[i] is one following characters: '(', ')', '&', '|', '!', 't',
//     'f', and ','.

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    bool parseBoolExpr(const std::string &expression) {
        int i = 0;
        return parse(expression, i);
    }

  private:
    bool parse(const std::string &expr, int &i) {
        char curr = expr[i++];

        if (curr == 't') {
            return true;
        }
        if (curr == 'f') {
            return false;
        }

        if (curr == '!') {
            i++;
            bool result = !parse(expr, i);
            i++;
            return result;
        }

        std::vector<bool> vals;
        i++;
        while (expr[i] != ')') {
            if (expr[i] != ',') {
                vals.push_back(parse(expr, i));
            } else {
                i++;
            }
        }
        i++;

        if (curr == '&') {
            for (bool v : vals) {
                if (!v) {
                    return false;
                }
            }
            return true;
        }
        if (curr == '|') {
            for (bool v : vals) {
                if (v) {
                    return true;
                }
            }
            return false;
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, bool>> tests = {
        {"&(|(f))", false},          {"|(f,f,f,t)", true}, {"!(&(f,t))", true},
        {"|(&(t,f,t),!(t))", false}, {"&(t,f,t)", false},  {"!(t)", false},
        {"|(f,f)", false},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.parseBoolExpr(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
