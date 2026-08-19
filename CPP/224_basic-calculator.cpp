#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
  public:
    int calculate(string &s) {
        long long result = 0, curr = 0;
        int sign = 1;
        std::stack<int> stack;

        for (char c : s) {
            if (std::isdigit(c)) {
                curr = curr * 10 + (c - '0');
            } else if (c == '+') {
                result += curr * sign;
                sign = 1;
                curr = 0;
            } else if (c == '-') {
                result += curr * sign;
                sign = -1;
                curr = 0;
            } else if (c == '(') {
                stack.push(result);
                stack.push(sign);
                result = 0;
                sign = 1;
                curr = 0;
            } else if (c == ')') {
                result += curr * sign;
                curr = 0;
                result *= stack.top();
                stack.pop();
                result += stack.top();
                stack.pop();
            }
        }

        result += curr * sign;
        return result;
    }
};

// code_end
