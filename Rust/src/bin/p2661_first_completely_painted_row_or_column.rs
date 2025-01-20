// 2661. First Completely Painted Row or Column
// Difficulty: Medium

// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

// Example 1:
// image explanation for example 1

// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
// Output: 2
// Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

// Example 2:
// image explanation for example 2

// Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// Output: 3
// Explanation: The second column becomes fully painted at arr[3].

// Constraints:

//     m == mat.length
//     n = mat[i].length
//     arr.length == m * n
//     1 <= m, n <= 105
//     1 <= m * n <= 105
//     1 <= arr[i], mat[r][c] <= m * n
//     All the integers of arr are unique.
//     All the integers of mat are unique.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let mut pos = vec![(0, 0); arr.len() + 1];
        let mut row_counts = vec![mat[0].len(); mat.len()];
        let mut col_counts = vec![mat.len(); mat[0].len()];
        for i in 0..mat.len() {
            for j in 0..mat[0].len() {
                pos[mat[i][j] as usize] = (i, j);
            }
        }

        for (i, curr) in arr.into_iter().enumerate() {
            let (mi, mj) = pos[curr as usize];
            row_counts[mi] -= 1;
            col_counts[mj] -= 1;
            if row_counts[mi] == 0 {
                return i as i32;
            }
            if col_counts[mj] == 0 {
                return i as i32;
            }
        }
        -1
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::first_complete_index(vec![1, 3, 4, 2], vec![vec![1, 4], vec![2, 3]]),
        2
    );
    assert_eq!(
        Solution::first_complete_index(
            vec![2, 8, 7, 4, 1, 3, 5, 6, 9],
            vec![vec![3, 2, 5], vec![1, 4, 6], vec![8, 7, 9]]
        ),
        3
    );
}
