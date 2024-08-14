// 77. Combinations
// Difficulty: Medium

// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.

// Example 1:
// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

// Example 2:
// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.

// Constraints:
//     1 <= n <= 20
//     1 <= k <= n

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut result = vec![];
        Self::recurse(1, n, k, &mut vec![], &mut result);
        result
    }

    fn recurse(i: i32, n: i32, k: i32, temp: &mut Vec<i32>, result: &mut Vec<Vec<i32>>) {
        if i > n {
            if k == 0 {
                result.push(temp.clone());
            }
            return;
        }

        temp.push(i);
        Self::recurse(i + 1, n, k - 1, temp, result);
        temp.pop();
        Self::recurse(i + 1, n, k, temp, result);
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::combine(4, 2),
        vec![
            vec![1, 2],
            vec![1, 3],
            vec![1, 4],
            vec![2, 3],
            vec![2, 4],
            vec![3, 4]
        ]
    );
    assert_eq!(Solution::combine(1, 1), vec![vec![1]]);
}
