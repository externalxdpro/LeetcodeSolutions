// 1047. Remove All Adjacent Duplicates In String
// Difficulty: Easy

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

// Example 1:
// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

// Example 2:
// Input: s = "azxxzy"
// Output: "ay"

// Constraints:
//     1 <= s.length <= 10^5
//     s consists of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut result: Vec<char> = vec![];

        for c in s.chars() {
            let last = result.last();
            if last == Some(&c) {
                result.pop();
                continue;
            }
            result.push(c);
        }

        result.into_iter().collect()
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_num() {
        assert_eq!(Solution::remove_duplicates("abbaca".into()), "ca");
        assert_eq!(Solution::remove_duplicates("azxxzy".into()), "ay");
    }
}

fn main() {}
