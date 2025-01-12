// 2116. Check if a Parentheses String Can Be Valid
// Difficulty: Medium

// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

//     It is ().
//     It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//     It can be written as (A), where A is a valid parentheses string.

// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

//     If locked[i] is '1', you cannot change s[i].
//     But if locked[i] is '0', you can change s[i] to either '(' or ')'.

// Return true if you can make s a valid parentheses string. Otherwise, return false.

// Example 1:

// Input: s = "))()))", locked = "010100"
// Output: true
// Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
// We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.

// Example 2:

// Input: s = "()()", locked = "0000"
// Output: true
// Explanation: We do not need to make any changes because s is already valid.

// Example 3:

// Input: s = ")", locked = "0"
// Output: false
// Explanation: locked permits us to change s[0].
// Changing s[0] to either '(' or ')' will not make s valid.

// Constraints:

//     n == s.length == locked.length
//     1 <= n <= 105
//     s[i] is either '(' or ')'.
//     locked[i] is either '0' or '1'.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn can_be_valid(s: String, locked: String) -> bool {
        if s.len() % 2 == 1 {
            return false;
        }

        let (mut open, mut unlocked) = (vec![], vec![]);
        for (i, (c, l)) in std::iter::zip(s.chars(), locked.chars()).enumerate() {
            match (c, l) {
                (_, '0') => unlocked.push(i),
                ('(', '1') => open.push(i),
                (')', '1') => {
                    if open.last().is_some() {
                        open.pop();
                    } else if unlocked.last().is_some() {
                        unlocked.pop();
                    } else {
                        return false;
                    }
                }
                _ => return false,
            }
        }

        while !open.is_empty() && !unlocked.is_empty() && open.last() < unlocked.last() {
            open.pop();
            unlocked.pop();
        }

        if open.is_empty() {
            true
        } else {
            false
        }
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::can_be_valid("))()))".to_string(), "010100".to_string()),
        true
    );
    assert_eq!(
        Solution::can_be_valid("()()".to_string(), "0000".to_string()),
        true
    );
    assert_eq!(
        Solution::can_be_valid(")".to_string(), "0".to_string()),
        false
    );
    assert_eq!(
        Solution::can_be_valid(
            "))))(())((()))))((()((((((())())((()))((((())()()))(()".to_string(),
            "101100101111110000000101000101001010110001110000000101".to_string()
        ),
        false
    );
}
