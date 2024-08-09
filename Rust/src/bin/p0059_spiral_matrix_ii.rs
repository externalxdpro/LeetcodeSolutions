// 59. Spiral Matrix II
// Difficulty: Medium

// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

// Example 1:
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]

// Example 2:
// Input: n = 1
// Output: [[1]]

// Constraints:
//     1 <= n <= 20

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut result = vec![vec![0; n as usize]; n as usize];
        let (mut i, mut j) = (0, 0);
        let mut dir = 'r';

        for val in 1..=(n * n) {
            result[i][j] = val;
            match dir {
                'r' => {
                    j += 1;
                    if j as i32 >= n - 1 || result[i][j + 1] != 0 {
                        dir = 'd';
                    }
                }
                'd' => {
                    i += 1;
                    if i as i32 == n - 1 || result[i + 1][j] != 0 {
                        dir = 'l';
                    }
                }
                'l' => {
                    j -= 1;
                    if j == 0 || result[i][j - 1] != 0 {
                        dir = 'u';
                    }
                }
                'u' => {
                    i -= 1;
                    if i == 0 || result[i - 1][j] != 0 {
                        dir = 'r';
                    }
                }
                _ => (),
            }
        }

        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::generate_matrix(3),
        vec![vec![1, 2, 3], vec![8, 9, 4], vec![7, 6, 5]]
    );
    assert_eq!(Solution::generate_matrix(1), vec![vec![1]]);
    assert_eq!(
        Solution::generate_matrix(4),
        vec![
            vec![1, 2, 3, 4],
            vec![12, 13, 14, 5],
            vec![11, 16, 15, 6],
            vec![10, 9, 8, 7]
        ]
    );
}
