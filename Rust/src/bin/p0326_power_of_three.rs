// 326. Power of Three
// Difficulty: Easy

// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).

// Constraints:

// -231 <= n <= 231 - 1

// Follow up: Could you solve it without loops/recursion?

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        n > 0 && 3_i32.pow(i32::MAX.ilog(3)) % n == 0
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::is_power_of_three(27), true);
    assert_eq!(Solution::is_power_of_three(0), false);
    assert_eq!(Solution::is_power_of_three(-1), false);
}
