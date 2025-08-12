// 2787. Ways to Express an Integer as Sum of Powers
// Difficulty: Medium

// Given two positive integers n and x.

// Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

// Since the result can be very large, return it modulo 109 + 7.

// For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

// Example 1:

// Input: n = 10, x = 2
// Output: 1
// Explanation: We can express n as the following: n = 32 + 12 = 10.
// It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
// Example 2:

// Input: n = 4, x = 1
// Output: 2
// Explanation: We can express n in the following ways:
// - n = 41 = 4.
// - n = 31 + 11 = 4.

// Constraints:

// 1 <= n <= 300
// 1 <= x <= 5

pub struct Solution {}

// submission codes start here

const MOD: i32 = 1e9 as i32 + 7;
const LEN: usize = 301;

impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        let mut memo = [[-1; LEN]; LEN];
        Self::dp(n, x, 1, &mut memo)
    }

    fn dp(n: i32, x: i32, curr: i32, memo: &mut [[i32; LEN]; LEN]) -> i32 {
        if n == 0 {
            return 1;
        }
        if n < 0 {
            return 0;
        }
        let pow = curr.pow(x as u32);
        if pow > n {
            return 0;
        }
        if memo[n as usize][curr as usize] != -1 {
            return memo[n as usize][curr as usize];
        }

        let take = Self::dp(n - pow, x, curr + 1, memo);
        let skip = Self::dp(n, x, curr + 1, memo);
        memo[n as usize][curr as usize] = (take + skip) % MOD;
        memo[n as usize][curr as usize]
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::number_of_ways(10, 2), 1);
    assert_eq!(Solution::number_of_ways(4, 1), 2);
}
