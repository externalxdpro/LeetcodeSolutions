// 1277. Count Square Submatrices with All Ones
// Difficulty: Medium

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation:
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:

// Input: matrix =
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation:
// There are 6 squares of side 1.
// There is 1 square of side 2.
// Total number of squares = 6 + 1 = 7.

// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let mut result = 0;
        let mut memo = vec![vec![None; matrix[0].len()]; matrix.len()];
        for i in 0..matrix.len() {
            for j in 0..matrix[0].len() {
                result += Self::dp(&matrix, i, j, &mut memo);
            }
        }
        result
    }

    fn dp(m: &Vec<Vec<i32>>, i: usize, j: usize, memo: &mut Vec<Vec<Option<i32>>>) -> i32 {
        if i >= m.len() || j >= m[0].len() || m[i][j] == 0 {
            return 0;
        }
        if let Some(x) = memo[i][j] {
            return x;
        }
        let results = [(0, 1), (1, 1), (1, 0)].map(|(di, dj)| Self::dp(m, i + di, j + dj, memo));
        memo[i][j] = Some(results.into_iter().min().unwrap() + 1);
        memo[i][j].unwrap()
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::count_squares(vec![vec![0, 1, 1, 1], vec![1, 1, 1, 1], vec![0, 1, 1, 1]]),
        15
    );
    assert_eq!(
        Solution::count_squares(vec![vec![1, 0, 1], vec![1, 1, 0], vec![1, 1, 0]]),
        7
    );
}
