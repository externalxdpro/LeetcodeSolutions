// Difficulty: Medium
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"

// Constraints:
// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

#include <bits/stdc++.h>

std::string multiply(std::string num1, std::string num2)
{
    if (num1 == "0" || num2 == "0") return "0";

    std::vector<int> digits(num1.length() + num2.length(), 0);
    for (int digit1 = num1.length() - 1; digit1 >= 0; digit1--)
    {
        for (int digit2 = num2.length() - 1; digit2 >= 0; digit2--)
        {
            digits[digit1 + digit2 + 1] += (num1[digit1] - '0') * (num2[digit2] - '0');
            digits[digit1 + digit2] += digits[digit1 + digit2 + 1] / 10;
            digits[digit1 + digit2 + 1] %= 10;
        }
    }

    std::string result = "";

    bool found = false;
    for (int i : digits)
    {
        if (!found && i == 0) continue;
        else found = true;

        result += i + '0';
    }

    return result;
}

int main()
{
    std::cout << multiply("2", "3") << "\n";
    std::cout << multiply("123", "456") << "\n";
    std::cout << multiply("0", "0") << "\n";
    std::cout << multiply("123456789", "987654321") << "\n";
}
