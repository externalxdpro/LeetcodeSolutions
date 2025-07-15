// 3136. Valid Word
// Difficulty: Easy

// A word is considered valid if:

//     It contains a minimum of 3 characters.
//     It contains only digits (0-9), and English letters (uppercase and lowercase).
//     It includes at least one vowel.
//     It includes at least one consonant.

// You are given a string word.

// Return true if word is valid, otherwise, return false.

// Notes:

//     'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
//     A consonant is an English letter that is not a vowel.

// Example 1:

// Input: word = "234Adas"

// Output: true

// Explanation:

// This word satisfies the conditions.

// Example 2:

// Input: word = "b3"

// Output: false

// Explanation:

// The length of this word is fewer than 3, and does not have a vowel.

// Example 3:

// Input: word = "a3$e"

// Output: false

// Explanation:

// This word contains a '$' character and does not have a consonant.

// Constraints:

//     1 <= word.length <= 20
//     word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }

        const VOWELS: [char; 5] = ['a', 'e', 'i', 'o', 'u'];
        let (mut vowel, mut cons) = (false, false);
        for c in word.to_ascii_lowercase().chars() {
            if !c.is_alphanumeric() {
                return false;
            }
            if c.is_alphabetic() {
                if VOWELS.contains(&c) {
                    vowel = true;
                } else {
                    cons = true;
                }
            }
        }
        vowel && cons
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::is_valid("234Adas".to_string()), true);
    assert_eq!(Solution::is_valid("b3".to_string()), false);
    assert_eq!(Solution::is_valid("a3$e".to_string()), false);
}
