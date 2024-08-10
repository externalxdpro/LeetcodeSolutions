// 64. Minimum Path Sum
// Difficulty: Medium

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// Example 1:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

// Constraints:
//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 200
//     0 <= grid[i][j] <= 200

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let mut dp = vec![vec![i32::MAX; grid[0].len()]; grid.len()];
        Self::recurse(&grid, 0, 0, &mut dp)
    }

    fn recurse(grid: &Vec<Vec<i32>>, i: usize, j: usize, dp: &mut Vec<Vec<i32>>) -> i32 {
        if i >= grid.len() || j >= grid[0].len() {
            return i32::MAX;
        } else if i == grid.len() - 1 && j == grid[0].len() - 1 {
            return grid[i][j];
        } else if dp[i][j] != i32::MAX {
            return dp[i][j];
        }

        let mut result = Self::recurse(grid, i + 1, j, dp);
        result = result.min(Self::recurse(grid, i, j + 1, dp));
        dp[i][j] = grid[i][j] + result;
        dp[i][j]
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::min_path_sum(vec![vec![1, 3, 1], vec![1, 5, 1], vec![4, 2, 1]]),
        7
    );
    assert_eq!(
        Solution::min_path_sum(vec![vec![1, 2, 3], vec![4, 5, 6]]),
        12
    );
}
