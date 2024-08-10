// 62. Unique Paths
// Difficulty: Medium

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:
// Input: m = 3, n = 7
// Output: 28

// Example 2:
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

// Constraints:
//     1 <= m, n <= 100

pub struct Solution {}

// submission codes start here

use std::collections::HashMap;

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        Self::recurse(m, n, &mut HashMap::new())
    }

    fn recurse(m: i32, n: i32, dp: &mut HashMap<(i32, i32), i32>) -> i32 {
        if m == 1 && n == 1 {
            return 1;
        } else if let Some(&x) = dp.get(&(m, n)) {
            return x;
        }

        let mut result = 0;
        if m > 1 {
            result += Self::recurse(m - 1, n, dp);
        }
        if n > 1 {
            result += Self::recurse(m, n - 1, dp);
        }
        dp.insert((m, n), result);
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::unique_paths(3, 7), 28);
    assert_eq!(Solution::unique_paths(3, 2), 3);
    assert_eq!(Solution::unique_paths(100, 100), 3);
}
