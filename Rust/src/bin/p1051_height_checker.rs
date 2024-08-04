// 1051. Height Checker
// Difficulty: Easy

// A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
// You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).
// Return the number of indices where heights[i] != expected[i].

// Example 1:
// Input: heights = [1,1,4,2,1,3]
// Output: 3
// Explanation:
// heights:  [1,1,4,2,1,3]
// expected: [1,1,1,2,3,4]
// Indices 2, 4, and 5 do not match.

// Example 2:
// Input: heights = [5,1,2,3,4]
// Output: 5
// Explanation:
// heights:  [5,1,2,3,4]
// expected: [1,2,3,4,5]
// All indices do not match.

// Example 3:
// Input: heights = [1,2,3,4,5]
// Output: 0
// Explanation:
// heights:  [1,2,3,4,5]
// expected: [1,2,3,4,5]
// All indices match.

// Constraints:
//     1 <= heights.length <= 100
//     1 <= heights[i] <= 100

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut expected = heights.clone();
        expected.sort_unstable();

        heights
            .into_iter()
            .zip(expected)
            .fold(0, |acc, (h, e)| acc + if h != e { 1 } else { 0 })
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1051() {
        assert_eq!(Solution::height_checker(vec![1, 1, 4, 2, 1, 3]), 3);
        assert_eq!(Solution::height_checker(vec![5, 1, 2, 3, 4]), 5);
        assert_eq!(Solution::height_checker(vec![1, 2, 3, 4, 5]), 0);
    }
}

fn main() {}
