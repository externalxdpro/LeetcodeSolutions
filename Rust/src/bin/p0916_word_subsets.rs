// 916. Word Subsets
// Difficulty: Medium

// You are given two string arrays words1 and words2.

// A string b is a subset of string a if every letter in b occurs in a including multiplicity.

//     For example, "wrr" is a subset of "warrior" but is not a subset of "world".

// A string a from words1 is universal if for every string b in words2, b is a subset of a.

// Return an array of all the universal strings in words1. You may return the answer in any order.

// Example 1:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]

// Example 2:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
// Output: ["apple","google","leetcode"]

// Constraints:

//     1 <= words1.length, words2.length <= 104
//     1 <= words1[i].length, words2[i].length <= 10
//     words1[i] and words2[i] consist only of lowercase English letters.
//     All the strings of words1 are unique.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn word_subsets(words1: Vec<String>, words2: Vec<String>) -> Vec<String> {
        use std::iter::zip;
        let words2 = words2.into_iter().fold(vec![0; 26], |curr, x| {
            let count = x.chars().fold([0; 26], |mut curr, c| {
                curr[c as usize - 'a' as usize] += 1;
                curr
            });
            zip(count, curr).map(|(x, y)| x.max(y)).collect()
        });
        words1
            .into_iter()
            .filter(|x| {
                let count = x.chars().fold([0; 26], |mut curr, c| {
                    curr[c as usize - 'a' as usize] += 1;
                    curr
                });
                zip(count, &words2).into_iter().all(|(x, &y)| x >= y)
            })
            .collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::word_subsets(
            vec![
                "amazon".to_string(),
                "apple".to_string(),
                "facebook".to_string(),
                "google".to_string(),
                "leetcode".to_string()
            ],
            vec!["e".to_string(), "o".to_string()]
        ),
        vec![
            "facebook".to_string(),
            "google".to_string(),
            "leetcode".to_string()
        ]
    );
    assert_eq!(
        Solution::word_subsets(
            vec![
                "amazon".to_string(),
                "apple".to_string(),
                "facebook".to_string(),
                "google".to_string(),
                "leetcode".to_string()
            ],
            vec!["l".to_string(), "e".to_string()]
        ),
        vec![
            "apple".to_string(),
            "google".to_string(),
            "leetcode".to_string()
        ]
    );
    assert_eq!(
        Solution::word_subsets(
            vec![
                "amazon".to_string(),
                "apple".to_string(),
                "facebook".to_string(),
                "google".to_string(),
                "leetcode".to_string()
            ],
            vec!["lo".to_string(), "eo".to_string()]
        ),
        vec!["google".to_string(), "leetcode".to_string()]
    );
}
