// 342. Power of Four
// Difficulty: Easy

// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

// Example 1:

// Input: n = 16
// Output: true
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true

// Constraints:

// -231 <= n <= 231 - 1

// Follow up: Could you solve it without loops/recursion?

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        n > 0 && 4i32.pow(n.ilog(4)) % n == 0
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::is_power_of_four(16), true);
    assert_eq!(Solution::is_power_of_four(5), false);
    assert_eq!(Solution::is_power_of_four(1), true);
}
