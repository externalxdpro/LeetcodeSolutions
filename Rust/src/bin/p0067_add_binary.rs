// 67. Add Binary
// Difficulty: Easy

// Given two binary strings a and b, return their sum as a binary string.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

// Constraints:
//     1 <= a.length, b.length <= 10^4
//     a and b consist only of '0' or '1' characters.
//     Each string does not contain leading zeros except for the zero itself.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let (a, b): (Vec<char>, Vec<char>) = (a.chars().collect(), b.chars().collect());
        let (mut i, mut j) = (a.len() - 1, b.len() - 1);
        let mut result: Vec<char> = vec![];
        let mut carry = 0;

        while i != usize::MAX || j != usize::MAX || carry > 0 {
            if i != usize::MAX {
                carry += a[i] as i32 - '0' as i32;
                i = i.wrapping_sub(1);
            }
            if j != usize::MAX {
                carry += b[j] as i32 - '0' as i32;
                j = j.wrapping_sub(1);
            }
            result.push(char::from_u32((carry % 2 + '0' as i32) as u32).unwrap());
            carry /= 2;
        }

        result.into_iter().rev().collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::add_binary("11".to_string(), "1".to_string()),
        "100"
    );
    assert_eq!(
        Solution::add_binary("1010".to_string(), "1011".to_string()),
        "10101"
    );
}
