// [242] Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
//     1 <= s.length, t.length <= 5 * 104
//     s and t consist of lowercase English letters.

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

pub struct Solution {}

// submission codes start here

// O(nlogn)
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut s_vec: Vec<char> = s.chars().collect();
        s_vec.sort();
        let mut t_vec: Vec<char> = t.chars().collect();
        t_vec.sort();
        s_vec == t_vec
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_242() {
        assert_eq!(
            Solution::is_anagram("anagram".to_string(), "nagaram".to_string()),
            true
        );
        assert_eq!(
            Solution::is_anagram("rat".to_string(), "car".to_string()),
            false
        );
        assert_eq!(
            Solution::is_anagram("big".to_string(), "burger".to_string()),
            false
        );
    }
}

fn main() {}
