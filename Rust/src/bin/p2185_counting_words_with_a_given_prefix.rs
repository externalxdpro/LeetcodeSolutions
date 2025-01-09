// 2185. Counting Words With a Given Prefix
// Difficulty: Easy

// You are given an array of strings words and a string pref.

// Return the number of strings in words that contain pref as a prefix.

// A prefix of a string s is any leading contiguous substring of s.

// Example 1:

// Input: words = ["pay","attention","practice","attend"], pref = "at"
// Output: 2
// Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

// Example 2:

// Input: words = ["leetcode","win","loops","success"], pref = "code"
// Output: 0
// Explanation: There are no strings that contain "code" as a prefix.

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length, pref.length <= 100
//     words[i] and pref consist of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
        words.into_iter().fold(0, |sum, x| {
            sum + if x.starts_with(pref.as_str()) { 1 } else { 0 }
        })
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::prefix_count(
            vec![
                "pay".to_string(),
                "attention".to_string(),
                "practice".to_string(),
                "attend".to_string()
            ],
            "at".to_string()
        ),
        2
    );
    assert_eq!(
        Solution::prefix_count(
            vec![
                "leetcode".to_string(),
                "win".to_string(),
                "loops".to_string(),
                "success".to_string()
            ],
            "code".to_string()
        ),
        0
    );
}
