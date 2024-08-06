// 3016. Minimum Number of Pushes to Type Word II
// Difficulty: Medium

// You are given a string word containing lowercase English letters.
// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.
// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

// Example 1:
// Input: word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.

// Example 2:
// Input: word = "xyzxyzxyzxyz"
// Output: 12
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "x" -> one push on key 2
// "y" -> one push on key 3
// "z" -> one push on key 4
// Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
// It can be shown that no other mapping can provide a lower cost.
// Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.

// Example 3:
// Input: word = "aabbccddeeffgghhiiiiii"
// Output: 24
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// "f" -> one push on key 7
// "g" -> one push on key 8
// "h" -> two pushes on key 9
// "i" -> one push on key 9
// Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
// It can be shown that no other mapping can provide a lower cost.

// Constraints:
//     1 <= word.length <= 10^5
//     word consists of lowercase English letters.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        use std::collections::{BTreeMap, HashSet};
        let mut freq: BTreeMap<char, usize> = BTreeMap::new();
        for c in word.chars() {
            freq.entry(c).and_modify(|x| *x += 1).or_insert(1);
        }

        let mut counts: BTreeMap<usize, HashSet<char>> = BTreeMap::new();
        for k in freq.keys() {
            let v = freq[k];
            counts
                .entry(v)
                .and_modify(|x| {
                    x.insert(*k);
                })
                .or_insert(HashSet::from([*k]));
        }

        let mut presses: BTreeMap<char, usize> = BTreeMap::new();
        let (mut i, mut count) = (0, 1);
        for k in counts.keys().rev() {
            let v = &counts[k];
            for &c in v {
                presses.insert(c, count);
                i += 1;
                if i == 8 {
                    i = 0;
                    count += 1;
                }
            }
        }

        let mut result = 0;
        for c in word.chars() {
            result += presses[&c];
        }

        result as i32
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_3016() {
        assert_eq!(Solution::minimum_pushes("abcde".to_string()), 5);
        assert_eq!(Solution::minimum_pushes("xyzxyzxyzxyz".to_string()), 12);
        assert_eq!(
            Solution::minimum_pushes("aabbccddeeffgghhiiiiii".to_string()),
            24
        );
        assert_eq!(
            Solution::minimum_pushes("abzaqsqcyrbzsrvamylmyxdjl".to_string()),
            32
        );
    }
}

fn main() {}
