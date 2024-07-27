// 2976. Minimum Cost to Convert String I
// Difficulty: Medium

// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

// Example 1:
// Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
// Output: 28
// Explanation: To convert the string "abcd" to string "acbe":
// - Change value at index 1 from 'b' to 'c' at a cost of 5.
// - Change value at index 2 from 'c' to 'e' at a cost of 1.
// - Change value at index 2 from 'e' to 'b' at a cost of 2.
// - Change value at index 3 from 'd' to 'e' at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28.
// It can be shown that this is the minimum possible cost.

// Example 2:
// Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
// Output: 12
// Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.

// Example 3:
// Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
// Output: -1
// Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.

// Constraints:
//     1 <= source.length == target.length <= 10^5
//     source, target consist of lowercase English letters.
//     1 <= cost.length == original.length == changed.length <= 2000
//     original[i], changed[i] are lowercase English letters.
//     1 <= cost[i] <= 10^6
//     original[i] != changed[i]

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn minimum_cost(
        source: String,
        target: String,
        original: Vec<char>,
        changed: Vec<char>,
        cost: Vec<i32>,
    ) -> i64 {
        let mut dis = vec![vec![i32::MAX; 26]; 26];
        for i in 0..26 {
            dis[i][i] = 0;
        }
        for i in 0..cost.len() {
            dis[original[i] as usize - 'a' as usize][changed[i] as usize - 'a' as usize] = dis
                [original[i] as usize - 'a' as usize][changed[i] as usize - 'a' as usize]
                .min(cost[i]);
        }
        for k in 0..26 {
            for i in 0..26 {
                if dis[i][k] < i32::MAX {
                    for j in 0..26 {
                        if dis[k][j] < i32::MAX {
                            dis[i][j] = dis[i][j].min(dis[i][k] + dis[k][j]);
                        }
                    }
                }
            }
        }
        let mut ans = 0;
        for (s, t) in source.chars().zip(target.chars()) {
            let (s, t) = (s as usize - 'a' as usize, t as usize - 'a' as usize);
            if dis[s][t] == i32::MAX {
                return -1;
            } else {
                ans += dis[s][t] as i64;
            }
        }

        ans
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2976() {
        assert_eq!(
            Solution::minimum_cost(
                "aaaa".to_string(),
                "bbbb".to_string(),
                vec!['a', 'c'],
                vec!['c', 'b'],
                vec![1, 2]
            ),
            12
        );
        assert_eq!(
            Solution::minimum_cost(
                "abcd".to_string(),
                "abce".to_string(),
                vec!['a'],
                vec!['e'],
                vec![10000]
            ),
            -1
        );
    }
}

fn main() {}
