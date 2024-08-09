// 840. Magic Squares In Grid
// Difficulty: Medium

// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
// Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

// Example 1:
// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1

// Example 2:
// Input: grid = [[8]]
// Output: 0

// Constraints:
//     row == grid.length
//     col == grid[i].length
//     1 <= row, col <= 10
//     0 <= grid[i][j] <= 15

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        use std::collections::HashSet;

        if grid.len() < 3 || grid[0].len() < 3 {
            return 0;
        }

        let mut result = 0;
        for i in 0..=(grid.len() - 3) {
            for j in 0..=(grid[0].len() - 3) {
                let mut square: Vec<i32> = vec![];
                square.extend_from_slice(&grid[i][j..(j + 3)]);
                square.extend_from_slice(&grid[i + 1][j..(j + 3)]);
                square.extend_from_slice(&grid[i + 2][j..(j + 3)]);

                if square.clone().into_iter().collect::<HashSet<_>>()
                    != HashSet::from([1, 2, 3, 4, 5, 6, 7, 8, 9])
                {
                    continue;
                }

                let row1 = square[0..3].iter().sum();
                let row2 = square[3..6].iter().sum();
                let row3 = square[6..9].iter().sum();
                let col1 = square[0] + square[3] + square[6];
                let col2 = square[1] + square[4] + square[7];
                let col3 = square[2] + square[5] + square[8];
                let diag1 = square[0] + square[4] + square[8];
                let diag2 = square[2] + square[4] + square[6];
                if HashSet::from([row1, row2, row3, col1, col2, col3, diag1, diag2]).len() == 1 {
                    result += 1;
                }
            }
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::num_magic_squares_inside(vec![
            vec![4, 3, 8, 4],
            vec![9, 5, 1, 9],
            vec![2, 7, 6, 2]
        ]),
        1
    );
    assert_eq!(Solution::num_magic_squares_inside(vec![vec![8]]), 0);
    assert_eq!(
        Solution::num_magic_squares_inside(vec![vec![5, 5, 5], vec![5, 5, 5], vec![5, 5, 5]]),
        0
    );
}
