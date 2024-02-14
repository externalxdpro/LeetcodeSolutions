// Difficulty: Easy
// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
//     Starting with any positive integer, replace the number by the sum of the
//     squares of its digits. Repeat the process until the number equals 1
//     (where it will stay), or it loops endlessly in a cycle which does not
//     include 1. Those numbers for which this process ends in 1 are happy.

// Return true if n is a happy number, and false if not.

// Example 1:
// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// Example 2:
// Input: n = 2
// Output: false

// Constraints:
//     1 <= n <= 2^31 - 1

#include <iostream>
#include <unordered_set>
#include <vector>

bool isHappy(int n) {
    std::string curr = std::to_string(n);
    std::unordered_set<std::string> seen;

    while (!seen.contains(curr)) {
        seen.insert(curr);

        int sum = 0;
        for (char i : curr) {
            int num = i - 48;
            sum += num * num;
        }

        if (sum == 1) {
            return true;
        }

        curr = std::to_string(sum);
    }

    return false;
}

int main() {
    std::vector<int> tests = {
        19,
        2,
    };

    for (int test : tests) {
        std::cout << (isHappy(test) ? "true" : "false") << std::endl;
    }

    return 0;
}
