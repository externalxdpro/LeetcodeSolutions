// [402] Remove K Digits
// Medium

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Constraints:
//     1 <= k <= num.length <= 10^5
//     num consists of only digits.
//     num does not have any leading zeros except for the zero itself.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn remove_kdigits(num: String, k: i32) -> String {
        let mut k = k as usize;
        let mut stack: Vec<char> = Vec::new();

        for i in num.chars() {
            while k > 0 && !stack.is_empty() && *stack.last().unwrap() > i {
                stack.pop();
                k -= 1;
            }
            stack.push(i);
        }
        for _ in 0..k {
            stack.pop();
        }

        let result = stack.into_iter().collect::<String>();
        let result = result.trim_start_matches('0');
        if result.is_empty() {
            "0".to_string()
        } else {
            result.to_string()
        }
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_402() {
        assert_eq!(
            Solution::remove_kdigits("1432219".to_string(), 3),
            "1219".to_string()
        );
        assert_eq!(
            Solution::remove_kdigits("10200".to_string(), 1),
            "200".to_string()
        );
        assert_eq!(
            Solution::remove_kdigits("10".to_string(), 2),
            "0".to_string()
        );
        assert_eq!(
            Solution::remove_kdigits("10".to_string(), 1),
            "0".to_string()
        );
    }
}

fn main() {}
