// 904. Fruit Into Baskets
// Difficulty: Medium

// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

// Example 1:

// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
// Example 3:

// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].

// Constraints:

// 1 <= fruits.length <= 105
// 0 <= fruits[i] < fruits.length

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut counts: HashMap<i32, i32> = HashMap::new();
        let mut l = 0;
        let (mut b1, mut b2) = (None, None);
        let mut result = 0;

        for r in 0..fruits.len() {
            if b1.is_none_or(|x| x == fruits[r]) {
                b1 = Some(fruits[r]);
                *counts.entry(fruits[r]).or_default() += 1;
            } else if b2.is_none_or(|x| x == fruits[r]) {
                b2 = Some(fruits[r]);
                *counts.entry(fruits[r]).or_default() += 1;
            } else {
                while counts.len() > 1 {
                    counts.entry(fruits[l]).and_modify(|c| *c -= 1);
                    if let Some(&0) = counts.get(&fruits[l]) {
                        if b1.is_some_and(|x| x == fruits[l]) {
                            b1 = None;
                        }
                        if b2.is_some_and(|x| x == fruits[l]) {
                            b2 = None;
                        }
                        counts.remove(&fruits[l]);
                    }
                    l += 1;
                }

                if b1.is_none() {
                    b1 = Some(fruits[r]);
                } else {
                    b2 = Some(fruits[r]);
                }
                *counts.entry(fruits[r]).or_default() += 1;
            }

            result = result.max((r - l + 1) as i32);
        }

        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::total_fruit(vec![1, 2, 1]), 3);
    assert_eq!(Solution::total_fruit(vec![0, 1, 2, 2]), 3);
    assert_eq!(Solution::total_fruit(vec![1, 2, 3, 2, 2]), 4);
}
