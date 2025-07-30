// 2419. Longest Subarray With Maximum Bitwise AND
// Difficulty: Medium

// You are given an integer array nums of size n.

// Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

//     In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.

// Return the length of the longest such subarray.

// The bitwise AND of an array is the bitwise AND of all the numbers in it.

// A subarray is a contiguous sequence of elements within an array.

// Example 1:

// Input: nums = [1,2,3,3,2,2]
// Output: 2
// Explanation:
// The maximum possible bitwise AND of a subarray is 3.
// The longest subarray with that value is [3,3], so we return 2.

// Example 2:

// Input: nums = [1,2,3,4]
// Output: 1
// Explanation:
// The maximum possible bitwise AND of a subarray is 4.
// The longest subarray with that value is [4], so we return 1.

// Constraints:

//     1 <= nums.length <= 105
//     1 <= nums[i] <= 106

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let max = nums.iter().max().unwrap().clone();
        let mut i = nums.iter().position(|&x| x == max).unwrap();
        let mut result = 0;
        while i < nums.len() {
            let mut j = 0;
            while i < nums.len() && nums[i] == max {
                j += 1;
                i += 1;
            }
            result = result.max(j);
            i += 1;
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::longest_subarray(vec![1, 2, 3, 3, 2, 2]), 2);
    assert_eq!(Solution::longest_subarray(vec![1, 2, 3, 4]), 1);
}
