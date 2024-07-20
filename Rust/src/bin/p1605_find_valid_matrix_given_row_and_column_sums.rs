// 1605. Find Valid Matrix Given Row and Column Sums
// Difficulty: Medium

// You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.
// Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.
// Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.

// Example 1:
// Input: rowSum = [3,8], colSum = [4,7]
// Output: [[3,0],
//          [1,7]]
// Explanation:
// 0th row: 3 + 0 = 3 == rowSum[0]
// 1st row: 1 + 7 = 8 == rowSum[1]
// 0th column: 3 + 1 = 4 == colSum[0]
// 1st column: 0 + 7 = 7 == colSum[1]
// The row and column sums match, and all matrix elements are non-negative.
// Another possible matrix is: [[1,2],
//                              [3,5]]

// Example 2:
// Input: rowSum = [5,7,10], colSum = [8,6,8]
// Output: [[0,5,0],
//          [6,1,0],
//          [2,0,8]]

// Constraints:
//     1 <= rowSum.length, colSum.length <= 500
//     0 <= rowSum[i], colSum[i] <= 10^8
//     sum(rowSum) == sum(colSum)

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn restore_matrix(mut row_sum: Vec<i32>, mut col_sum: Vec<i32>) -> Vec<Vec<i32>> {
        let (r, c) = (row_sum.len(), col_sum.len());
        let mut matrix = vec![vec![0; c]; r];

        for i in 0..r {
            for j in 0..c {
                let x = row_sum[i].min(col_sum[j]);
                matrix[i][j] = x;
                row_sum[i] -= x;
                col_sum[j] -= x;
            }
        }

        matrix
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1605() {
        assert_eq!(
            Solution::restore_matrix(vec![3, 8], vec![4, 7]),
            vec![vec![3, 0], vec![1, 7]]
        );
        assert_eq!(
            Solution::restore_matrix(vec![5, 7, 10], vec![8, 6, 8]),
            vec![vec![5, 0, 0], vec![3, 4, 0], vec![0, 2, 8]]
        );
    }
}

fn main() {}
