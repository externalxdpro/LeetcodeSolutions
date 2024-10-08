// 1937. Maximum Number of Points with Cost
// Difficulty: Medium

// You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.
// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.
// abs(x) is defined as:
//     x for x >= 0.
//     -x for x < 0.

// Example 1:
// Input: points = [[1,2,3],[1,5,1],[3,1,1]]
// Output: 9
// Explanation:
// The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
// You add 3 + 5 + 3 = 11 to your score.
// However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
// Your final score is 11 - 2 = 9.

// Example 2:
// Input: points = [[1,5],[2,3],[4,2]]
// Output: 11
// Explanation:
// The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
// You add 5 + 3 + 4 = 12 to your score.
// However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
// Your final score is 12 - 1 = 11.

// Constraints:
//     m == points.length
//     n == points[r].length
//     1 <= m, n <= 10^5
//     1 <= m * n <= 10^5
//     0 <= points[r][c] <= 10^5

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i64 {
        let mut points: Vec<Vec<i64>> = points
            .into_iter()
            .map(|x| x.into_iter().map(|x| x as i64).collect())
            .collect();

        for i in 1..points.len() {
            let mut r = vec![0; points[0].len()];
            *r.last_mut().unwrap() = *points[i - 1].last().unwrap();
            for j in (0..(points[0].len() - 1)).rev() {
                r[j] = points[i - 1][j].max(r[j + 1] - 1);
            }

            let mut l = points[i - 1][0];
            points[i][0] = l.max(r[0]) + points[i][0];
            for j in 1..points[0].len() {
                l = points[i - 1][j].max(l - 1);
                points[i][j] = l.max(r[j]) + points[i][j];
            }
        }

        *points.last().unwrap().into_iter().max().unwrap() as i64
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::max_points(vec![vec![1, 2, 3], vec![1, 5, 1], vec![3, 1, 1]]),
        9
    );
    assert_eq!(
        Solution::max_points(vec![vec![1, 5], vec![2, 3], vec![4, 2]]),
        11
    );
}
