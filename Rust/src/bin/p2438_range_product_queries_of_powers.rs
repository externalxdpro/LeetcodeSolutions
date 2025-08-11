// 2438. Range Product Queries of Powers
// Difficulty: Medium

// Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.

// You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.

// Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

// Example 1:

// Input: n = 15, queries = [[0,1],[2,2],[0,3]]
// Output: [2,4,64]
// Explanation:
// For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
// Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
// Answer to 2nd query: powers[2] = 4.
// Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
// Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.
// Example 2:

// Input: n = 2, queries = [[0,0]]
// Output: [2]
// Explanation:
// For n = 2, powers = [2].
// The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the same, so [2] is returned.

// Constraints:

// 1 <= n <= 109
// 1 <= queries.length <= 105
// 0 <= starti <= endi < powers.length

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn product_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        const MOD: i64 = 1e9 as i64 + 7;
        let mut result = vec![1; queries.len()];

        for i in 0..queries.len() {
            let (l, r) = (queries[i][0], queries[i][1]);
            let mut np = 0;
            let mut powers = [1; 32];
            for j in 0..32 {
                let t = 1 << j;
                if (t & n) != 0 {
                    powers[np] = t;
                    np += 1;
                }
            }

            for j in l..=r {
                let mut tmp = result[i] as i64;
                tmp *= powers[j as usize] as i64;
                tmp %= MOD;
                result[i] = tmp as i32;
            }
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::product_queries(15, vec![vec![0, 1], vec![2, 2], vec![0, 3]]),
        [2, 4, 64]
    );
    assert_eq!(Solution::product_queries(2, vec![vec![0, 0]]), [2]);
}
