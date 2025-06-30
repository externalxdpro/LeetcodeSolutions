// 594. Longest Harmonious Subsequence
// Difficulty: Easy

// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious

// among all its possible subsequences.

// Example 1:

// Input: nums = [1,3,2,2,5,2,3,7]

// Output: 5

// Explanation:

// The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:

// Input: nums = [1,2,3,4]

// Output: 2

// Explanation:

// The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

// Example 3:

// Input: nums = [1,1,1,1]

// Output: 0

// Explanation:

// No harmonic subsequence exists.

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -109 <= nums[i] <= 109

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_lhs(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();

        let mut result = 0;
        let mut l = 0;
        for r in 1..nums.len() {
            while nums[r] - nums[l] > 1 {
                l += 1;
            }
            if nums[r] - nums[l] == 1 {
                result = result.max(r - l + 1);
            }
        }
        result as i32
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::find_lhs(vec![1, 3, 2, 2, 5, 2, 3, 7]), 5);
    assert_eq!(Solution::find_lhs(vec![1, 2, 3, 4]), 2);
    assert_eq!(Solution::find_lhs(vec![1, 1, 1, 1]), 0);
}
