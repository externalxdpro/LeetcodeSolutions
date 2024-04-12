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
        use std::{cmp, iter::zip};
        let max_lefts = height.iter().scan(0, Self::get_max);
        let max_rights = height
            .iter()
            .rev()
            .scan(0, Self::get_max)
            .collect::<Vec<i32>>()
            .into_iter()
            .rev();
        let boundary = zip(max_lefts, max_rights).map(|(x, y)| cmp::min(x, y));
        zip(boundary, height.iter())
            .map(|(x, &y)| (x - y).abs())
            .sum()
    }

    fn get_max(max: &mut i32, x: &i32) -> Option<i32> {
        *max = std::cmp::max(*max, *x);
        Some(*max)
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
