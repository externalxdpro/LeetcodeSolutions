// 231. Power of Two
// Difficulty: Easy

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false

// Constraints:

// -231 <= n <= 231 - 1

// Follow up: Could you solve it without loops/recursion?

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && n.count_ones() == 1
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::is_power_of_two(1), true);
    assert_eq!(Solution::is_power_of_two(16), true);
    assert_eq!(Solution::is_power_of_two(3), false);
    assert_eq!(Solution::is_power_of_two(-2147483648), false);
}
