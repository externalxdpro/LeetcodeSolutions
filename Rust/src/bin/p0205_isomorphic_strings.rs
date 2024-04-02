// [205] Isomorphic Strings
// Easy

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Example 3:
// Input: s = "paper", t = "title"
// Output: true

// Constraints:
//     1 <= s.length <= 5 * 10^4
//     t.length == s.length
//     s and t consist of any valid ascii character.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        use std::collections::HashSet;

        let zip = s.chars().zip(t.chars()).collect::<HashSet<_>>();

        zip.len() == s.chars().collect::<HashSet<_>>().len()
            && zip.len() == t.chars().collect::<HashSet<_>>().len()
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_205() {
        assert_eq!(Solution::is_isomorphic("egg".into(), "add".into()), true);
        assert_eq!(Solution::is_isomorphic("foo".into(), "bar".into()), false);
        assert_eq!(
            Solution::is_isomorphic("paper".into(), "title".into()),
            true
        );
    }
}

fn main() {}
