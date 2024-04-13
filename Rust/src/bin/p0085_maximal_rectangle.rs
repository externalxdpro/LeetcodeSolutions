// [85] Maximal Rectangle
// Hard

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

// Example 2:
// Input: matrix = [["0"]]
// Output: 0

// Example 3:
// Input: matrix = [["1"]]
// Output: 1

// Constraints:
//     rows == matrix.length
//     cols == matrix[i].length
//     1 <= row, cols <= 200
//     matrix[i][j] is '0' or '1'.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        use std::cmp::{max, min};

        let mut row = vec![0; matrix[0].len()];
        let mut result = 0;

        for m in matrix {
            for i in 0..row.len() {
                row[i] = if m[i] == '0' { 0 } else { row[i] + 1 };
            }

            for l in 0..row.len() {
                let mut height = row[l];
                for r in l..row.len() {
                    if row[r] == 0 {
                        break;
                    }
                    height = min(height, row[r]);
                    result = max(result, (r - l + 1) as i32 * height)
                }
            }
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_85() {
        assert_eq!(
            Solution::maximal_rectangle(vec![
                vec!['1', '0', '1', '0', '0'],
                vec!['1', '0', '1', '1', '1'],
                vec!['1', '1', '1', '1', '1'],
                vec!['1', '0', '0', '1', '0']
            ]),
            6
        );
        assert_eq!(Solution::maximal_rectangle(vec![vec!['0']]), 0);
        assert_eq!(Solution::maximal_rectangle(vec![vec!['1']]), 1);
    }
}

fn main() {}
