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
        fn is_prime(i: &(usize, &i32)) -> bool {
            let primes = vec![
                2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                83, 89, 97,
            ];
            primes.into_iter().find(|x| x == i.1).is_some()
        }

        let a = nums.iter().enumerate().find(is_prime).unwrap().0;
        let b = nums.iter().enumerate().rfind(is_prime).unwrap().0;
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
