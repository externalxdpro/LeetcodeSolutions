// [3115] Maximum Prime Difference
// Medium

// You are given an integer array nums.
// Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.

// Example 1:
// Input: nums = [4,2,9,5,3]
// Output: 3
// Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.

// Example 2:
// Input: nums = [4,8,2,8]
// Output: 0
// Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.

// Constraints:
//     1 <= nums.length <= 3 * 10^5
//     1 <= nums[i] <= 100
//     The input is generated such that the number of prime numbers in the nums is at least one.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn maximum_prime_difference(nums: Vec<i32>) -> i32 {
        let is_primes = [
            false, false, true, true, false, true, false, true, false, false, false, true, false,
            true, false, false, false, true, false, true, false, false, false, true, false, false,
            false, false, false, true, false, true, false, false, false, false, false, true, false,
            false, false, true, false, true, false, false, false, true, false, false, false, false,
            false, true, false, false, false, false, false, true, false, true, false, false, false,
            false, false, true, false, false, false, true, false, true, false, false, false, false,
            false, true, false, false, false, true, false, false, false, false, false, true, false,
            false, false, false, false, false, false, true, false, false, false,
        ];

        let (mut a, mut b) = (nums.len(), 0usize);

        for (i, x) in nums.into_iter().enumerate() {
            if is_primes[x as usize] {
                a = a.min(i);
                b = b.max(i);
            }
        }
        (b - a) as i32
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_num() {
        assert_eq!(Solution::maximum_prime_difference(vec![4, 2, 9, 5, 3]), 3);
        assert_eq!(Solution::maximum_prime_difference(vec![4, 8, 2, 8]), 0);
    }
}

fn main() {}
