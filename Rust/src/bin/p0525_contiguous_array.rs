// [525] Contiguous Array
// Difficulty: Medium

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Constraints:
//     1 <= nums.length <= 10^5
//     nums[i] is either 0 or 1.

pub struct Solution {}

// submission codes start here

use std::{cmp, collections::HashMap};

impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let mut max = 0;
        let mut count = 0;
        let mut map = HashMap::from([(0, -1)]);

        for (i, v) in nums.iter().enumerate() {
            match v {
                0 => count -= 1,
                _ => count += 1,
            }
            if map.contains_key(&count) {
                max = cmp::max(max, i as i32 - map[&count]);
            } else {
                map.insert(count, i as i32);
            }
        }

        max
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_525() {
        assert_eq!(Solution::find_max_length(vec![0, 1]), 2);
        assert_eq!(Solution::find_max_length(vec![0, 1, 0]), 2);
        assert_eq!(Solution::find_max_length(vec![0, 1, 0, 1]), 4);
        assert_eq!(Solution::find_max_length(vec![0, 0, 1, 0, 0, 0, 1, 1]), 6);
    }
}

fn main() {}
