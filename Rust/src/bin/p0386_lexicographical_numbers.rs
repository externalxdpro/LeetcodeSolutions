// 386. Lexicographical Numbers
// Difficulty: Medium

// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space.

// Example 1:

// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

// Example 2:

// Input: n = 2
// Output: [1,2]

// Constraints:

//     1 <= n <= 5 * 104

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut result: Vec<i32> = vec![];
        for i in 1..=9 {
            Self::recurse(i, n, &mut result);
        }
        result
    }

    fn recurse(curr: i32, lim: i32, result: &mut Vec<i32>) {
        if curr > lim {
            return;
        }
        result.push(curr);
        for i in 0..=9 {
            let num = curr * 10 + i;
            Self::recurse(num, lim, result);
        }
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::lexical_order(13),
        (vec![1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9])
    );
    assert_eq!(Solution::lexical_order(2), (vec![1, 2]));
}
