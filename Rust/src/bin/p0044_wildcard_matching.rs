// 44. Wildcard Matching
// Difficulty: Hard

// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
//     '?' Matches any single character.
//     '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Example 3:
// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// Constraints:
//     0 <= s.length, p.length <= 2000
//     s contains only lowercase English letters.
//     p contains only lowercase English letters, '?' or '*'.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let mut dp = vec![vec![false; p.len() + 1]; s.len() + 1];
        let (s, p): (Vec<char>, Vec<char>) = (s.chars().collect(), p.chars().collect());
        dp[s.len()][p.len()] = true;

        for i in (0..=s.len()).rev() {
            for j in (0..p.len()).rev() {
                if p[j] == '*' {
                    dp[i][j] = dp[i][j + 1];

                    if i < s.len() {
                        dp[i][j] = dp[i][j] || dp[i + 1][j] || dp[i + 1][j + 1];
                    }
                } else {
                    dp[i][j] = i < s.len() && (s[i] == p[j] || p[j] == '?') && dp[i + 1][j + 1];
                }
            }
        }

        dp[0][0]
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0044() {
        assert_eq!(Solution::is_match("aa".into(), "a".into()), false);
        assert_eq!(Solution::is_match("aa".into(), "*".into()), true);
        assert_eq!(Solution::is_match("cb".into(), "?a".into()), false);
    }
}

fn main() {}
