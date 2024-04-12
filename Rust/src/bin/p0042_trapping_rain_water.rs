// [42] Trapping Rain Water
// Hard

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:
//     n == height.length
//     1 <= n <= 2 * 10^4
//     0 <= height[i] <= 10^5

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        use std::cmp::{max, min};
        use std::iter::zip;

        let mut max_left = height[0];
        let mut max_lefts = vec![0; height.len()];
        for i in 0..height.len() {
            max_left = max(max_left, height[i]);
            max_lefts[i] = max_left;
        }

        let mut max_right = *height.last().unwrap();
        let mut max_rights = vec![0; height.len()];
        for i in (0..height.len()).rev() {
            max_right = max(max_right, height[i]);
            max_rights[i] = max_right;
        }

        let boundary: Vec<i32> = zip(max_lefts, max_rights).map(|(x, y)| min(x, y)).collect();
        std::iter::zip(boundary, height)
            .map(|(x, y)| (x - y).abs())
            .sum()
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_42() {
        assert_eq!(Solution::trap(vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), 6);
        assert_eq!(Solution::trap(vec![4, 2, 0, 3, 2, 5]), 9);
    }
}

fn main() {}
