// 3201. Find the Maximum Length of Valid Subsequence I
// Difficulty: Medium

// You are given an integer array nums.
// A subsequence sub of nums with length x is called valid if it satisfies:

// (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
// Return the length of the longest valid subsequence of nums.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: nums = [1,2,3,4]

// Output: 4

// Explanation:

// The longest valid subsequence is [1, 2, 3, 4].

// Example 2:

// Input: nums = [1,2,1,1,2,1,2]

// Output: 6

// Explanation:

// The longest valid subsequence is [1, 2, 1, 2, 1, 2].

// Example 3:

// Input: nums = [1,3]

// Output: 2

// Explanation:

// The longest valid subsequence is [1, 3].

// Constraints:

// 2 <= nums.length <= 2 * 105
// 1 <= nums[i] <= 107

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let (mut evens, mut odds, mut alts) = (0, 0, 1);
        let mut parity = nums[0] % 2;

        for num in nums {
            if num % 2 == 0 {
                evens += 1;
                if parity == 1 {
                    alts += 1;
                }
            } else {
                odds += 1;
                if parity == 0 {
                    alts += 1;
                }
            }
            parity = num % 2;
        }

        [evens, odds, alts].into_iter().max().unwrap()
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::maximum_length(vec![1, 2, 3, 4]), 4);
    assert_eq!(Solution::maximum_length(vec![1, 2, 1, 1, 2, 1, 2]), 6);
    assert_eq!(Solution::maximum_length(vec![1, 3]), 2);
}
