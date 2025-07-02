// 3333. Find the Original Typed String II
// Difficulty: Hard

// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

// You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

// Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

// Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: word = "aabbccdd", k = 7

// Output: 5

// Explanation:

// The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".

// Example 2:

// Input: word = "aabbccdd", k = 8

// Output: 1

// Explanation:

// The only possible string is "aabbccdd".

// Example 3:

// Input: word = "aaabbb", k = 3

// Output: 8

// Constraints:

//     1 <= word.length <= 5 * 105
//     word consists only of lowercase English letters.
//     1 <= k <= 2000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn possible_string_count(word: String, k: i32) -> i32 {
        use itertools::Itertools;
        const MOD: usize = 1e9 as usize + 7;
        let k = k as usize;

        let groups = word
            .chars()
            .chunk_by(|&x| x)
            .into_iter()
            .map(|(_, g)| g.count())
            .collect_vec();

        let total = groups.iter().fold(1, |acc, &x| acc * x % MOD as usize);

        if k < groups.len() {
            return total as i32;
        }

        let mut memo = vec![0; k];
        memo[0] = 1;
        for &num in groups.iter() {
            let mut curr = vec![0; k];
            let mut sum = 0;
            for s in 0..k {
                if s > 0 {
                    sum = (sum + memo[s - 1]) % MOD;
                }
                if s > num {
                    sum = (sum - memo[s - num - 1] + MOD) % MOD;
                }
                curr[s] = sum;
            }
            memo = curr;
        }

        let mut invalid = 0;
        for i in groups.len()..k {
            invalid = (invalid + memo[i]) % MOD;
        }

        ((total - invalid + MOD) % MOD) as i32
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::possible_string_count("aabbccdd".to_string(), 7),
        5
    );
    assert_eq!(
        Solution::possible_string_count("aabbccdd".to_string(), 8),
        1
    );
    assert_eq!(Solution::possible_string_count("aaabbb".to_string(), 3), 8);
}
