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
        let mut row = vec![0; matrix[0].len()];
        let mut result = 0;

        for m in matrix {
            for i in 0..row.len() {
                row[i] = if m[i] == '0' { 0 } else { row[i] + 1 };
            }
            result = std::cmp::max(result, Self::calc_area(&row));
        }

        result
    }

    fn calc_area(row: &Vec<i32>) -> i32 {
        let mut stack: Vec<i32> = vec![-1];
        let mut result = 0;

        for i in 0..row.len() {
            while *stack.last().unwrap() != -1 && row[*stack.last().unwrap() as usize] > row[i] {
                let height = row[stack.pop().unwrap() as usize];
                let width = i as i32 - *stack.last().unwrap() - 1;
                result = std::cmp::max(result, height * width);
            }
            stack.push(i as i32);
        }
        while *stack.last().unwrap() != -1 {
            let height = row[stack.pop().unwrap() as usize];
            let width = row.len() as i32 - *stack.last().unwrap() - 1;
            result = std::cmp::max(result, height * width);
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
