// 1568. Minimum Number of Days to Disconnect Island
// Difficulty: Hard

// You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
// The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
// In one day, we are allowed to change any single land cell (1) into a water cell (0).
// Return the minimum number of days to disconnect the grid.

// Example 1:
// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 2
// Explanation: We need at least 2 days to get a disconnected grid.
// Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

// Example 2:
// Input: grid = [[1,1]]
// Output: 2
// Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.

// Constraints:
//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 30
//     grid[i][j] is either 0 or 1.

pub struct Solution {}

// submission codes start here

static DIRECTIONS: [(i32, i32); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];
impl Solution {
    pub fn min_days(mut grid: Vec<Vec<i32>>) -> i32 {
        let init_count = Self::count_islands(&mut grid);
        if init_count != 1 {
            return 0;
        }

        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 0 {
                    continue;
                }
                grid[i][j] = 0;
                let new_count = Self::count_islands(&mut grid);
                if new_count != 1 {
                    return 1;
                }
                grid[i][j] = 1;
            }
        }

        2
    }

    fn count_islands(grid: &mut Vec<Vec<i32>>) -> i32 {
        let (rows, cols) = (grid.len(), grid[0].len());
        let mut visited: Vec<Vec<bool>> = vec![vec![false; cols]; rows];
        let mut count = 0;

        for i in 0..rows {
            for j in 0..cols {
                if !visited[i][j] && grid[i][j] == 1 {
                    count += 1;
                    Self::explore_islands(grid, i, j, &mut visited);
                }
            }
        }

        count
    }

    fn explore_islands(grid: &mut Vec<Vec<i32>>, i: usize, j: usize, visited: &mut Vec<Vec<bool>>) {
        visited[i][j] = true;

        for dir in DIRECTIONS {
            let (ni, nj) = (i as i32 + dir.0, j as i32 + dir.1);
            if ni >= 0 && ni < grid.len() as i32 && nj >= 0 && nj < grid[0].len() as i32 {
                let (ni, nj) = (ni as usize, nj as usize);
                if grid[ni][nj] == 1 && !visited[ni][nj] {
                    Self::explore_islands(grid, ni, nj, visited);
                }
            }
        }
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::min_days(vec![vec![0, 1, 1, 0], vec![0, 1, 1, 0], vec![0, 0, 0, 0]]),
        2
    );
    assert_eq!(Solution::min_days(vec![vec![1, 1]]), 2);
}
