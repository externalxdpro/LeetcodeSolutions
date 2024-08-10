// 959. Regions Cut By Slashes
// Difficulty: Medium

// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
// Given the grid grid represented as a string array, return the number of regions.
// Note that backslash characters are escaped, so a '\' is represented as '\\'.

// Example 1:
// Input: grid = [" /","/ "]
// Output: 2

// Example 2:
// Input: grid = [" /","  "]
// Output: 1

// Example 3:
// Input: grid = ["/\\","\\/"]
// Output: 5
// Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

// Constraints:
//     n == grid.length == grid[i].length
//     1 <= n <= 30
//     grid[i][j] is either '/', '\', or ' '.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn regions_by_slashes(grid: Vec<String>) -> i32 {
        let grid: Vec<Vec<char>> = grid.into_iter().map(|x| x.chars().collect()).collect();
        let mut expanded_grid = vec![vec![0; grid[0].len() * 3]; grid.len() * 3];

        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                let (ei, ej) = (i * 3, j * 3);

                match grid[i][j] {
                    '/' => {
                        expanded_grid[ei][ej + 2] = 1;
                        expanded_grid[ei + 1][ej + 1] = 1;
                        expanded_grid[ei + 2][ej] = 1;
                    }
                    '\\' => {
                        expanded_grid[ei][ej] = 1;
                        expanded_grid[ei + 1][ej + 1] = 1;
                        expanded_grid[ei + 2][ej + 2] = 1;
                    }
                    _ => (),
                }
            }
        }

        let mut result = 0;
        for i in 0..(expanded_grid.len() as i32) {
            for j in 0..(expanded_grid[0].len() as i32) {
                if expanded_grid[i as usize][j as usize] == 0 {
                    result += 1;
                    Self::remove(&mut expanded_grid, i, j);
                }
            }
        }
        result
    }

    fn remove(grid: &mut Vec<Vec<i32>>, i: i32, j: i32) {
        if i < 0
            || i as usize >= grid.len()
            || j < 0
            || j as usize >= grid[0].len()
            || grid[i as usize][j as usize] != 0
        {
            return;
        }
        grid[i as usize][j as usize] = 1;
        Self::remove(grid, i + 1, j);
        Self::remove(grid, i - 1, j);
        Self::remove(grid, i, j + 1);
        Self::remove(grid, i, j - 1);
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::regions_by_slashes(vec![" /".to_string(), "/ ".to_string()]),
        2
    );
    assert_eq!(
        Solution::regions_by_slashes(vec![" /".to_string(), "  ".to_string()]),
        1
    );
    assert_eq!(
        Solution::regions_by_slashes(vec!["/\\".to_string(), "\\/".to_string()]),
        5
    );
}
