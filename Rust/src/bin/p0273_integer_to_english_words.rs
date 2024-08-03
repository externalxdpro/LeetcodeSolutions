// 273. Integer to English Words
// Difficulty: Hard

// Convert a non-negative integer num to its English words representation.

// Example 1:
// Input: num = 123
// Output: "One Hundred Twenty Three"

// Example 2:
// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"

// Example 3:
// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

// Constraints:
//     0 <= num <= 2^31 - 1

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn number_to_words(mut num: i32) -> String {
        use std::collections::HashMap;
        let map: HashMap<i32, &str> = HashMap::from([
            (0, "Zero"),
            (1, "One"),
            (2, "Two"),
            (3, "Three"),
            (4, "Four"),
            (5, "Five"),
            (6, "Six"),
            (7, "Seven"),
            (8, "Eight"),
            (9, "Nine"),
            (10, "Ten"),
            (11, "Eleven"),
            (12, "Twelve"),
            (13, "Thirteen"),
            (14, "Fourteen"),
            (15, "Fifteen"),
            (16, "Sixteen"),
            (17, "Seventeen"),
            (18, "Eighteen"),
            (19, "Nineteen"),
            (20, "Twenty"),
            (30, "Thirty"),
            (40, "Forty"),
            (50, "Fifty"),
            (60, "Sixty"),
            (70, "Seventy"),
            (80, "Eighty"),
            (90, "Ninety"),
            (100, "Hundred"),
            (1000, "Thousand"),
            (1000000, "Million"),
            (1000000000, "Billion"),
        ]);

        if num <= 20 {
            return map[&num].to_string();
        }

        let mut i = 0;
        let mut result = String::new();

        while num > 0 {
            if num % 1000 > 0 {
                result = Self::get_value(num % 1000, &map)
                    + if i != 0 { map[&(10i32.pow(i * 3))] } else { "" }
                    + " "
                    + result.as_str();
            }
            num /= 1000;
            i += 1;
        }

        result.trim().to_string()
    }

    fn get_value(num: i32, map: &std::collections::HashMap<i32, &str>) -> String {
        if num == 0 {
            "".to_string()
        } else if num < 20 {
            map[&num].to_string() + " "
        } else if num < 100 {
            map[&(num - (num % 10))].to_string() + " " + Self::get_value(num % 10, map).as_str()
        } else {
            map[&(num / 100)].to_string() + " Hundred " + Self::get_value(num % 100, map).as_str()
        }
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_273() {
        assert_eq!(Solution::number_to_words(123), "One Hundred Twenty Three");
        assert_eq!(
            Solution::number_to_words(12345),
            "Twelve Thousand Three Hundred Forty Five"
        );
        assert_eq!(
            Solution::number_to_words(1234567),
            "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
        );
    }
}

fn main() {}
