// 2040. Kth Smallest Product of Two Sorted Arrays
// Difficulty: Hard

// Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

// Example 1:
// Input: nums1 = [2,5], nums2 = [3,4], k = 2
// Output: 8
// Explanation: The 2 smallest products are:
// - nums1[0] * nums2[0] = 2 * 3 = 6
// - nums1[0] * nums2[1] = 2 * 4 = 8
// The 2nd smallest product is 8.

// Example 2:
// Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
// Output: 0
// Explanation: The 6 smallest products are:
// - nums1[0] * nums2[1] = (-4) * 4 = -16
// - nums1[0] * nums2[0] = (-4) * 2 = -8
// - nums1[1] * nums2[1] = (-2) * 4 = -8
// - nums1[1] * nums2[0] = (-2) * 2 = -4
// - nums1[2] * nums2[0] = 0 * 2 = 0
// - nums1[2] * nums2[1] = 0 * 4 = 0
// The 6th smallest product is 0.

// Example 3:
// Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
// Output: -6
// Explanation: The 3 smallest products are:
// - nums1[0] * nums2[4] = (-2) * 5 = -10
// - nums1[0] * nums2[3] = (-2) * 4 = -8
// - nums1[4] * nums2[0] = 2 * (-3) = -6
// The 3rd smallest product is -6.

// Constraints:
//     1 <= nums1.length, nums2.length <= 5 * 10^4
//     -10^5 <= nums1[i], nums2[j] <= 10^5
//     1 <= k <= nums1.length * nums2.length
//     nums1 and nums2 are sorted.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn kth_smallest_product(nums1: Vec<i32>, nums2: Vec<i32>, mut k: i64) -> i64 {
        use std::{cmp::Reverse, collections::BinaryHeap};
        let mut products: BinaryHeap<Reverse<i64>> = BinaryHeap::new();
        for num1 in nums1 {
            for &num2 in nums2.iter() {
                products.push(Reverse(num1 as i64 * num2 as i64));
            }
        }

        while {
            k -= 1;
            k > 0
        } {
            products.pop();
        }
        products.pop().unwrap().0
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2040() {
        assert_eq!(Solution::kth_smallest_product(vec![2, 5], vec![3, 4], 2), 8);
        assert_eq!(
            Solution::kth_smallest_product(vec![-4, -2, 0, 3], vec![2, 4], 6),
            0
        );
        assert_eq!(
            Solution::kth_smallest_product(vec![-2, -1, 0, 1, 2], vec![-3, -1, 2, 4, 5], 3),
            -6
        );
    }
}

fn main() {}
