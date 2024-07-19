// [#] Name
// Difficulty: Easy

// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

// Example 1:
// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

// Example 2:
// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

// Example 3:
// Input: matrix = [[7,8],[1,2]]
// Output: [7]
// Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

// Constraints:
//     m == mat.length
//     n == mat[i].length
//     1 <= n, m <= 50
//     1 <= matrix[i][j] <= 10^5.
//     All elements in the matrix are distinct.

// Description

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let (m, n) = (matrix.len(), matrix[0].len());
        let (mut min, mut max) = (Vec::with_capacity(m), Vec::with_capacity(n));

        for i in 0..m {
            let mut curr = matrix[i][0];
            for j in 1..n {
                curr = curr.min(matrix[i][j]);
            }
            min.push(curr);
        }
        for j in 0..n {
            let mut curr = matrix[0][j];
            for i in 1..m {
                curr = curr.max(matrix[i][j]);
            }
            max.push(curr);
        }

        let mut res = vec![];
        for i in 0..m {
            for j in 0..n {
                let curr = matrix[i][j];
                if (curr == min[i] && curr == max[j]) {
                    res.push(curr);
                }
            }
        }
        res
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1380() {
        assert_eq!(
            Solution::lucky_numbers(vec![vec![3, 7, 8], vec![9, 11, 13], vec![15, 16, 17]]),
            (vec![15])
        );
        assert_eq!(
            Solution::lucky_numbers(vec![
                vec![1, 10, 4, 2],
                vec![9, 3, 8, 7],
                vec![15, 16, 17, 12]
            ]),
            (vec![12])
        );
        assert_eq!(
            Solution::lucky_numbers(vec![vec![7, 8], vec![1, 2]]),
            (vec![7])
        );
    }
}

fn main() {}
