#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
  public:
    int calculate(string &s) {
        int curr = 0;
        char op = '+';
        std::stack<int> stack;

        for (int i = 0; i < s.size(); i++) {
            if (std::isdigit(s[i])) {
                curr = curr * 10 + (s[i] - '0');
            }

            if ((!std::isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    stack.push(curr);
                } else if (op == '-') {
                    stack.push(-curr);
                } else if (op == '*') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top * curr);
                } else if (op == '/') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top / curr);
                }

                op = s[i];
                curr = 0;
            }
        }

        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};

// code_end
