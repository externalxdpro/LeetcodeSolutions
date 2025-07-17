// 3202. Find the Maximum Length of Valid Subsequence II
// Difficulty: Medium

// You are given an integer array nums and a positive integer k.

// A

// sub of nums with length x is called valid if it satisfies:

//     (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.

// Return the length of the longest valid subsequence of nums.

// Example 1:

// Input: nums = [1,2,3,4,5], k = 2

// Output: 5

// Explanation:

// The longest valid subsequence is [1, 2, 3, 4, 5].

// Example 2:

// Input: nums = [1,4,2,3,1,4], k = 3

// Output: 4

// Explanation:

// The longest valid subsequence is [1, 4, 1, 4].

// Constraints:

//     2 <= nums.length <= 103
//     1 <= nums[i] <= 107
//     1 <= k <= 103

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn maximum_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut memo = vec![vec![0; k as usize]; k as usize];
        let mut result = 0;
        for num in nums {
            let num = (num % k) as usize;
            for prev in 0..(k as usize) {
                memo[prev][num] = memo[num][prev] + 1;
                result = result.max(memo[prev][num]);
            }
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::maximum_length(vec![1, 2, 3, 4, 5], 2), 5);
    assert_eq!(Solution::maximum_length(vec![1, 4, 2, 3, 1, 4], 3), 4);
}
