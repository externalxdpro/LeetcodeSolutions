// 78. Subsets
// Difficulty: Medium

// Given an integer array nums of unique elements, return all possible
// subsets
// (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
//     1 <= nums.length <= 10
//     -10 <= nums[i] <= 10
//     All the numbers of nums are unique.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = vec![];
        Self::recurse(&nums, 0, &mut vec![], &mut result);
        result
    }

    fn recurse(nums: &Vec<i32>, i: usize, temp: &mut Vec<i32>, result: &mut Vec<Vec<i32>>) {
        result.push(temp.clone());

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
        Solution::subsets(vec![1, 2, 3]),
        vec![
            vec![],
            vec![1],
            vec![1, 2],
            vec![1, 2, 3],
            vec![1, 3],
            vec![2],
            vec![2, 3],
            vec![3]
        ]
    );
    assert_eq!(Solution::subsets(vec![0]), vec![vec![], vec![0],]);
}
