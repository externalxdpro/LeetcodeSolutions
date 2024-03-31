// [2444] Count Subarrays With Fixed Bounds
// Hard

// You are given an integer array nums and two integers minK and maxK.
// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
//     The minimum value in the subarray is equal to minK.
//     The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.
// A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

// Example 2:
// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

// Constraints:
//     2 <= nums.length <= 10^5
//     1 <= nums[i], minK, maxK <= 10^6

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, min_k: i32, max_k: i32) -> i64 {
        use std::cmp::{max, min};

        let mut result = 0;
        let mut min_i = -1;
        let mut max_i = -1;
        let mut l = 0;

        for r in 0..nums.len() {
            let curr = nums[r];
            if curr < min_k || curr > max_k {
                l = r + 1;
                continue;
            }
            if curr == min_k {
                min_i = r as i32;
            }
            if curr == max_k {
                max_i = r as i32;
            }
            result += max(min(min_i, max_i) - l as i32 + 1, 0) as i64;
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2444() {
        assert_eq!(Solution::count_subarrays(vec![1, 3, 5, 2, 7, 5], 1, 5), 2);
        assert_eq!(Solution::count_subarrays(vec![1, 1, 1, 1], 1, 1), 10);
    }
}

fn main() {}
