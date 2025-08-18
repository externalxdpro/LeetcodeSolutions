// 679. 24 Game
// Difficulty: Hard

// You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

// You are restricted with the following rules:

// The division operator '/' represents real division, not integer division.
// For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
// Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
// For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
// You cannot concatenate numbers together
// For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
// Return true if you can get such expression that evaluates to 24, and false otherwise.

// Example 1:

// Input: cards = [4,1,8,7]
// Output: true
// Explanation: (8-4) * (7-1) = 24
// Example 2:

// Input: cards = [1,2,1,2]
// Output: false

// Constraints:

// cards.length == 4
// 1 <= cards[i] <= 9

pub struct Solution {}

// submission codes start here

const EPSILON: f64 = 1e-6;

impl Solution {
    pub fn judge_point24(cards: Vec<i32>) -> bool {
        let cards = cards.into_iter().map(|x| x as f64).collect();
        Self::recurse(&cards)
    }

    fn recurse(cards: &Vec<f64>) -> bool {
        if cards.len() == 1 {
            return (cards[0] - 24.0).abs() < EPSILON;
        }
        for i in 0..cards.len() {
            for j in (i + 1)..cards.len() {
                let mut next: Vec<f64> = cards
                    .iter()
                    .enumerate()
                    .filter(|&(k, _)| k != i && k != j)
                    .map(|(_, x)| *x)
                    .collect();
                for val in Self::compute(cards[i], cards[j]) {
                    next.push(val);
                    if Self::recurse(&next) {
                        return true;
                    }
                    next.pop();
                }
            }
        }
        false
    }

    fn compute(a: f64, b: f64) -> Vec<f64> {
        let mut result = vec![a + b, a - b, b - a, a * b];
        if b.abs() > EPSILON {
            result.push(a / b);
        }
        if a.abs() > EPSILON {
            result.push(b / a);
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::judge_point24(vec![4, 1, 8, 7]), true);
    assert_eq!(Solution::judge_point24(vec![1, 2, 1, 2]), false);
    assert_eq!(Solution::judge_point24(vec![3, 3, 8, 8]), true);
}
