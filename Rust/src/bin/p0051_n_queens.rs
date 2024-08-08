// 51. N-Queens
// Difficulty: Hard

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]

// Constraints:
//     1 <= n <= 9

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        if n == 1 {
            return vec![vec!["Q".to_string()]];
        } else if n <= 3 {
            return vec![];
        }

        let mut result = vec![];
        let mut solution = vec![-1; n as usize];
        Self::recurse(n, &mut solution, 0, &mut result);
        result
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
    fn test_0051() {
        assert_eq!(
            Solution::solve_n_queens(4),
            vec![
                vec![".Q..", "...Q", "Q...", "..Q."],
                vec!["..Q.", "Q...", "...Q", ".Q.."]
            ]
        );
        assert_eq!(Solution::solve_n_queens(1), vec![vec!["Q"],]);
    }
}

fn main() {}
