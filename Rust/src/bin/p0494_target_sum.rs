// 494. Target Sum
// Difficulty: Medium

// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

//     For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// Example 2:

// Input: nums = [1], target = 1
// Output: 1

// Constraints:

//     1 <= nums.length <= 20
//     0 <= nums[i] <= 1000
//     0 <= sum(nums[i]) <= 1000
//     -1000 <= target <= 1000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let total: i32 = nums.iter().sum();
        let mut result = 0;
        let mut dp = vec![vec![0; 2 * total as usize + 1]; nums.len()];
        Self::recurse(&nums, 0, target, &mut result, &mut dp);
        result
    }

    fn recurse(nums: &[i32], i: usize, target: i32, result: &mut i32, dp: &mut Vec<Vec<i32>>) {
        if i == nums.len() {
            if target == 0 {
                *result += 1;
            }
            return;
        }
        Self::recurse(nums, i + 1, target - nums[i], result, dp);
        Self::recurse(nums, i + 1, target + nums[i], result, dp);
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::find_target_sum_ways(vec![1, 1, 1, 1, 1], 3), 5);
    assert_eq!(Solution::find_target_sum_ways(vec![1], 1), 1);
}
