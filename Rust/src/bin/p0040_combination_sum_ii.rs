// 40. Combination Sum II
// Difficulty: Medium

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output:
// [
// [1,2,2],
// [5]
// ]

// Constraints:
//     1 <= candidates.length <= 100
//     1 <= candidates[i] <= 50
//     1 <= target <= 30

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn combination_sum2(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort_unstable();
        let mut result: Vec<Vec<i32>> = vec![];
        Self::recurse(&candidates, target, 0, &mut vec![], &mut result);
        result
    }

    fn recurse(
        candidates: &[i32],
        target: i32,
        i: usize,
        curr: &mut Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if target == 0 {
            result.push(curr.clone());
            return;
        }

        for j in i..candidates.len() {
            if j > i && candidates[j] == candidates[j - 1] {
                continue;
            }
            if candidates[j] > target {
                break;
            }
            curr.push(candidates[j]);
            Self::recurse(candidates, target - candidates[j], j + 1, curr, result);
            curr.pop();
        }
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::combination_sum2(vec![10, 1, 2, 7, 6, 1, 5], 8),
        vec![vec![1, 1, 6], vec![1, 2, 5], vec![1, 7], vec![2, 6]]
    );
    assert_eq!(
        Solution::combination_sum2(vec![2, 5, 2, 1, 2], 5),
        vec![vec![1, 2, 2], vec![5]]
    );
}
