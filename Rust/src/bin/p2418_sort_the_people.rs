// 2418. Sort the People
// Difficulty: Easy

// You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
// For each index i, names[i] and heights[i] denote the name and height of the ith person.
// Return names sorted in descending order by the people's heights.

// Example 1:
// Input: names = ["Mary","John","Emma"], heights = [180,165,170]
// Output: ["Mary","Emma","John"]
// Explanation: Mary is the tallest, followed by Emma and John.

// Example 2:
// Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
// Output: ["Bob","Alice","Bob"]
// Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

// Constraints:
//     n == names.length == heights.length
//     1 <= n <= 103
//     1 <= names[i].length <= 20
//     1 <= heights[i] <= 10^5
//     names[i] consists of lower and upper case English letters.
//     All the values of heights are distinct.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        use std::collections::BTreeSet;
        let zipped: BTreeSet<(i32, String)> = heights.into_iter().zip(names).collect();
        zipped.into_iter().map(|x| x.1).rev().collect()
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2418() {
        assert_eq!(
            Solution::sort_people(
                vec!["Mary", "John", "Emma"]
                    .into_iter()
                    .map(|x| x.to_string())
                    .collect(),
                vec![180, 165, 170]
            ),
            ["Mary", "Emma", "John"]
        );
        assert_eq!(
            Solution::sort_people(
                vec!["Alice", "Bob", "Bob"]
                    .into_iter()
                    .map(|x| x.to_string())
                    .collect(),
                vec![155, 185, 150]
            ),
            ["Bob", "Alice", "Bob"]
        );
    }
}

fn main() {}
