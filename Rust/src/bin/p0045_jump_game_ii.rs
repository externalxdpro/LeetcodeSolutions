// 45. Jump Game II
// Difficulty: Medium

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
//     0 <= j <= nums[i] and
//     i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

// Constraints:
//     1 <= nums.length <= 10^4
//     0 <= nums[i] <= 1000
//     It's guaranteed that you can reach nums[n - 1].

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn jump(mut nums: Vec<i32>) -> i32 {
        if nums.len() <= 1 {
            return 0;
        }

        for i in 1..nums.len() {
            nums[i] = nums[i - 1].max(nums[i] + i as i32);
        }

        let (mut curr_i, mut jumps) = (0, 0);
        while curr_i < nums.len() - 1 {
            jumps += 1;
            curr_i = nums[curr_i] as usize;
        }

        jumps
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0045() {
        assert_eq!(Solution::jump(vec![2, 3, 1, 1, 4]), 2);
        assert_eq!(Solution::jump(vec![2, 3, 0, 1, 4]), 2);
        assert_eq!(
            Solution::jump(vec![
                5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4,
                1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5
            ]),
            5
        );
    }
}

fn main() {}
