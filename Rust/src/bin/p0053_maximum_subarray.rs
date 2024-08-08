// 53. Maximum Subarray
// Difficulty: Medium

// Given an integer array nums, find the
// subarray
// with the largest sum, and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// Constraints:
//     1 <= nums.length <= 10^5
//     -104 <= nums[i] <= 10^4

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let (mut max, mut result) = (0, i32::MIN);

        for num in nums {
            max = num.max(num + max);
            result = result.max(max);
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0053() {
        assert_eq!(
            Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4]),
            6
        );
        assert_eq!(Solution::max_sub_array(vec![1]), 1);
        assert_eq!(Solution::max_sub_array(vec![5, 4, -1, 7, 8]), 23);
    }
}

fn main() {}
