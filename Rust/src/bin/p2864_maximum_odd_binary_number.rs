/**
 * [2864] Maximum Odd Binary Number
 *
 * You are given a binary string s that contains at least one '1'.
 * You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
 * Return a string representing the maximum odd binary number that can be created from the given combination.
 * Note that the resulting string can have leading zeros.
 *  
 * <strong class="example">Example 1:
 *
 * Input: s = "010"
 * Output: "001"
 * Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
 *
 * <strong class="example">Example 2:
 *
 * Input: s = "0101"
 * Output: "1001"
 * Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
 *
 *
 * Constraints:
 *
 * 	1 <= s.length <= 100
 * 	s consists only of '0' and '1'.
 * 	s contains at least one '1'.
 *
 */
pub struct Solution {}

// problem: https://leetcode.com/problems/maximum-odd-binary-number/
// discuss: https://leetcode.com/problems/maximum-odd-binary-number/discuss/?currentPage=1&orderBy=most_votes&query=

// submission codes start here

impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let ones = s.chars().filter(|&x| x == '1').count();
        "1".repeat(ones - 1) + "0".repeat(s.len() - ones).as_str() + "1"
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2864() {
        assert_eq!(
            String::from("001"),
            Solution::maximum_odd_binary_number(String::from("010"))
        );
        assert_eq!(
            String::from("1001"),
            Solution::maximum_odd_binary_number(String::from("0101"))
        );
    }
}
