// 3170. Lexicographically Minimum String After Removing Stars
// Difficulty: Medium

// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

// While there is a '*', do the following operation:

//     Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.

// Return the

// resulting string after removing all '*' characters.

// Example 1:

// Input: s = "aaba*"

// Output: "aab"

// Explanation:

// We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

// Example 2:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no '*' in the string.

// Constraints:

//     1 <= s.length <= 105
//     s consists only of lowercase English letters and '*'.
//     The input is generated such that it is possible to delete all '*' characters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn clear_stars(s: String) -> String {
        let mut b: Vec<u8> = s.bytes().collect();
        let mut counts: Vec<Vec<usize>> = vec![vec![]; 26];
        for i in 0..s.len() {
            if b[i] != b'*' {
                counts[(b[i] - b'a') as usize].push(i);
            } else {
                for j in 0..26 {
                    if let Some(top) = counts[j].pop() {
                        b[top] = b'*';
                        break;
                    }
                }
            }
        }
        b.into_iter()
            .filter_map(|x| if x != b'*' { Some(x as char) } else { None })
            .collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::clear_stars("aaba*".to_string()),
        "aab".to_string()
    );
    assert_eq!(Solution::clear_stars("abc".to_string()), "abc".to_string());
    assert_eq!(Solution::clear_stars("de*".to_string()), "e".to_string());
}
