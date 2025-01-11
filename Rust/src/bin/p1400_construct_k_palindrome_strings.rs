// 1400. Construct K Palindrome Strings
// Difficulty: Medium

// Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

// Example 1:

// Input: s = "annabelle", k = 2
// Output: true
// Explanation: You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

// Example 2:

// Input: s = "leetcode", k = 3
// Output: false
// Explanation: It is impossible to construct 3 palindromes using all the characters of s.

// Example 3:

// Input: s = "true", k = 4
// Output: true
// Explanation: The only possible solution is to put each character in a separate string.

// Constraints:

//     1 <= s.length <= 105
//     s consists of lowercase English letters.
//     1 <= k <= 105

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        let k = k as usize;
        if s.len() < k {
            return false;
        }
        if s.len() == k {
            return true;
        }

        let freq = s.chars().fold([0; 26], |mut curr, x| {
            curr[x as usize - 'a' as usize] += 1;
            curr
        });
        freq.into_iter().filter(|x| x % 2 == 1).count() <= k
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::can_construct("annabelle".to_string(), 2), true);
    assert_eq!(Solution::can_construct("leetcode".to_string(), 3), false);
    assert_eq!(Solution::can_construct("true".to_string(), 4), true);
}
