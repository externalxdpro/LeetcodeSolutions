// 90. Subsets II
// Difficulty: Medium

// Given an integer array nums that may contain duplicates, return all possible
// subsets
// (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
//     1 <= nums.length <= 10
//     -10 <= nums[i] <= 10

pub struct Solution {}

// submission codes start here

use std::collections::BTreeSet;

impl Solution {
    pub fn subsets_with_dup(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort_unstable();
        let mut result = BTreeSet::new();
        Self::recurse(&nums, 0, &mut vec![], &mut result);
        result.into_iter().collect()
    }

    fn recurse(nums: &Vec<i32>, i: usize, temp: &mut Vec<i32>, result: &mut BTreeSet<Vec<i32>>) {
        result.insert(temp.clone());

        for i in i..nums.len() {
            temp.push(nums[i]);
            Self::recurse(nums, i + 1, temp, result);
            temp.pop();
        }
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::subsets_with_dup(vec![1, 2, 2]),
        vec![
            vec![],
            vec![1],
            vec![1, 2],
            vec![1, 2, 2],
            vec![2],
            vec![2, 2]
        ]
    );
    assert_eq!(Solution::subsets_with_dup(vec![0]), vec![vec![], vec![0]]);
}
