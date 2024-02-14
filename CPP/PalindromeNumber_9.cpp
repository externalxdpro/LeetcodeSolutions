// Difficulty: Easy
// Given an integer x, return true if x is a palindrome, and false otherwise.

// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it
// becomes 121-. Therefore it is not a palindrome.

// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

// Constraints:
//     -2^31 <= x <= 2^31 - 1

// Follow up: Could you solve it without converting the integer to a string?

#include <format>
#include <iostream>
#include <vector>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long origNum = x;
    long newNum = 0;

    do {
        newNum *= 10;
        newNum += origNum % 10;
    } while (origNum /= 10);

    if (x == newNum) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, bool>> tests = {
        {121, true}, {-121, false}, {10, false}};

    for (auto [test, ans] : tests) {
        bool result = isPalindrome(test);
        std::cout << std::format("{}: {} {}\n", test, result,
                                 result == ans ? "✅" : "❌");
    }

    return 0;
}
