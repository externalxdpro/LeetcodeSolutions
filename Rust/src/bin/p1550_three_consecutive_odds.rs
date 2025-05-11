// 1550. Three Consecutive Odds
// Difficulty: Easy

// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

// Example 1:

// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.

// Example 2:

// Input: arr = [1,2,34,3,4,5,7,23,12]
// Output: true
// Explanation: [5,7,23] are three consecutive odds.

// Constraints:

//     1 <= arr.length <= 1000
//     1 <= arr[i] <= 1000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        arr.windows(3)
            .any(|x| x[0] % 2 == 1 && x[1] % 2 == 1 && x[2] % 2 == 1)
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::three_consecutive_odds(vec![2, 6, 4, 1]), false);
    assert_eq!(
        Solution::three_consecutive_odds(vec![1, 2, 34, 3, 4, 5, 7, 23, 12]),
        true
    );
}
