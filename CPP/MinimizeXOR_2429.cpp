// 2429. Minimize XOR
// Difficulty: Medium

// Given two positive integers num1 and num2, find the positive integer x such
// that:

//     x has the same number of set bits as num2, and
//     The value x XOR num1 is minimal.

// Note that XOR is the bitwise XOR operation.

// Return the integer x. The test cases are generated such that x is uniquely
// determined.

// The number of set bits of an integer is the number of 1's in its binary
// representation.

// Example 1:

// Input: num1 = 3, num2 = 5
// Output: 3
// Explanation:
// The binary representations of num1 and num2 are 0011 and 0101, respectively.
// The integer 3 has the same number of set bits as num2, and the value 3 XOR 3
// = 0 is minimal.

// Example 2:

// Input: num1 = 1, num2 = 12
// Output: 3
// Explanation:
// The binary representations of num1 and num2 are 0001 and 1100, respectively.
// The integer 3 has the same number of set bits as num2, and the value 3 XOR 1
// = 2 is minimal.

// Constraints:

//     1 <= num1, num2 <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// pub fn minimize_xor(num1: i32, num2: i32) -> i32 {
//         let (num1, num2) = (num1 as usize, num2 as usize);
//         let mut result = num1;
//         let target_count = format!("{num2:b}").chars().filter(|&x| x ==
//         '1').count(); let mut curr_count =
//         format!("{result:b}").chars().filter(|&x| x == '1').count(); let mut
//         curr_bit: usize = 0;

//         let is_set = |x, bit| x & (1 << bit) as usize == 1;
//         let toggle_bit = |x, bit| x ^ (1 << bit) as usize;

//         while curr_count < target_count {
//             if !is_set(result, curr_bit) {
//                 result = toggle_bit(result, curr_bit);
//                 curr_count += 1;
//             }
//             curr_bit += 1;
//         }
//         while curr_count > target_count {
//             if is_set(result, curr_bit) {
//                 result = toggle_bit(result, curr_bit);
//                 curr_count -= 1;
//             }
//             curr_bit += 1;
//         }
//         result as i32
//     }

class Solution {
  public:
    int minimizeXor(int num1, int num2) {
        int result      = num1;
        int targetCount = __builtin_popcount(num2);
        int currCount   = __builtin_popcount(result);
        int currBit     = 0;

        auto isSet     = [](int x, int bit) { return x & (1 << bit); };
        auto toggleBit = [](int x, int bit) { return x ^ (1 << bit); };

        while (currCount < targetCount) {
            if (!isSet(result, currBit)) {
                result = toggleBit(result, currBit);
                currCount++;
            }
            currBit++;
        }
        while (currCount > targetCount) {
            if (isSet(result, currBit)) {
                result = toggleBit(result, currBit);
                currCount--;
            }
            currBit++;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, int>, int>> tests = {
        {{3, 5}, 3},
        {{1, 12}, 3},
        {{79, 74}, 76},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.minimizeXor(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
