// 2561. Rearranging Fruits
// Difficulty: Hard

// You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

// Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
// The cost of the swap is min(basket1[i],basket2[j]).
// Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

// Return the minimum cost to make both the baskets equal or -1 if impossible.

// Example 1:

// Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
// Output: 1
// Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
// Example 2:

// Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
// Output: -1
// Explanation: It can be shown that it is impossible to make both the baskets equal.

// Constraints:

// basket1.length == basket2.length
// 1 <= basket1.length <= 105
// 1 <= basket1[i],basket2[i] <= 109

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        use std::collections::HashMap;
        let min = basket1.iter().chain(basket2.iter()).min().copied().unwrap();
        let mut freq = HashMap::new();
        basket1.iter().for_each(|&x| {
            *freq.entry(x).or_insert(0) += 1;
        });
        basket2.iter().for_each(|&x| {
            *freq.entry(x).or_insert(0) -= 1;
        });

        let mut merged = vec![];
        for (&k, &v) in freq.iter() {
            if v % 2 == 1 {
                return -1;
            }
            merged.extend(vec![k; (v as i32).abs() as usize / 2].into_iter());
        }
        merged.sort_unstable();
        merged
            .iter()
            .take(merged.len() / 2)
            .fold(0, |acc, &x| acc + (x.min(2 * min)) as i64)
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::min_cost(vec![4, 2, 2, 2], vec![1, 4, 1, 2]), 1);
    assert_eq!(Solution::min_cost(vec![2, 3, 4, 1], vec![3, 2, 5, 1]), -1);
    assert_eq!(
        Solution::min_cost(vec![4, 4, 4, 4, 3], vec![5, 5, 5, 5, 3]),
        8
    );
}
