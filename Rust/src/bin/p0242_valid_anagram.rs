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

// O(n)
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut counts = vec![0; 26];
        s.bytes().for_each(|x| counts[(x - b'a') as usize] += 1);
        t.bytes().for_each(|x| counts[(x - b'a') as usize] -= 1);

        !counts.into_iter().any(|x| x != 0)
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
