// 869. Reordered Power of 2
// Difficulty: Medium

// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

// Return true if and only if we can do this so that the resulting number is a power of two.

// Example 1:

// Input: n = 1
// Output: true
// Example 2:

// Input: n = 10
// Output: false

// Constraints:

// 1 <= n <= 109

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn reordered_power_of2(n: i32) -> bool {
        let target = Self::freq(n);
        for i in 0..=30 {
            let pow = 2i32.pow(i);
            if target == Self::freq(pow) {
                return true;
            }
        }
        false
    }

    fn freq(mut n: i32) -> [i32; 10] {
        let mut result = [0; 10];
        while n > 0 {
            result[(n % 10) as usize] += 1;
            n /= 10;
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::reordered_power_of2(1), true);
    assert_eq!(Solution::reordered_power_of2(10), false);
}
