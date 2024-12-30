// 2466. Count Ways To Build Good Strings
// Difficulty: Medium

// Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

//     Append the character '0' zero times.
//     Append the character '1' one times.

// This can be performed any number of times.

// A good string is a string constructed by the above process having a length between low and high (inclusive).

// Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

// Example 1:

// Input: low = 3, high = 3, zero = 1, one = 1
// Output: 8
// Explanation:
// One possible valid good string is "011".
// It can be constructed as follows: "" -> "0" -> "01" -> "011".
// All binary strings from "000" to "111" are good strings in this example.

// Example 2:

// Input: low = 2, high = 3, zero = 1, one = 2
// Output: 5
// Explanation: The good strings are "00", "11", "000", "110", and "011".

// Constraints:

//     1 <= low <= high <= 105
//     1 <= zero, one <= low

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn count_good_strings(low: i32, high: i32, zero: i32, one: i32) -> i32 {
        let mut result = 0;
        let mut memo = vec![-1; high as usize + 1];
        memo[0] = 1;
        for len in low..=high {
            result += Self::recurse(len as usize, zero as usize, one as usize, &mut memo);
            result %= 1_000_000_007;
        }
        result
    }

    fn recurse(len: usize, zero: usize, one: usize, memo: &mut [i32]) -> i32 {
        if memo[len] != -1 {
            return memo[len];
        }
        let mut result = 0;
        if len >= one {
            result += Self::recurse(len - one, zero, one, memo);
        }
        if len >= zero {
            result += Self::recurse(len - zero, zero, one, memo);
        }
        memo[len] = result % 1_000_000_007;
        memo[len]
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::count_good_strings(3, 3, 1, 1), 8);
    assert_eq!(Solution::count_good_strings(2, 3, 1, 2), 5);
    assert_eq!(Solution::count_good_strings(200, 200, 10, 1), 764262396);
    assert_eq!(Solution::count_good_strings(1, 100000, 1, 1), 215447031);
}
