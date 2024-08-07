// 273. Integer to English Words
// Difficulty: Hard

// Convert a non-negative integer num to its English words representation.

// Example 1:
// Input: num = 123
// Output: "One Hundred Twenty Three"

// Example 2:
// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"

// Example 3:
// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
// Seven"

// Constraints:
//     0 <= num <= 2^31 - 1

#include <algorithm>
#include <cmath>
#include <fmt/ranges.h>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string numberToWords(int num) {
        std::unordered_map<int, std::string> map = {
            {0, "Zero"},          {1, "One"},
            {2, "Two"},           {3, "Three"},
            {4, "Four"},          {5, "Five"},
            {6, "Six"},           {7, "Seven"},
            {8, "Eight"},         {9, "Nine"},
            {10, "Ten"},          {11, "Eleven"},
            {12, "Twelve"},       {13, "Thirteen"},
            {14, "Fourteen"},     {15, "Fifteen"},
            {16, "Sixteen"},      {17, "Seventeen"},
            {18, "Eighteen"},     {19, "Nineteen"},
            {20, "Twenty"},       {30, "Thirty"},
            {40, "Forty"},        {50, "Fifty"},
            {60, "Sixty"},        {70, "Seventy"},
            {80, "Eighty"},       {90, "Ninety"},
            {100, "Hundred"},     {1000, "Thousand"},
            {1000000, "Million"}, {1000000000, "Billion"},
        };

        if (num <= 20) {
            return map[num];
        }

        int         i = 0;
        std::string result;

        while (num > 0) {
            if (num % 1000 > 0) {
                result = getValue(num % 1000, map) +
                         (i != 0 ? map[std::pow(10, i * 3)] : "") + ' ' +
                         result;
            }
            num /= 1000;
            i++;
        }

        while (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

  private:
    std::string getValue(int num, std::unordered_map<int, std::string> &map) {
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return map[num] + ' ';
        } else if (num < 100) {
            return map[num - (num % 10)] + ' ' + getValue(num % 10, map);
        } else {
            return map[num / 100] + " Hundred " + getValue(num % 100, map);
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::string>> tests = {
        {123, "One Hundred Twenty Three"},
        {12345, "Twelve Thousand Three Hundred Forty Five"},
        {1234567, "One Million Two Hundred Thirty Four Thousand Five Hundred "
                  "Sixty Seven"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numberToWords(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
