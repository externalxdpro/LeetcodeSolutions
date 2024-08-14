// 719. Find K-th Smallest Pair Distance
// Difficulty: Hard

// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

// Example 1:
// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.

// Example 2:
// Input: nums = [1,1,1], k = 2
// Output: 0

// Example 3:
// Input: nums = [1,6,1], k = 3
// Output: 5

// Constraints:
//     n == nums.length
//     2 <= n <= 10^4
//     0 <= nums[i] <= 10^6
//     1 <= k <= n * (n - 1) / 2

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn smallest_distance_pair(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();
        let (mut l, mut r) = (0, (nums.last().unwrap() - nums.first().unwrap()) as usize);
        while l < r {
            let m = l + (r - l) / 2;
            if Self::is_small_pairs(&nums, k, m as i32) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        l as i32
    }

    fn is_small_pairs(nums: &[i32], k: i32, m: i32) -> bool {
        let mut count = 0;
        let mut l = 0;
        for r in 1..nums.len() {
            while nums[r] - nums[l] > m {
                l += 1;
            }
            count += (r - l) as i32;
        }
        return count >= k;
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::smallest_distance_pair(vec![1, 3, 1], 1), 0);
    assert_eq!(Solution::smallest_distance_pair(vec![1, 1, 1], 2), 0);
    assert_eq!(Solution::smallest_distance_pair(vec![1, 6, 1], 3), 5);
}
