// Difficulty: Easy
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Constraints:
//     1 <= n <= 45

#include <fmt/ranges.h>
#include <vector>

// Recursive, too slow
// int climbStairs(int n) {
//     if (n == 1 || n == 2) {
//         return n;
//     }

//     return climbStairs(n - 1) + climbStairs(n - 2);
// }

// Using only two nums
// int climbStairs(int n) {
//     if (n == 1 || n == 2) {
//         return n;
//     }

//     int secondLast = 1;
//     int last = 2;

//     for (int i = 3; i <= n; i++) {
//         int temp = secondLast + last;
//         secondLast = last;
//         last = temp;
//     }

//     return last;
// }

// Using an array
int climbStairs(int n) {
    if (n == 1 || n == 2) {
        return n;
    }

    std::vector<int> fibs(n, 0);
    fibs[0] = 1;
    fibs[1] = 2;

    for (int i = 2; i < n; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }

    return fibs.back();
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, int>> tests = {
        {2, 2},
        {3, 3},
        {45, 1836311903},
    };

    for (auto [test, ans] : tests) {
        int result = climbStairs(test);
        fmt::print("{}: {} {}\n", test, result, result == ans);
    }

    return 0;
}
