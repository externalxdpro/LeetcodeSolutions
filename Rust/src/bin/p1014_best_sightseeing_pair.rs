// 1014. Best Sightseeing Pair
// Difficulty: Medium

// You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

// The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

// Return the maximum score of a pair of sightseeing spots.

// Example 1:

// Input: values = [8,1,5,2,6]
// Output: 11
// Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

// Example 2:

// Input: values = [1,2]
// Output: 2

// Constraints:

//     2 <= values.length <= 5 * 104
//     1 <= values[i] <= 1000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_score_sightseeing_pair(values: Vec<i32>) -> i32 {
        let mut max_l = vec![0; values.len()];
        max_l[0] = values[0];
        let mut result = 0;
        for i in 1..values.len() {
            result = result.max(max_l[i - 1] + values[i] - i as i32);
            max_l[i] = max_l[i - 1].max(values[i] + i as i32);
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::max_score_sightseeing_pair(vec![8, 1, 5, 2, 6]),
        11
    );
    assert_eq!(Solution::max_score_sightseeing_pair(vec![1, 2]), 2);
}
