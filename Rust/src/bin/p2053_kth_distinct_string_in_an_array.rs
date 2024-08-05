// 2053. Kth Distinct String in an Array
// Difficulty: Easy

// A distinct string is a string that is present only once in an array.
// Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
// Note that the strings are considered in the order in which they appear in the array.

// Example 1:
// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
// Explanation:
// The only distinct strings in arr are "d" and "a".
// "d" appears 1st, so it is the 1st distinct string.
// "a" appears 2nd, so it is the 2nd distinct string.
// Since k == 2, "a" is returned.

// Example 2:
// Input: arr = ["aaa","aa","a"], k = 1
// Output: "aaa"
// Explanation:
// All strings in arr are distinct, so the 1st string "aaa" is returned.

// Example 3:
// Input: arr = ["a","b","a"], k = 3
// Output: ""
// Explanation:
// The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".

// Constraints:
//     1 <= k <= arr.length <= 1000
//     1 <= arr[i].length <= 5
//     arr[i] consists of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn kth_distinct(arr: Vec<String>, k: i32) -> String {
        use std::collections::HashMap;
        let mut map: HashMap<String, usize> = HashMap::new();
        for i in arr.clone() {
            map.entry(i).and_modify(|x| *x += 1).or_insert(1);
        }
        arr.into_iter()
            .filter(|x| map[x] == 1)
            .nth((k - 1) as usize)
            .unwrap_or_else(|| "".to_string())
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2053() {
        assert_eq!(
            Solution::kth_distinct(
                vec![
                    "d".into(),
                    "b".into(),
                    "c".into(),
                    "b".into(),
                    "c".into(),
                    "a".into()
                ],
                2
            ),
            "a"
        );
        assert_eq!(
            Solution::kth_distinct(vec!["aaa".into(), "aa".into(), "a".into(),], 1),
            "aaa"
        );
        assert_eq!(
            Solution::kth_distinct(vec!["a".into(), "b".into(), "a".into(),], 3),
            ""
        );
    }
}

fn main() {}
