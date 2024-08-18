// 84. Largest Rectangle in Histogram
// Difficulty: Hard

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:
// Input: heights = [2,4]
// Output: 4

// Constraints:
//     1 <= heights.length <= 10^5
//     0 <= heights[i] <= 10^4

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        if heights.len() == 0 {
            return 0;
        } else if heights.len() == 1 {
            return heights[0];
        }

        let mut result = heights[0];
        let mut stack = vec![];
        for i in 0..heights.len() {
            while stack.last().is_some_and(|&j| heights[j] > heights[i]) {
                let j = stack.pop().unwrap();
                result = result.max(heights[j] * (i - stack.last().map_or(0, |&k| k + 1)) as i32);
            }
            stack.push(i);
        }
        while let Some(i) = stack.pop() {
            result = result
                .max(heights[i] * (heights.len() - stack.last().map_or(0, |&j| j + 1)) as i32);
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::largest_rectangle_area(vec![2, 1, 5, 6, 2, 3]), 10);
    assert_eq!(Solution::largest_rectangle_area(vec![2, 4]), 4);
}
