// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
// Difficulty: Hard

// Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

//     1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
//     2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
//     3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
//     4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

// Notice that there could be some signs on the cells of the grid that point outside the grid.

// You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

// You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

// Return the minimum cost to make the grid have at least one valid path.

// Example 1:

// Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
// Output: 3
// Explanation: You will start at point (0, 0).
// The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
// The total cost = 3.

// Example 2:

// Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
// Output: 0
// Explanation: You can follow the path from (0, 0) to (2, 2).

// Example 3:

// Input: grid = [[1,2],[4,3]]
// Output: 1

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_cost(grid: Vec<Vec<i32>>) -> i32 {
        let mut memo = vec![vec![i32::MAX; grid[0].len()]; grid.len()];
        memo[0][0] = 0;

        loop {
            let prev = memo.clone();

            for i in 0..grid.len() {
                for j in 0..grid[0].len() {
                    if i > 0 {
                        memo[i][j] = memo[i][j]
                            .min(memo[i - 1][j] + if grid[i - 1][j] == 3 { 0 } else { 1 });
                    }
                    if j > 0 {
                        memo[i][j] = memo[i][j]
                            .min(memo[i][j - 1] + if grid[i][j - 1] == 1 { 0 } else { 1 });
                    }
                }
            }

            for i in (0..grid.len()).rev() {
                for j in (0..grid[0].len()).rev() {
                    if i < grid.len() - 1 {
                        memo[i][j] = memo[i][j]
                            .min(memo[i + 1][j] + if grid[i + 1][j] == 4 { 0 } else { 1 });
                    }
                    if j < grid[0].len() - 1 {
                        memo[i][j] = memo[i][j]
                            .min(memo[i][j + 1] + if grid[i][j + 1] == 2 { 0 } else { 1 });
                    }
                }
            }

            if prev == memo {
                break;
            }
        }

        memo[grid.len() - 1][grid[0].len() - 1]
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::min_cost(vec![
            vec![1, 1, 1, 1],
            vec![2, 2, 2, 2],
            vec![1, 1, 1, 1],
            vec![2, 2, 2, 2]
        ]),
        3
    );
    assert_eq!(
        Solution::min_cost(vec![vec![1, 1, 3], vec![3, 2, 2], vec![1, 1, 4]]),
        0
    );
    assert_eq!(Solution::min_cost(vec![vec![1, 2], vec![4, 3]]), 1);
}
