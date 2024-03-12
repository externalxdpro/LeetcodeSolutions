/**
 * [9] Intersection of Two Arrays
 *
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 *
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 *
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 * Constraints:
 *     -2^31 <= x <= 2^31 - 1
 *
 * Follow up: Could you solve it without converting the integer to a string?
 *
 */

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let str = x.to_string();
        if str.len() % 2 == 0 {
            str[..str.len() / 2].to_string()
                == str[str.len() / 2..].chars().rev().collect::<String>()
        } else {
            str[..str.len() / 2].to_string()
                == str[str.len() / 2 + 1..].chars().rev().collect::<String>()
        }
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_9() {
        assert_eq!(Solution::is_palindrome(121), true);
        assert_eq!(Solution::is_palindrome(-121), false);
    }
}

fn main() {}
