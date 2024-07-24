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
    pub fn kth_smallest_product(nums1: Vec<i32>, nums2: Vec<i32>, k: i64) -> i64 {
        let (neg1, pos1): (Vec<i32>, Vec<i32>) = nums1.iter().partition(|&&x| x < 0);
        let (neg2, pos2): (Vec<i32>, Vec<i32>) = nums2.iter().partition(|&&x| x < 0);
        let rneg1: Vec<i32> = neg1.iter().cloned().rev().collect();
        let rpos1: Vec<i32> = pos1.iter().cloned().rev().collect();
        let rneg2: Vec<i32> = neg2.iter().cloned().rev().collect();
        let rpos2: Vec<i32> = pos2.iter().cloned().rev().collect();
        let countle = |mid: i64| -> i64 {
            Self::countle(&neg1, &rpos2, mid)
                + Self::countle(&rneg1, &rneg2, mid)
                + Self::countle(&rpos1, &neg2, mid)
                + Self::countle(&pos1, &pos2, mid)
        };

        let mut r = (-(10_i64.pow(10)), 10_i64.pow(10));
        while r.0 != r.1 {
            let mid = r.0 + (r.1 - r.0) / 2;
            if countle(mid) < k {
                r.0 = mid + 1;
            } else {
                r.1 = mid;
            }
        }
        r.0
    }

    fn countle(nums1: &[i32], nums2: &[i32], k: i64) -> i64 {
        let mut i = nums2.len();
        let mut count = 0;
        for &v in nums1 {
            while i > 0 && (nums2[i - 1] as i64) * (v as i64) > k {
                i -= 1;
            }
            count += i as i64;
        }

        count
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
