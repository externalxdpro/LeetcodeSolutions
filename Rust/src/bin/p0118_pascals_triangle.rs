// 118. Pascal's Triangle
// Difficulty: Easy

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:

// Input: numRows = 1
// Output: [[1]]

// Constraints:

//     1 <= numRows <= 30

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        use std::iter::once;
        (1..num_rows).fold(vec![vec![1]], |mut acc, _| {
            acc.push(
                once(1)
                    .chain(acc.last().unwrap().windows(2).map(|x| x[0] + x[1]))
                    .chain(once(1))
                    .collect::<Vec<_>>(),
            );
            acc
        })
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::generate(5),
        [
            vec![1],
            vec![1, 1],
            vec![1, 2, 1],
            vec![1, 3, 3, 1],
            vec![1, 4, 6, 4, 1]
        ]
    );
    assert_eq!(Solution::generate(1), [[1]]);
}
