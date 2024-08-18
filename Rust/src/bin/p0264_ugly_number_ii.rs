// 264. Ugly Number II
// Difficulty: Medium

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.

// Example 1:
// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

// Example 2:
// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

// Constraints:
//     1 <= n <= 1690

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn nth_ugly_number(n: i32) -> i32 {
        let mut dp = vec![0; n as usize];
        dp[0] = 1;
        Self::recurse(n as usize, 1, (0, 0, 0), &mut dp)
    }

    fn recurse(n: usize, i: usize, idx: (usize, usize, usize), dp: &mut Vec<i32>) -> i32 {
        if i == n {
            return dp[n - 1];
        }
        let (two, three, five) = (dp[idx.0] * 2, dp[idx.1] * 3, dp[idx.2] * 5);
        dp[i] = two.min(three).min(five);
        let new_idx = (
            if dp[i] == two { idx.0 + 1 } else { idx.0 },
            if dp[i] == three { idx.1 + 1 } else { idx.1 },
            if dp[i] == five { idx.2 + 1 } else { idx.2 },
        );
        Self::recurse(n, i + 1, new_idx, dp)
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::nth_ugly_number(10), 12);
    assert_eq!(Solution::nth_ugly_number(1), 1);
}
