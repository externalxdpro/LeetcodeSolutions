// [2962] Count Subarrays Where Max Element Appears at Least K Times
// Difficulty: Medium

// You are given an integer array nums and a positive integer k.
// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
// A subarray is a contiguous sequence of elements within an array.

// Example 1:
// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

// Example 2:
// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times.

// Constraints:
//     1 <= nums.length <= 10^5
//     1 <= nums[i] <= 10^6
//     1 <= k <= 10^5

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let max = *nums.iter().max().unwrap();
        let mut max_count = 0;
        let mut l = 0;
        let mut result = 0;

        for r in 0..nums.len() {
            if nums[r] == max {
                max_count += 1;
            }
            while max_count >= k {
                if nums[l] == max {
                    max_count -= 1;
                }
                l += 1;
            }
            result += l as i64;
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2962() {
        assert_eq!(Solution::count_subarrays(vec![1, 3, 2, 3, 3], 2), 6);
        assert_eq!(Solution::count_subarrays(vec![1, 4, 2, 1], 3), 0);
    }
}

fn main() {}
