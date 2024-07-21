// 2392. Build a Matrix With Conditions
// Difficulty: Hard

// You are given a positive integer k. You are also given:
//     a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
//     a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.
// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.
// The matrix should also satisfy the following conditions:
//     The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
//     The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

// Example 1:
// Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output: [[3,0,0],[0,0,1],[0,2,0]]
// Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
// The row conditions are the following:
// - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
// - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
// The column conditions are the following:
// - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
// - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
// Note that there may be multiple correct answers.

// Example 2:
// Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
// Output: []
// Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
// No matrix can satisfy all the conditions, so we return the empty matrix.

// Constraints:
//     2 <= k <= 400
//     1 <= rowConditions.length, colConditions.length <= 10^4
//     rowConditions[i].length == colConditions[i].length == 2
//     1 <= abovei, belowi, lefti, righti <= k
//     abovei != belowi
//     lefti != righti

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn build_matrix(
        k: i32,
        row_conditions: Vec<Vec<i32>>,
        col_conditions: Vec<Vec<i32>>,
    ) -> Vec<Vec<i32>> {
        use std::collections::HashMap;

        let k = k as usize;
        let row_order = Self::generate_topo_sort(row_conditions, k);
        let col_order = Self::generate_topo_sort(col_conditions, k);

        if row_order.len() < k || col_order.len() < k {
            return vec![];
        }

        let mut m: HashMap<i32, usize> = HashMap::new();
        for i in 0..k {
            m.insert(col_order[i], i);
        }

        let mut ans = vec![vec![0; k]; k];
        for i in 0..k {
            ans[i][*m.get(&row_order[i]).unwrap()] = row_order[i];
        }
        ans
    }

    fn generate_topo_sort(a: Vec<Vec<i32>>, k: usize) -> Vec<i32> {
        use std::collections::VecDeque;

        let mut deg: Vec<i32> = vec![0; k];
        let mut order: Vec<i32> = vec![];
        let mut graph: Vec<Vec<i32>> = vec![vec![]; k];
        let mut q: VecDeque<i32> = VecDeque::new();

        for c in a {
            graph[(c[0] - 1) as usize].push(c[1] - 1);
            deg[(c[1] - 1) as usize] += 1;
        }
        for i in 0..k {
            if deg[i] == 0 {
                q.push_back(i as i32);
            }
        }
        while !q.is_empty() {
            let x = q.pop_front().unwrap();
            order.push(x + 1);
            for &y in graph[x as usize].iter() {
                deg[y as usize] -= 1;
                if deg[y as usize] == 0 {
                    q.push_back(y);
                }
            }
        }

        order
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2392() {
        assert_eq!(
            Solution::build_matrix(
                3,
                vec![vec![1, 2], vec![3, 2]],
                vec![vec![2, 1], vec![3, 2]]
            ),
            vec![vec![0, 0, 1], vec![3, 0, 0], vec![0, 2, 0]]
        );
        assert_eq!(
            Solution::build_matrix(
                3,
                vec![vec![1, 2], vec![2, 3], vec![3, 1], vec![2, 3]],
                vec![vec![2, 1]]
            ),
            Vec::<Vec<i32>>::new()
        );
    }
}

fn main() {}
