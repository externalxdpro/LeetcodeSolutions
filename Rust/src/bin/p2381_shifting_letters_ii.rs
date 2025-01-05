// 2381. Shifting Letters II
// Difficulty: Medium

// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

// Return the final string after all such shifts to s are applied.

// Example 1:

// Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
// Output: "ace"
// Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
// Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
// Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

// Example 2:

// Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
// Output: "catz"
// Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
// Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".

// Constraints:

//     1 <= s.length, shifts.length <= 5 * 104
//     shifts[i].length == 3
//     0 <= starti <= endi < s.length
//     0 <= directioni <= 1
//     s consists of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
        let s: Vec<char> = s.chars().collect();
        let mut diff: Vec<i32> = vec![0; s.len()];
        for shift in shifts {
            if shift[2] == 1 {
                diff[shift[0] as usize] += 1;
                if shift[1] as usize + 1 < s.len() {
                    diff[shift[1] as usize + 1] -= 1;
                }
            } else {
                diff[shift[0] as usize] -= 1;
                if shift[1] as usize + 1 < s.len() {
                    diff[shift[1] as usize + 1] += 1;
                }
            }
        }

        let mut result = vec![' '; s.len()];
        let mut num_shifts = 0;
        for i in 0..s.len() {
            num_shifts = (num_shifts + diff[i]) % 26;
            num_shifts += if num_shifts < 0 { 26 } else { 0 };
            result[i] = (b'a' + (s[i] as u8 - b'a' + num_shifts as u8) % 26) as char;
        }

        result.into_iter().collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::shifting_letters(
            "abc".to_string(),
            vec![vec![0, 1, 0], vec![1, 2, 1], vec![0, 2, 1]]
        ),
        "ace".to_string()
    );
    assert_eq!(
        Solution::shifting_letters("dztz".to_string(), vec![vec![0, 0, 0], vec![1, 1, 1]]),
        "catz".to_string()
    );
}
