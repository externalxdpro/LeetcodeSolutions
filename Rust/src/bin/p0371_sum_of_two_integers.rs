// [371] Sum of Two Integers
// Difficulty: Medium

// Given two integers a and b, return the sum of the two integers without using the operators + and -.

// Example 1:
// Input: a = 1, b = 2
// Output: 3

// Example 2:
// Input: a = 2, b = 3
// Output: 5

// Constraints:
//     -1000 <= a, b <= 1000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn get_sum(mut a: i32, mut b: i32) -> i32 {
        while b != 0 {
            let temp = a & b;
            a = a ^ b;
            b = temp << 1;
        }
        a
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_371() {
        assert_eq!(Solution::get_sum(1, 2), 3);
        assert_eq!(Solution::get_sum(2, 3), 5);
    }
}

fn main() {}
