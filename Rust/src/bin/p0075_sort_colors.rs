// 75. Sort Colors
// Difficulty: Medium

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

// Constraints:
//     n == nums.length
//     1 <= n <= 300
//     nums[i] is either 0, 1, or 2.

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let (mut l, mut r, mut i) = (0, nums.len() - 1, 0);
        while i <= r && r > 0 {
            match nums[i] {
                0 => {
                    nums.swap(l, i);
                    (l, i) = (l + 1, i + 1);
                }
                1 => {
                    i += 1;
                }
                2 => {
                    nums.swap(i, r);
                    r -= 1;
                }
                _ => (),
            }
        }
    }
}

// submission codes end

fn main() {}
