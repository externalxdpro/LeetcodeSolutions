// [2016] Maximum Difference Between Increasing Elements
// Easy

// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
// Return the maximum difference. If no such i and j exists, return -1.

// Example 1:
// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

// Example 2:
// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].

// Example 3:
// Input: nums = [1,5,2,10]
// Output: 9
// Explanation:
// The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

// Constraints:
//     n == nums.length
//     2 <= n <= 1000
//     1 <= nums[i] <= 10^9

pub struct Solution {}

// submission codes start here

// Functional
impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        use std::cmp::min;
        nums.iter()
            .scan(i32::MAX, |s, &i| {
                *s = min(*s, i);
                Some(*s)
            })
            .zip(nums.iter())
            .map(|(x, &y)| y - x)
            .filter(|&i| i != 0)
            .max()
            .unwrap_or(-1)
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2016() {
        assert_eq!(Solution::maximum_difference(vec![7, 1, 5, 4]), 4);
        assert_eq!(Solution::maximum_difference(vec![9, 4, 3, 2]), -1);
        assert_eq!(Solution::maximum_difference(vec![1, 5, 2, 10]), 9);
    }
}

fn main() {}
