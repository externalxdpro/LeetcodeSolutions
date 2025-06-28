// 2099. Find Subsequence of Length K With the Largest Sum
// Difficulty: Easy

// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [2,1,3,3], k = 2
// Output: [3,3]
// Explanation:
// The subsequence has the largest sum of 3 + 3 = 6.

// Example 2:

// Input: nums = [-1,-2,3,4], k = 3
// Output: [-1,3,4]
// Explanation:
// The subsequence has the largest sum of -1 + 3 + 4 = 6.

// Example 3:

// Input: nums = [3,4,3,3], k = 2
// Output: [3,4]
// Explanation:
// The subsequence has the largest sum of 3 + 4 = 7.
// Another possible subsequence is [4, 3].

// Constraints:

//     1 <= nums.length <= 1000
//     -105 <= nums[i] <= 105
//     1 <= k <= nums.length

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut nums: Vec<_> = nums.into_iter().enumerate().collect();
        nums.sort_unstable_by(|&a, &b| b.1.cmp(&a.1));
        let mut nums: Vec<_> = nums.into_iter().take(k as usize).collect();
        nums.sort_unstable();
        nums.into_iter().map(|(_, v)| v).collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::max_subsequence(vec![2, 1, 3, 3], 2), [3, 3]);
    assert_eq!(Solution::max_subsequence(vec![-1, -2, 3, 4], 3), [-1, 3, 4]);
    assert_eq!(Solution::max_subsequence(vec![3, 4, 3, 3], 2), [3, 4]);
    assert_eq!(Solution::max_subsequence(vec![50, -75], 2), [50, -75]);
}
