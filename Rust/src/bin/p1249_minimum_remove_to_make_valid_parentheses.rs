// 1249. Minimum Remove to Make Valid Parentheses
// Medium

// Given a string s of '(' , ')' and lowercase English characters.
// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
// Formally, a parentheses string is valid if and only if:
//     It is the empty string, contains only lowercase characters, or
//     It can be written as AB (A concatenated with B), where A and B are valid strings, or
//     It can be written as (A), where A is a valid string.

// Example 1:
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

// Example 2:
// Input: s = "a)b(c)d"
// Output: "ab(c)d"

// Example 3:
// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.

// Constraints:
//     1 <= s.length <= 10^5
//     s[i] is either'(' , ')', or lowercase English letter.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut temp = String::with_capacity(s.len());
        let mut result = String::with_capacity(s.len());
        let mut open = 0;

        for c in s.chars() {
            if c != '(' && c != ')' {
                temp.push(c);
            } else if c == '(' {
                open += 1;
                temp.push(c);
            } else if open > 0 {
                open -= 1;
                temp.push(c);
            }
        }
        if open <= 0 {
            return temp;
        }

        open = 0;
        for c in temp.chars().rev() {
            if c != '(' && c != ')' {
                result.push(c);
            } else if c == ')' {
                open += 1;
                result.push(c);
            } else if open > 0 {
                open -= 1;
                result.push(c);
            }
        }

        result.chars().rev().collect()
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1249() {
        assert_eq!(
            Solution::min_remove_to_make_valid("lee(t(c)o)de)".into()),
            "lee(t(c)o)de".to_string()
        );
        assert_eq!(
            Solution::min_remove_to_make_valid("a)b(c)d".into()),
            "ab(c)d".to_string()
        );
        assert_eq!(
            Solution::min_remove_to_make_valid("))((".into()),
            "".to_string()
        );
        assert_eq!(
            Solution::min_remove_to_make_valid("(a(b(c)d)".into()),
            "a(b(c)d)".to_string()
        );
    }
}

fn main() {}
