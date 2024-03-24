// [287] Find the Duplicate Number
// Difficulty: Medium

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3

// Example 3:
// Input: nums = [3,3,3,3,3]
// Output: 3

// Constraints:
//     1 <= n <= 10^5
//     nums.length == n + 1
//     1 <= nums[i] <= n
//     All the integers in nums appear only once except for precisely one integer which appears two or more times.

// Follow up:
//     How can we prove that at least one duplicate number must exist in nums?
//     Can you solve the problem in linear runtime complexity?

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut slow = nums[0];
        let mut fast = nums[0];

        while {
            slow = nums[slow as usize];
            fast = nums[nums[fast as usize] as usize];

            fast != slow
        } {}

        slow = nums[0];
        while fast != slow {
            fast = nums[fast as usize];
            slow = nums[slow as usize];
        }

        slow
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_287() {
        assert_eq!(Solution::find_duplicate(vec![1, 3, 4, 2, 2]), 2);
        assert_eq!(Solution::find_duplicate(vec![3, 1, 3, 4, 2]), 3);
        assert_eq!(Solution::find_duplicate(vec![3, 3, 3, 3, 3]), 3);
    }
}

fn main() {}
