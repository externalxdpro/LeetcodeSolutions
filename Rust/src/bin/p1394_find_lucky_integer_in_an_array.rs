// 1394. Find Lucky Integer in an Array
// Difficulty: Easy

// Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

// Return the largest lucky integer in the array. If there is no lucky integer return -1.

// Example 1:

// Input: arr = [2,2,3,4]
// Output: 2
// Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

// Example 2:

// Input: arr = [1,2,2,3,3,3]
// Output: 3
// Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

// Example 3:

// Input: arr = [2,2,2,3,3]
// Output: -1
// Explanation: There are no lucky numbers in the array.

// Constraints:

//     1 <= arr.length <= 500
//     1 <= arr[i] <= 500

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_lucky(mut arr: Vec<i32>) -> i32 {
        use itertools::Itertools;
        arr.sort_unstable_by(|a, b| b.cmp(a));
        arr.into_iter()
            .chunk_by(|&x| x)
            .into_iter()
            .map(|(x, i)| (x, i.count() as i32))
            .filter(|(a, b)| a == b)
            .next()
            .unwrap_or((-1, -1))
            .0
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::find_lucky(vec![2, 2, 3, 4]), 2);
    assert_eq!(Solution::find_lucky(vec![1, 2, 2, 3, 3, 3]), 3);
    assert_eq!(Solution::find_lucky(vec![2, 2, 2, 3, 3]), -1);
}
