// 2264. Largest 3-Same-Digit Number in String
// Difficulty: Easy

// You are given a string num representing a large integer. An integer is good if it meets the following conditions:

// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.

// Note:

// A substring is a contiguous sequence of characters within a string.
// There may be leading zeroes in num or a good integer.

// Example 1:

// Input: num = "6777133339"
// Output: "777"
// Explanation: There are two distinct good integers: "777" and "333".
// "777" is the largest, so we return "777".
// Example 2:

// Input: num = "2300019"
// Output: "000"
// Explanation: "000" is the only good integer.
// Example 3:

// Input: num = "42352338"
// Output: ""
// Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.

// Constraints:

// 3 <= num.length <= 1000
// num only consists of digits.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn largest_good_integer(num: String) -> String {
        use itertools::Itertools;
        num.chars()
            .tuple_windows()
            .filter(|&(a, b, c)| a == b && b == c)
            .map(|(a, b, c)| format!("{a}{b}{c}"))
            .max()
            .unwrap_or("".to_string())
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::largest_good_integer("6777133339".to_string()),
        "777"
    );
    assert_eq!(Solution::largest_good_integer("2300019".to_string()), "000");
    assert_eq!(Solution::largest_good_integer("42352338".to_string()), "");
}
