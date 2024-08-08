// N-Queens II
// Difficulty: Hard

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example 1:
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

// Example 2:
// Input: n = 1
// Output: 1

// Constraints:
//     1 <= n <= 9

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        if n == 1 {
            return 1;
        } else if n <= 3 {
            return 0;
        }

        let mut result = vec![];
        let mut solution = vec![-1; n as usize];
        Self::recurse(n, &mut solution, 0, &mut result);
        result.len() as i32
    }

    fn recurse(n: i32, solution: &mut [i32], row: i32, result: &mut Vec<Vec<String>>) {
        if row == n {
            result.push(Self::construct_string(solution));
            return;
        }

        for col in 0..n {
            if Self::is_valid_move(row, col, solution) {
                solution[row as usize] = col;
                Self::recurse(n, solution, row + 1, result);
                solution[row as usize] = -1;
            }
        }
    }

    fn construct_string(solution: &[i32]) -> Vec<String> {
        let mut board = vec![];
        for row in 0..solution.len() {
            let mut row_str = vec!['.'; solution.len()];
            row_str[solution[row] as usize] = 'Q';
            board.push(row_str.into_iter().collect());
        }
        board
    }

    fn is_valid_move(row: i32, col: i32, solution: &[i32]) -> bool {
        for i in 0..row {
            let (old_row, old_col) = (i, solution[i as usize]);
            let diagonal_offset = row - old_row;

            if old_col == col
                || old_col == col - diagonal_offset
                || old_col == col + diagonal_offset
            {
                return false;
            }
        }
        true
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0052() {
        assert_eq!(Solution::total_n_queens(4), 2);
        assert_eq!(Solution::total_n_queens(1), 1);
    }
}

fn main() {}
