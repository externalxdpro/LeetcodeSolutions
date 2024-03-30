// [992] Subarrays with K Different Integers
// Difficulty: Hard

// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.
//     For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

// Example 2:
// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

// Constraints:
//     1 <= nums.length <= 2 * 10^4
//     1 <= nums[i], k <= nums.length

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn subarrays_with_k_distinct(nums: Vec<i32>, k: i32) -> i32 {
        Self::find_at_most(&nums, k) - Self::find_at_most(&nums, k - 1)
    }

    fn find_at_most(nums: &Vec<i32>, k: i32) -> i32 {
        use std::collections::HashMap;
        let mut l = 0;
        let mut result = 0;
        let mut map = HashMap::<i32, i32>::new();

        for r in 0..nums.len() {
            map.entry(nums[r]).or_insert(0);
            map.entry(nums[r]).and_modify(|x| *x += 1);

            while map.len() as i32 > k && l <= r {
                map.entry(nums[l]).and_modify(|x| *x -= 1);
                if map[&nums[l]] == 0 {
                    map.remove(&nums[l]);
                }
                l += 1;
            }
            result += (r - l) as i32 + 1;
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_992() {
        assert_eq!(
            Solution::subarrays_with_k_distinct(vec![1, 2, 1, 2, 3], 2),
            7
        );
        assert_eq!(
            Solution::subarrays_with_k_distinct(vec![1, 2, 1, 3, 4], 3),
            3
        );
    }
}

fn main() {}
