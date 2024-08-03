// 1071. Greatest Common Divisor of Strings
// Difficulty: Easy

// For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

// Example 1:
// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"

// Example 2:
// Input: str1 = "ABABAB", str2 = "ABAB"
// Output: "AB"

// Example 3:
// Input: str1 = "LEET", str2 = "CODE"
// Output: ""

// Constraints:
//     1 <= str1.length, str2.length <= 1000
//     str1 and str2 consist of English uppercase letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        if str1.clone() + str2.as_str() == str2.clone() + str1.as_str() {
            str1[..(Self::gcd(str1.len(), str2.len()) as usize)].to_string()
        } else {
            "".to_string()
        }
    }

    fn gcd(mut n: usize, mut m: usize) -> usize {
        assert!(n != 0 && m != 0);
        while m != 0 {
            if m < n {
                std::mem::swap(&mut m, &mut n);
            }
            m %= n;
        }
        n
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1071() {
        assert_eq!(
            Solution::gcd_of_strings("ABCABC".into(), "ABC".into()),
            "ABC"
        );
        assert_eq!(
            Solution::gcd_of_strings("ABABAB".into(), "ABAB".into()),
            "AB"
        );
        assert_eq!(Solution::gcd_of_strings("LEET".into(), "CODE".into()), "");
    }
}

fn main() {}
