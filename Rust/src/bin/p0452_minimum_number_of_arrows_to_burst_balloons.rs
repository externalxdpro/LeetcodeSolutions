// [452] Minimum Number of Arrows to Burst Balloons
// Difficulty: Medium

// There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
// Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
// Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

// Example 1:
// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

// Example 2:
// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
// Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

// Example 3:
// Input: points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
// - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].

// Constraints:
//     1 <= points.length <= 10^5
//     points[i].length == 2
//     -2^31 <= xstart < xend <= 2^31 - 1

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort();
        let mut arrows = 1;
        let mut end = points[0][1];

        for b in points.into_iter().skip(1) {
            if b[0] > end {
                arrows += 1;
                end = b[1]
            } else {
                end = std::cmp::min(end, b[1]);
            }
        }

        arrows
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    // use super::*;

    use crate::Solution;

    #[test]
    fn test_452() {
        assert_eq!(
            Solution::find_min_arrow_shots(vec![vec![10, 16], vec![2, 8], vec![1, 6], vec![7, 12]]),
            2
        );
        assert_eq!(
            Solution::find_min_arrow_shots(vec![vec![1, 2], vec![3, 4], vec![5, 6], vec![7, 8]]),
            4
        );
        assert_eq!(
            Solution::find_min_arrow_shots(vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![4, 5]]),
            2
        );
    }
}

fn main() {}
