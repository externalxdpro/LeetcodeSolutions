// 885. Spiral Matrix III
// Difficulty: Medium

// You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
// You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
// Return an array of coordinates representing the positions of the grid in the order you visited them.

// Example 1:
// Input: rows = 1, cols = 4, rStart = 0, cStart = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]

// Example 2:
// Input: rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

// Constraints:
//     1 <= rows, cols <= 100
//     0 <= rStart < rows
//     0 <= cStart < cols

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn spiral_matrix_iii(rows: i32, cols: i32, r_start: i32, c_start: i32) -> Vec<Vec<i32>> {
        let mut result = vec![];
        let (mut i, mut j) = (r_start, c_start);
        let mut count = 1;
        let mut dir = 'r';

        while result.len() < (rows * cols) as usize {
            match dir {
                'r' => {
                    for _ in 0..count {
                        if Self::in_bounds(rows, cols, i, j) {
                            result.push(vec![i, j]);
                        }
                        j += 1;
                    }
                    dir = 'd';
                }
                'd' => {
                    for _ in 0..count {
                        if Self::in_bounds(rows, cols, i, j) {
                            result.push(vec![i, j]);
                        }
                        i += 1;
                    }
                    count += 1;
                    dir = 'l';
                }
                'l' => {
                    for _ in 0..count {
                        if Self::in_bounds(rows, cols, i, j) {
                            result.push(vec![i, j]);
                        }
                        j -= 1;
                    }
                    dir = 'u';
                }
                'u' => {
                    for _ in 0..count {
                        if Self::in_bounds(rows, cols, i, j) {
                            result.push(vec![i, j]);
                        }
                        i -= 1;
                    }
                    count += 1;
                    dir = 'r';
                }
                _ => (),
            }
        }

        result
    }

    fn in_bounds(rows: i32, cols: i32, i: i32, j: i32) -> bool {
        i >= 0 && i < rows && j >= 0 && j < cols
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0885() {
        assert_eq!(
            Solution::spiral_matrix_iii(1, 4, 0, 0),
            vec![vec![0, 0], vec![0, 1], vec![0, 2], vec![0, 3]]
        );
        assert_eq!(
            Solution::spiral_matrix_iii(5, 6, 1, 4),
            vec![
                vec![1, 4],
                vec![1, 5],
                vec![2, 5],
                vec![2, 4],
                vec![2, 3],
                vec![1, 3],
                vec![0, 3],
                vec![0, 4],
                vec![0, 5],
                vec![3, 5],
                vec![3, 4],
                vec![3, 3],
                vec![3, 2],
                vec![2, 2],
                vec![1, 2],
                vec![0, 2],
                vec![4, 5],
                vec![4, 4],
                vec![4, 3],
                vec![4, 2],
                vec![4, 1],
                vec![3, 1],
                vec![2, 1],
                vec![1, 1],
                vec![0, 1],
                vec![4, 0],
                vec![3, 0],
                vec![2, 0],
                vec![1, 0],
                vec![0, 0]
            ]
        );
    }
}

fn main() {}
