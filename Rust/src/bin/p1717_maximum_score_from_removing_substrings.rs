// 1717. Maximum Score From Removing Substrings
// Difficulty: Medium

// You are given a string s and two integers x and y. You can perform two types of operations any number of times.

// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

// Example 1:

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.
// Example 2:

// Input: s = "aabbaaxybbaabb", x = 5, y = 4
// Output: 20

// Constraints:

// 1 <= s.length <= 105
// 1 <= x, y <= 104
// s consists of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn maximum_gain(s: String, x: i32, y: i32) -> i32 {
        let (mut a, mut b) = (0, 0);
        let less = x.min(y);
        let mut result = 0;

        for c in s.chars() {
            match c {
                'a' => {
                    if x < y && b > 0 {
                        b -= 1;
                        result += y;
                    } else {
                        a += 1;
                    }
                }
                'b' => {
                    if x > y && a > 0 {
                        a -= 1;
                        result += x;
                    } else {
                        b += 1;
                    }
                }
                _ => {
                    result += a.min(b) * less;
                    (a, b) = (0, 0);
                }
            }
        }

        result + a.min(b) * less
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::maximum_gain("cdbcbbaaabab".to_string(), 4, 5), 19);
    assert_eq!(
        Solution::maximum_gain("aabbaaxybbaabb".to_string(), 5, 4),
        20
    );
}
