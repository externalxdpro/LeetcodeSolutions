// 10. Regular Expression Matching
// Difficulty: Hard

// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
//     '.' Matches any single character.​​​​
//     '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

// Example 3:
// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".

// Constraints:
//     1 <= s.length <= 20
//     1 <= p.length <= 20
//     s contains only lowercase English letters.
//     p contains only lowercase English letters, '.', and '*'.
//     It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        Self::is_match_aux(s.as_str(), p.as_str())
    }

    fn is_match_aux(s: &str, p: &str) -> bool {
        if p.is_empty() {
            return s.is_empty();
        }
        let first_match = !s.is_empty()
            && (p.chars().nth(0).unwrap() == s.chars().nth(0).unwrap()
                || p.chars().nth(0).unwrap() == '.');

        if p.len() >= 2 && p.chars().nth(1).unwrap() == '*' {
            Self::is_match_aux(s, &p[2..]) || (first_match && Self::is_match_aux(&s[1..], p))
        } else {
            first_match && Self::is_match_aux(&s[1..], &p[1..])
        }
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_0010() {
        assert_eq!(Solution::is_match("aa".to_string(), "a".to_string()), false);
        assert_eq!(Solution::is_match("aa".to_string(), "a*".to_string()), true);
        assert_eq!(Solution::is_match("ab".to_string(), ".*".to_string()), true);
        assert_eq!(
            Solution::is_match("ab".to_string(), ".*c".to_string()),
            false
        );
    }
}

fn main() {}
