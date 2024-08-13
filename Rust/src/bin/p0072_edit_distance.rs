// 72. Edit Distance
// Difficulty: Medium

// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
//     Insert a character
//     Delete a character
//     Replace a character

// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// Constraints:
//     0 <= word1.length, word2.length <= 500
//     word1 and word2 consist of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (word1, word2): (Vec<char>, Vec<char>) =
            (word1.chars().collect(), word2.chars().collect());
        let (len1, len2) = (word1.len(), word2.len());
        let mut dp: Vec<Vec<i32>> = vec![vec![-1; len2 + 1]; len1 + 1];
        for i in 0..=len1 {
            dp[i][0] = i as i32;
        }
        for j in 0..=len2 {
            dp[0][j] = j as i32;
        }
        for i in 1..=len1 {
            for j in 1..=len2 {
                if word1[i - 1] == word2[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + dp[i - 1][j].min(dp[i][j - 1]).min(dp[i - 1][j - 1])
                }
            }
        }

        dp[len1][len2]
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::min_distance("horse".to_string(), "ros".to_string()),
        3
    );
    assert_eq!(
        Solution::min_distance("intention".to_string(), "execution".to_string()),
        5
    );
}
