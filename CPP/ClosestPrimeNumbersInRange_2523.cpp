// 2523. Closest Prime Numbers in Range
// Difficulty: Medium

// Given two positive integers left and right, find the two integers num1 and
// num2 such that:

//     left <= num1 < num2 <= right .
//     Both num1 and num2 are

//     .
//     num2 - num1 is the minimum amongst all other pairs satisfying the above
//     conditions.

// Return the positive integer array ans = [num1, num2]. If there are multiple
// pairs satisfying these conditions, return the one with the smallest num1
// value. If no such numbers exist, return [-1, -1].

// Example 1:

// Input: left = 10, right = 19
// Output: [11,13]
// Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
// The closest gap between any pair is 2, which can be achieved by [11,13] or
// [17,19]. Since 11 is smaller than 17, we return the first pair.

// Example 2:

// Input: left = 4, right = 6
// Output: [-1,-1]
// Explanation: There exists only one prime number in the given range, so the
// conditions cannot be satisfied.

// Constraints:

//     1 <= left <= right <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <vector>

class Solution {
  public:
    std::vector<int> closestPrimes(int left, int right) {
        std::vector<int> primes(right + 1, true);
        for (int i = 2; i * i <= right; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= right; j += i) {
                    primes[j] = false;
                }
            }
        }
        std::vector<int> nums;
        for (int i = std::max(left, 2); i < primes.size(); i++) {
            if (primes[i]) {
                nums.push_back(i);
            }
        }
        if (nums.size() < 2) {
            return {-1, -1};
        }
        std::vector<int> result = {-1, -1};
        int              min    = std::numeric_limits<int>::max();
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] < min) {
                min    = nums[i + 1] - nums[i];
                result = {nums[i], nums[i + 1]};
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, std::vector<int>>> tests = {
        {{10, 19}, {11, 13}},
        {{4, 6}, {-1, -1}},
        {{1, 1000000}, {2, 3}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.closestPrimes(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
