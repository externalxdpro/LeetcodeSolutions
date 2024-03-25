// [442] Find All Duplicates in an Array
// Difficulty: Medium

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

// Example 2:
// Input: nums = [1,1,2]
// Output: [1]

// Example 3:
// Input: nums = [1]
// Output: []

// Constraints:
//     n == nums.length
//     1 <= n <= 10^5
//     1 <= nums[i] <= n
//     Each element in nums appears once or twice.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_duplicates(mut nums: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::with_capacity(nums.len());

        for i in 0..nums.len() {
            let curr = nums[i].abs() as usize - 1;
            if nums[curr] < 0 {
                result.push(nums[i].abs());
                continue;
            }
            nums[curr] *= -1;
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_442() {
        assert_eq!(
            Solution::find_duplicates(vec![4, 3, 2, 7, 8, 2, 3, 1]),
            vec![2, 3]
        );
        assert_eq!(Solution::find_duplicates(vec![1, 1, 2]), vec![1]);
        assert_eq!(Solution::find_duplicates(vec![1]), vec![]);
    }
}

fn main() {}
