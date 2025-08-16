// 1323. Maximum 69 Number
// Difficulty: Easy

// You are given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// Example 1:

// Input: num = 9669
// Output: 9969
// Explanation:
// Changing the first digit results in 6669.
// Changing the second digit results in 9969.
// Changing the third digit results in 9699.
// Changing the fourth digit results in 9666.
// The maximum number is 9969.
// Example 2:

// Input: num = 9996
// Output: 9999
// Explanation: Changing the last digit 6 to 9 results in the maximum number.
// Example 3:

// Input: num = 9999
// Output: 9999
// Explanation: It is better not to apply any change.

// Constraints:

// 1 <= num <= 104
// num consists of only 6 and 9 digits.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        let mut digs = Self::to_vec(num);
        let i = digs.iter().position(|&x| x == 6);
        if let Some(i) = i {
            digs[i] = 9;
            digs.into_iter().fold(0, |acc, x| acc * 10 + x)
        } else {
            num
        }
    }

    fn to_vec(mut n: i32) -> Vec<i32> {
        let mut result = vec![];
        while n > 0 {
            result.push(n % 10);
            n /= 10;
        }
        result.reverse();
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::maximum69_number(9669), 9969);
    assert_eq!(Solution::maximum69_number(9996), 9999);
    assert_eq!(Solution::maximum69_number(9999), 9999);
}
