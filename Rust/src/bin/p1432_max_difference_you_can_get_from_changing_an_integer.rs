// 1432. Max Difference You Can Get From Changing an Integer
// Difficulty: Medium

// You are given an integer num. You will apply the following steps to num two separate times:

//     Pick a digit x (0 <= x <= 9).
//     Pick another digit y (0 <= y <= 9). Note y can be equal to x.
//     Replace all the occurrences of x in the decimal representation of num by y.

// Let a and b be the two results from applying the operation to num independently.

// Return the max difference between a and b.

// Note that neither a nor b may have any leading zeros, and must not be 0.

// Example 1:

// Input: num = 555
// Output: 888
// Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
// The second time pick x = 5 and y = 1 and store the new integer in b.
// We have now a = 999 and b = 111 and max difference = 888

// Example 2:

// Input: num = 9
// Output: 8
// Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
// The second time pick x = 9 and y = 1 and store the new integer in b.
// We have now a = 9 and b = 1 and max difference = 8

// Constraints:

//     1 <= num <= 108

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_diff(num: i32) -> i32 {
        let (mut min, mut max) = (num, num);
        let vec = Self::to_vec(num);

        for x in 0..=9 {
            for y in 0..=9 {
                let rep = Self::replace(&vec, x, y);
                if rep[0] != 0 {
                    let num = Self::to_num(rep);
                    min = std::cmp::min(min, num);
                    max = std::cmp::max(max, num);
                }
            }
        }

        max - min
    }

    fn to_vec(mut x: i32) -> Vec<i32> {
        let mut result = vec![];
        while x > 0 {
            result.push(x % 10);
            x /= 10;
        }
        result.reverse();
        result
    }

    fn to_num(digits: Vec<i32>) -> i32 {
        digits.into_iter().fold(0, |acc, x| acc * 10 + x)
    }

    fn replace(digits: &Vec<i32>, from: i32, to: i32) -> Vec<i32> {
        digits
            .into_iter()
            .map(|&x| if x == from { to } else { x })
            .collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::max_diff(555), 888);
    assert_eq!(Solution::max_diff(9), 8);
}
