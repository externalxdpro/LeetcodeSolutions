// 1408. String Matching in an Array
// Difficulty: Easy

// Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

// A substring is a contiguous sequence of characters within a string

// Example 1:

// Input: words = ["mass","as","hero","superhero"]
// Output: ["as","hero"]
// Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
// ["hero","as"] is also a valid answer.

// Example 2:

// Input: words = ["leetcode","et","code"]
// Output: ["et","code"]
// Explanation: "et", "code" are substring of "leetcode".

// Example 3:

// Input: words = ["blue","green","bu"]
// Output: []
// Explanation: No string of words is substring of another string.

// Constraints:

//     1 <= words.length <= 100
//     1 <= words[i].length <= 30
//     words[i] contains only lowercase English letters.
//     All the strings of words are unique.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        use std::collections::HashSet;
        let mut result: HashSet<String> = HashSet::new();
        for i in 0..words.len() {
            for j in (i + 1)..words.len() {
                let (word1, word2) = (&words[i], &words[j]);
                if word1.len() < word2.len() && word2.contains(word1) {
                    result.insert(word1.clone());
                } else if word2.len() < word1.len() && word1.contains(word2) {
                    result.insert(word2.clone());
                }
            }
        }
        result.into_iter().collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::string_matching(vec![
            "mass".to_string(),
            "as".to_string(),
            "hero".to_string(),
            "superhero".to_string()
        ]),
        vec!["as".to_string(), "hero".to_string()]
    );
    assert_eq!(
        Solution::string_matching(vec![
            "leetcode".to_string(),
            "et".to_string(),
            "code".to_string()
        ]),
        vec!["et".to_string(), "code".to_string()]
    );
    assert_eq!(
        Solution::string_matching(vec![
            "blue".to_string(),
            "green".to_string(),
            "bu".to_string()
        ]),
        vec!["".to_string(); 0]
    );
}
