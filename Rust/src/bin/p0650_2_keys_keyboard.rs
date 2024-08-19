// 650. 2 Keys Keyboard
// Difficulty: Medium

// There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
//     Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
//     Paste: You can paste the characters which are copied last time.
// Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

// Example 1:
// Input: n = 3
// Output: 3
// Explanation: Initially, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.

// Example 2:
// Input: n = 1
// Output: 0

// Constraints:
//     1 <= n <= 1000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_steps(n: i32) -> i32 {
        Self::recurse(n, &mut vec![0; n as usize + 1])
    }

    fn recurse(n: i32, dp: &mut [i32]) -> i32 {
        if n <= 2 {
            return if n == 2 { 2 } else { 0 };
        }
        if dp[n as usize] != 0 {
            return dp[n as usize];
        }
        let mut min = n;
        for i in 2..=((n as f32).sqrt() as i32) {
            if n % i == 0 {
                min = min.min(Self::recurse(n / i, dp) + i);
            }
        }

        dp[n as usize] = min;
        min
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::min_steps(3), 3);
    assert_eq!(Solution::min_steps(1), 0);
    assert_eq!(Solution::min_steps(6), 5);
}
