// [54] Spiral Matrix
// Medium

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Constraints:
//     m == matrix.length
//     n == matrix[i].length
//     1 <= m, n <= 10
//     -100 <= matrix[i][j] <= 100

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn spiral_order(mut matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut result: Vec<i32> = vec![];
        let mut visited_count: usize = 0;
        let (mut row_inc, mut col_inc): (i32, i32) = (0, 1);
        let (mut i, mut j): (i32, i32) = (0, 0);

        while visited_count < matrix.len() * matrix[0].len() {
            result.push(matrix[i as usize][j as usize]);
            matrix[i as usize][j as usize] = 1000;
            visited_count += 1;

            if i + row_inc >= matrix.len() as i32
                || j + col_inc >= matrix[0].len() as i32
                || i + row_inc < 0
                || j + col_inc < 0
                || matrix[(i + row_inc) as usize][(j + col_inc) as usize] == 1000
            {
                (row_inc, col_inc) = match (row_inc, col_inc) {
                    (0, 1) => (1, 0),
                    (1, 0) => (0, -1),
                    (0, -1) => (-1, 0),
                    (-1, 0) => (0, 1),
                    _ => (row_inc, row_inc),
                }
            }

            (i, j) = (i + row_inc, j + col_inc);
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_54() {
        assert_eq!(
            Solution::spiral_order(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]),
            vec![1, 2, 3, 6, 9, 8, 7, 4, 5]
        );
        assert_eq!(
            Solution::spiral_order(vec![
                vec![1, 2, 3, 4],
                vec![5, 6, 7, 8],
                vec![9, 10, 11, 12]
            ]),
            vec![1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
        );
        assert_eq!(Solution::spiral_order(vec![vec![0]]), vec![0]);
    }
}

fn main() {}
