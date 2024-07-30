// 1653. Minimum Deletions to Make String Balanced
// Difficulty: Medium

// You are given a string s consisting only of characters 'a' and 'b'​​​​.
// You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
// Return the minimum number of deletions needed to make s balanced.

// Example 1:
// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

// Example 2:
// Input: s = "bbaaaaabb"
// Output: 2
// Explanation: The only solution is to delete the first two characters.

// Constraints:
//     1 <= s.length <= 10^5
//     s[i] is 'a' or 'b'​​.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let (mut a_after, mut b_before) = (s.chars().filter(|&c| c == 'a').count(), 0);
        let mut ans = i32::MAX;

        for c in s.chars() {
            if c == 'a' {
                a_after -= 1;
            }
            ans = ans.min((a_after + b_before) as i32);
            if c == 'b' {
                b_before += 1;
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
    fn test_1653() {
        assert_eq!(Solution::minimum_deletions("aababbab".into()), 2);
        assert_eq!(Solution::minimum_deletions("bbaaaaabb".into()), 2);
        assert_eq!(Solution::minimum_deletions("b".into()), 0);
        assert_eq!(Solution::minimum_deletions("bb".into()), 0);
        assert_eq!(Solution::minimum_deletions("bbbbbbbaabbbbbaaabbbabbbbaabbbbbbaabbaaabaabbbaaaabaaababbbabbabbaaaabbbabbbbbaabbababbbaaaaaababaaababaabbabbbaaaabbbbbabbabaaaabbbaba".into()), 60);
    }
}

fn main() {}
