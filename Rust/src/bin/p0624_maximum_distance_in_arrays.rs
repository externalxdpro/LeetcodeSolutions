// [#] Name
// Difficulty:

// You are given m arrays, where each array is sorted in ascending order.
// You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
// Return the maximum distance.

// Example 1:
// Input: arrays = [[1,2,3],[4,5],[1,2,3]]
// Output: 4
// Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

// Example 2:
// Input: arrays = [[1],[1]]
// Output: 0

// Constraints:
//     m == arrays.length
//     2 <= m <= 10^5
//     1 <= arrays[i].length <= 500
//     -10^4 <= arrays[i][j] <= 10^4
//     arrays[i] is sorted in ascending order.
//     There will be at most 10^5 integers in all the arrays.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
        let (mut smallest, mut biggest) = (arrays[0][0], *arrays[0].last().unwrap());
        let mut result = 0;

        for i in 1..arrays.len() {
            let curr = &arrays[i];
            result = result
                .max((*curr.last().unwrap() - smallest).abs())
                .max((biggest - curr[0]).abs());
            smallest = smallest.min(curr[0]);
            biggest = biggest.max(*curr.last().unwrap());
        }

        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::max_distance(vec![vec![1, 2, 3], vec![4, 5], vec![1, 2, 3]]),
        4
    );
    assert_eq!(Solution::max_distance(vec![vec![1], vec![1]]), 0);
    assert_eq!(Solution::max_distance(vec![vec![4], vec![1, 5]]), 3);
}
