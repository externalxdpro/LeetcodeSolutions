// 2182. Construct String With Repeat Limit
// Difficulty: Medium

// You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

// Return the lexicographically largest repeatLimitedString possible.

// A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

// Example 1:

// Input: s = "cczazcc", repeatLimit = 3
// Output: "zzcccac"
// Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
// The letter 'a' appears at most 1 time in a row.
// The letter 'c' appears at most 3 times in a row.
// The letter 'z' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
// Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.

// Example 2:

// Input: s = "aababab", repeatLimit = 2
// Output: "bbabaa"
// Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa".
// The letter 'a' appears at most 2 times in a row.
// The letter 'b' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
// Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.

// Constraints:

//     1 <= repeatLimit <= s.length <= 105
//     s consists of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn repeat_limited_string(s: String, repeat_limit: i32) -> String {
        use std::collections::{BinaryHeap, HashMap};

        let mut freq = HashMap::<char, i32>::new();
        let mut heap = BinaryHeap::<char>::new();
        for c in s.chars() {
            freq.entry(c).and_modify(|x| *x += 1).or_insert(1);
        }
        for (&c, _) in freq.iter() {
            heap.push(c);
        }

        let mut result = String::new();
        while let Some(c) = heap.pop() {
            let v = freq[&c].min(repeat_limit);
            for _ in 0..v {
                result.push(c);
            }
            freq.entry(c).and_modify(|x| *x -= v);

            if freq[&c] > 0 && !heap.is_empty() {
                let next = heap.pop().unwrap();
                result.push(next);
                freq.entry(next).and_modify(|x| *x -= 1);

                if freq[&next] > 0 {
                    heap.push(next);
                }
                heap.push(c);
            }
        }

        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::repeat_limited_string("cczazcc".to_string(), 3),
        "zzcccac".to_string()
    );
    assert_eq!(
        Solution::repeat_limited_string("aababab".to_string(), 2),
        "bbabaa".to_string()
    );
}
