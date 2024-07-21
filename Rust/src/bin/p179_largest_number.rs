// 179. Largest Number
// Difficulty: Medium

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.

// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

// Constraints:
//     1 <= nums.length <= 100
//     0 <= nums[i] <= 10^9

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut strings: Vec<String> = nums.into_iter().map(|x| x.to_string()).collect();
        strings.sort_unstable_by(|a, b| format!("{}{}", b, a).cmp(&format!("{}{}", a, b)));

        let res = strings.join("");
        if res.chars().next() == Some('0') {
            "0".to_string()
        } else {
            res
        }
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_179() {
        assert_eq!(Solution::largest_number(vec![10, 2]), "210");
        assert_eq!(Solution::largest_number(vec![3, 30, 34, 5, 9]), "9534330");
        assert_eq!(Solution::largest_number(vec![0, 0, 0]), "0");
        assert_eq!(
            Solution::largest_number(vec![
                3297, 7683, 8930, 2412, 1041, 6045, 7020, 9553, 1221, 1122
            ]),
            "9553893076837020604532972412122111221041"
        );
    }
}

fn main() {}
