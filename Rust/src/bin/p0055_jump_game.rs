// 55. Jump Game
// Difficulty: Medium

// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

// Constraints:
//     1 <= nums.length <= 10^4
//     0 <= nums[i] <= 10^5

pub struct Solution {}

// submission codes start here

use std::collections::HashMap;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        Self::recurse(&nums, 0, &mut HashMap::new())
    }

    fn recurse(nums: &Vec<i32>, i: usize, dp: &mut HashMap<usize, bool>) -> bool {
        if i == nums.len() - 1 {
            return true;
        } else if i >= nums.len() {
            return false;
        } else if let Some(&x) = dp.get(&i) {
            return x;
        }

        for j in ((i + 1)..=(i + nums[i] as usize)).rev() {
            if Self::recurse(nums, j, dp) {
                dp.insert(i, true);
                return true;
            }
        }

        dp.insert(i, false);
        false
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0055() {
        assert_eq!(Solution::can_jump(vec![2, 3, 1, 1, 4]), true);
        assert_eq!(Solution::can_jump(vec![3, 2, 1, 0, 4]), false);
        assert_eq!(
            Solution::can_jump(vec![
                5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4,
                1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5
            ]),
            true
        );
    }
}

fn main() {}
