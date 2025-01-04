// 1930. Unique Length-3 Palindromic Subsequences
// Difficulty: Medium

// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

//     For example, "ace" is a subsequence of "abcde".

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")

// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".

// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")

// Constraints:

//     3 <= s.length <= 105
//     s consists of only lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        use std::collections::HashSet;
        let letters: HashSet<char> = s.chars().collect();
        let s: Vec<char> = s.chars().collect();
        let mut result = 0;

        for letter in letters {
            let (mut i, mut j) = (-1, 0);

            for k in 0..s.len() {
                if s[k] == letter {
                    if i == -1 {
                        i = k as i32;
                    }
                    j = k as i32;
                }
            }

            let mut between = HashSet::new();
            for k in (i + 1)..j {
                between.insert(s[k as usize]);
            }
            result += between.len() as i32;
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::count_palindromic_subsequence("aabca".to_string()),
        3
    );
    assert_eq!(
        Solution::count_palindromic_subsequence("adc".to_string()),
        0
    );
    assert_eq!(
        Solution::count_palindromic_subsequence("bbcbaba".to_string()),
        4
    );
}
