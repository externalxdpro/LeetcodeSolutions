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
        let max: Vec<i32> = (0..matrix[0].len())
            .map(|i| matrix.iter().map(|x| x[i]).max().unwrap())
            .collect();
        let min: Vec<i32> = matrix.iter().map(|x| *x.iter().min().unwrap()).collect();

        let mut res: Vec<i32> = vec![];
        for i in 0..matrix.len() {
            for j in 0..matrix[0].len() {
                if matrix[i][j] == min[i] && matrix[i][j] == max[j] {
                    res.push(matrix[i][j]);
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
