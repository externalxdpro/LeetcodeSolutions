// [22] Generate Parentheses
// Difficulty: Medium

// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

// Constraints:
//     1 <= n <= 8

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        Self::dp(n, 0, "".to_string()).into_iter().collect()
    }

    fn dp(left: i32, open: i32, curr: String) -> std::collections::HashSet<String> {
        use std::collections::HashSet;
        let mut result = HashSet::new();
        if left == 0 && open == 0 {
            result.insert(curr.clone());
        }
        if left > 0 {
            result.extend(Self::dp(left - 1, open + 1, format!("{}(", curr.clone())));
        }
        if open > 0 {
            result.extend(Self::dp(left, open - 1, format!("{})", curr.clone())));
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashSet;

    #[test]
    fn test_22() {
        assert_eq!(
            Solution::generate_parenthesis(3)
                .iter()
                .map(|x| x as &str)
                .collect::<HashSet<&str>>(),
            vec!["(()())", "((()))", "()()()", "()(())", "(())()"]
                .into_iter()
                .collect::<HashSet<&str>>(),
        );
        assert_eq!(Solution::generate_parenthesis(1), vec!["()"]);
    }
}

fn main() {}
