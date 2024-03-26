// [41] First Missing Positive
// Difficulty: Hard

// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example 1:
// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.

// Constraints:
//     1 <= nums.length <= 10^5
//     -2^31 <= nums[i] <= 2^31 - 1

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn first_missing_positive(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        for i in 0..n {
            if nums[i] <= 0 || nums[i] > n as i32 {
                nums[i] = (n + 1) as i32;
            }
        }

        for i in 0..n {
            let mut num = nums[i].abs();
            if num > n as i32 {
                continue;
            }
            num -= 1;
            nums[num as usize] = -1 * nums[num as usize].abs();
        }

        for i in 0..n {
            if nums[i] >= 0 {
                return (i + 1) as i32;
            }
        }

        (n + 1) as i32
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_41() {
        assert_eq!(Solution::first_missing_positive(vec![1, 2, 0]), 3);
        assert_eq!(Solution::first_missing_positive(vec![3, 4, -1, 1]), 2);
        assert_eq!(Solution::first_missing_positive(vec![7, 8, 9, 11, 12]), 1);
        assert_eq!(Solution::first_missing_positive(vec![1, 1]), 2);
    }
}

fn main() {}
