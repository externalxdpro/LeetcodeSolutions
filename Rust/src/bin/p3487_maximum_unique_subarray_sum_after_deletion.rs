// 3487. Maximum Unique Subarray Sum After Deletion
// Difficulty: Easy

// You are given an integer array nums.

// You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

// All elements in the subarray are unique.
// The sum of the elements in the subarray is maximized.
// Return the maximum sum of such a subarray.

// Example 1:

// Input: nums = [1,2,3,4,5]

// Output: 15

// Explanation:

// Select the entire array without deleting any element to obtain the maximum sum.

// Example 2:

// Input: nums = [1,1,0,1,1]

// Output: 1

// Explanation:

// Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array [1] to obtain the maximum sum.

// Example 3:

// Input: nums = [1,2,-1,-2,1,0,-1]

// Output: 3

// Explanation:

// Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_sum(mut nums: Vec<i32>) -> i32 {
        use itertools::Itertools;
        nums.sort_unstable_by(|a, b| b.cmp(&a));
        let mut iter = nums.iter().dedup().filter(|&&x| x > 0).peekable();
        if iter.peek().is_some() {
            iter.sum()
        } else {
            nums[0]
        }
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::max_sum(vec![1, 2, 3, 4, 5]), 15);
    assert_eq!(Solution::max_sum(vec![1, 1, 0, 1, 1]), 1);
    assert_eq!(Solution::max_sum(vec![1, 2, -1, -2, 1, 0, -1]), 3);
    assert_eq!(Solution::max_sum(vec![-100]), -100);
}
