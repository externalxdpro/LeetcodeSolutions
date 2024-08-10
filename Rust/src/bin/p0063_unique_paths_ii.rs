// 63. Unique Paths II
// Difficulty: Medium

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The testcases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:
// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Example 2:
// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

// Constraints:
//     m == obstacleGrid.length
//     n == obstacleGrid[i].length
//     1 <= m, n <= 100
//     obstacleGrid[i][j] is 0 or 1.

pub struct Solution {}

// submission codes start here

use std::collections::HashMap;

impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        Self::recurse(&obstacle_grid, 0, 0, &mut HashMap::new())
    }

    fn recurse(
        grid: &Vec<Vec<i32>>,
        i: usize,
        j: usize,
        dp: &mut HashMap<(usize, usize), i32>,
    ) -> i32 {
        if i == grid.len() || j == grid[0].len() || grid[i][j] == 1 {
            return 0;
        } else if i == grid.len() - 1 && j == grid[0].len() - 1 {
            return 1;
        } else if let Some(&x) = dp.get(&(i, j)) {
            return x;
        }

        let mut result = 0;
        result += Self::recurse(grid, i + 1, j, dp);
        result += Self::recurse(grid, i, j + 1, dp);
        dp.insert((i, j), result);
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::unique_paths_with_obstacles(vec![vec![0, 0, 0], vec![0, 1, 0], vec![0, 0, 0]]),
        2
    );
    assert_eq!(
        Solution::unique_paths_with_obstacles(vec![vec![0, 1], vec![0, 0]]),
        1
    );
}
