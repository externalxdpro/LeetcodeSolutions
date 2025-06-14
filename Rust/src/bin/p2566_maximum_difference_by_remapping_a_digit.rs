// 2566. Maximum Difference by Remapping a Digit
// Difficulty: Easy

// You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

// Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

// Notes:

//     When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
//     Bob can remap a digit to itself, in which case num does not change.
//     Bob can remap different digits for obtaining minimum and maximum values respectively.
//     The resulting number after remapping can contain leading zeroes.

// Example 1:

// Input: num = 11891
// Output: 99009
// Explanation:
// To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
// To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
// The difference between these two numbers is 99009.

// Example 2:

// Input: num = 90
// Output: 99
// Explanation:
// The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
// Thus, we return 99.

// Constraints:

//     1 <= num <= 108

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_max_difference(num: i32) -> i32 {
        let stk = Self::to_stack(num);
        let max = *stk.iter().find(|&&x| x != 9).unwrap_or(&0);
        let min = *stk.iter().find(|&&x| x != 0).unwrap_or(&0);
        let max = Self::replace(&stk, (max, 9));
        let min = Self::replace(&stk, (min, 0));
        max - min
    }

    fn to_stack(mut x: i32) -> Vec<i32> {
        let mut result = vec![];
        while x > 0 {
            result.push(x % 10);
            x /= 10;
        }
        result.reverse();
        result
    }

    fn replace(stk: &Vec<i32>, rep: (i32, i32)) -> i32 {
        let mut result = 0;
        for &x in stk {
            result *= 10;
            if x == rep.0 {
                result += rep.1;
            } else {
                result += x;
            }
        }

        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::min_max_difference(11891), 99009);
    assert_eq!(Solution::min_max_difference(90), 99);
    assert_eq!(Solution::min_max_difference(99999), 99999);
    assert_eq!(Solution::min_max_difference(456), 900);
}
