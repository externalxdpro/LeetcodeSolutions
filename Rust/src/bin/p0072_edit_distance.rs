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
        let mut dp = [[-1; 1000]; 1000];
        let (str1, str2): (Vec<char>, Vec<char>) =
            (word1.chars().collect(), word2.chars().collect());
        return Self::recurse(
            &str1,
            &str2,
            str1.len().wrapping_sub(1),
            str2.len().wrapping_sub(1),
            &mut dp,
        );
    }

    fn recurse(str1: &[char], str2: &[char], i1: usize, i2: usize, dp: &mut [[i32; 1000]]) -> i32 {
        if i1 == usize::MAX {
            return i2 as i32 + 1;
        } else if i2 == usize::MAX {
            return i1 as i32 + 1;
        }

        if dp[i1][i2] != -1 {
            return dp[i1][i2];
        }

        if str1[i1] == str2[i2] {
            dp[i1][i2] = Self::recurse(str1, str2, i1.wrapping_sub(1), i2.wrapping_sub(1), dp);
            return dp[i1][i2];
        } else {
            let insert = Self::recurse(str1, str2, i1, i2.wrapping_sub(1), dp);
            let rem = Self::recurse(str1, str2, i1.wrapping_sub(1), i2, dp);
            let repl = Self::recurse(str1, str2, i1.wrapping_sub(1), i2.wrapping_sub(1), dp);
            let max = insert.min(rem);
            dp[i1][i2] = 1 + max.min(repl);
            return dp[i1][i2];
        }
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
