// 440. K-th Smallest in Lexicographical Order
// Difficulty: Hard

// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

// Example 1:

// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

// Example 2:

// Input: n = 1, k = 1
// Output: 1

// Constraints:

//     1 <= k <= n <= 109

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_kth_number(n: i32, mut k: i32) -> i32 {
        let mut curr = 1;
        k -= 1;

        while k > 0 {
            let step = Self::steps(n, curr as i64, curr as i64 + 1);
            if step <= k {
                curr += 1;
                k -= step;
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        curr
    }

    fn steps(n: i32, mut p1: i64, mut p2: i64) -> i32 {
        use std::cmp::min;
        let mut result = 0;
        while p1 <= n as i64 {
            result += (min(n as i64 + 1, p2) - p1) as i32;
            (p1, p2) = (p1 * 10, p2 * 10);
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::find_kth_number(13, 2), 10);
    assert_eq!(Solution::find_kth_number(1, 1), 1);
}
