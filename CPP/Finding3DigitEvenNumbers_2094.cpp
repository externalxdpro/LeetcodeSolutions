// 2094. Finding 3-Digit Even Numbers
// Difficulty: Easy

// You are given an integer array digits, where each element is a digit. The
// array may contain duplicates.

// You need to find all the unique integers that follow the given requirements:

//     The integer consists of the concatenation of three elements from digits
//     in any arbitrary order. The integer does not have leading zeros. The
//     integer is even.

// For example, if the given digits were [1, 2, 3], integers 132 and 312 follow
// the requirements.

// Return a sorted array of the unique integers.

// Example 1:

// Input: digits = [2,1,3,0]
// Output: [102,120,130,132,210,230,302,310,312,320]
// Explanation: All the possible integers that follow the requirements are in
// the output array. Notice that there are no odd integers or integers with
// leading zeros.

// Example 2:

// Input: digits = [2,2,8,8,2]
// Output: [222,228,282,288,822,828,882]
// Explanation: The same digit can be used as many times as it appears in
// digits. In this example, the digit 8 is used twice each time in 288, 828, and
// 882.

// Example 3:

// Input: digits = [3,7,5]
// Output: []
// Explanation: No even integers can be formed using the given digits.

// Constraints:

//     3 <= digits.length <= 100
//     0 <= digits[i] <= 9

#include <fmt/ranges.h>
#include <set>
#include <vector>

class Solution {
  public:
    std::vector<int> findEvenNumbers(std::vector<int> &d) {
        std::set<int> result;

        for (int i = 0; i < d.size(); i++) {
            if (d[i] == 0) {
                continue;
            }
            for (int j = 0; j < d.size(); j++) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k < d.size(); k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (d[k] % 2 == 0) {
                        int num = d[i] * 100 + d[j] * 10 + d[k];
                        result.insert(num);
                    }
                }
            }
        }

        return std::vector(result.begin(), result.end());
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{2, 1, 3, 0}, {102, 120, 130, 132, 210, 230, 302, 310, 312, 320}},
        {{2, 2, 8, 8, 2}, {222, 228, 282, 288, 822, 828, 882}},
        {{3, 7, 5}, {}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findEvenNumbers(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
