// 1639. Number of Ways to Form a Target String Given a Dictionary
// Difficulty: Hard

// You are given a list of strings of the same length words and a string target.

// Your task is to form target using the given words under the following rules:

//     target should be formed from left to right.
//     To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
//     Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
//     Repeat the process until you form the string target.

// Notice that you can use multiple characters from the same string in words provided the conditions above are met.

// Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

// Example 1:

// Input: words = ["acca","bbbb","caca"], target = "aba"
// Output: 6
// Explanation: There are 6 ways to form target.
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
// "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
// "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
// "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

// Example 2:

// Input: words = ["abba","baab"], target = "bab"
// Output: 4
// Explanation: There are 4 ways to form target.
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
// "bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
// "bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
// "bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

// Constraints:

//     1 <= words.length <= 1000
//     1 <= words[i].length <= 1000
//     All strings in words have the same length.
//     1 <= target.length <= 1000
//     words[i] and target contain only lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn num_ways(words: Vec<String>, target: String) -> i32 {
        let words: Vec<Vec<char>> = words.into_iter().map(|x| x.chars().collect()).collect();
        let target: Vec<char> = target.chars().collect();
        let mut memo = vec![vec![-1; target.len()]; words[0].len()];
        let mut freq = vec![vec![0; 26]; words[0].len()];
        for i in 0..words.len() {
            for j in 0..words[0].len() {
                freq[j][words[i][j] as usize - 'a' as usize] += 1;
            }
        }
        Self::recurse(&words, &target, 0, 0, &mut memo, &mut freq)
    }

    fn recurse(
        words: &Vec<Vec<char>>,
        target: &Vec<char>,
        w_i: usize,
        t_i: usize,
        memo: &mut Vec<Vec<i32>>,
        freq: &mut Vec<Vec<i32>>,
    ) -> i32 {
        if t_i == target.len() {
            return 1;
        }
        if w_i == words[0].len() || words[0].len() - w_i < target.len() - t_i {
            return 0;
        }
        if memo[w_i][t_i] != -1 {
            return memo[w_i][t_i];
        }

        let mut result: i64 = 0;
        result += Self::recurse(words, target, w_i + 1, t_i, memo, freq) as i64;
        result += freq[w_i][target[t_i] as usize - 'a' as usize] as i64
            * Self::recurse(words, target, w_i + 1, t_i + 1, memo, freq) as i64;

        memo[w_i][t_i] = (result % 1000000007) as i32;
        memo[w_i][t_i]
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::num_ways(
            vec!["acca".to_string(), "bbbb".to_string(), "caca".to_string()],
            "aba".to_string()
        ),
        6
    );
    assert_eq!(
        Solution::num_ways(
            vec!["abba".to_string(), "baab".to_string()],
            "bab".to_string()
        ),
        4
    );
}
