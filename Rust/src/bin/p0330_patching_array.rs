// 330. Patching Array
// Difficulty: Hard

// Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
// Return the minimum number of patches required.

// Example 1:
// Input: nums = [1,3], n = 6
// Output: 1
// Explanation:
// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.

// Example 2:
// Input: nums = [1,5,10], n = 20
// Output: 2
// Explanation: The two patches can be [2, 4].

// Example 3:
// Input: nums = [1,2,2], n = 5
// Output: 0

// Constraints:
//     1 <= nums.length <= 1000
//     1 <= nums[i] <= 10^4
//     nums is sorted in ascending order.
//     1 <= n <= 2^31 - 1

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_patches(nums: Vec<i32>, n: i32) -> i32 {
        let (mut count, mut sum, mut i): (i64, i64, usize) = (0, 0, 0);
        while sum < n as i64 {
            if i < nums.len() && nums[i] as i64 <= sum + 1 {
                sum += nums[i] as i64;
                i += 1;
            } else {
                count += 1;
                sum += sum + 1;
            }
        }
        count as i32
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_330() {
        assert_eq!(Solution::min_patches(vec![1, 3], 6), 1);
        assert_eq!(Solution::min_patches(vec![1, 5, 10], 20), 2);
        assert_eq!(Solution::min_patches(vec![1, 2, 2], 5), 0);
        assert_eq!(Solution::min_patches(vec![1, 2, 31, 33], 2147483647), 28);
    }
}

fn main() {}
