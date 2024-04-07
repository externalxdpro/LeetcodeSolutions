// [678] Valid Parenthesis String
// Medium

// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
//     Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//     Any right parenthesis ')' must have a corresponding left parenthesis '('.
//     Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//     '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "(*)"
// Output: true

// Example 3:
// Input: s = "(*))"
// Output: true

// Constraints:
//     1 <= s.length <= 100
//     s[i] is '(', ')' or '*'.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let (mut low, mut high): (usize, Option<usize>) = (0, Some(0));

        for i in s.chars() {
            match i {
                '(' => (low, high) = (low + 1, Some(high.unwrap() + 1)),
                ')' => (low, high) = (low.saturating_sub(1), high.unwrap().checked_sub(1)),
                '*' => (low, high) = (low.saturating_sub(1), Some(high.unwrap() + 1)),
                _ => (),
            }
            if let None = high {
                return false;
            }
        }

        low == 0
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_678() {
        assert_eq!(Solution::check_valid_string("()".into()), true);
        assert_eq!(Solution::check_valid_string("(*)".into()), true);
        assert_eq!(Solution::check_valid_string("(*))".into()), true);
        assert_eq!(Solution::check_valid_string("))((".into()), false);
        assert_eq!(Solution::check_valid_string("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())".into()), false);
    }
}

fn main() {}
