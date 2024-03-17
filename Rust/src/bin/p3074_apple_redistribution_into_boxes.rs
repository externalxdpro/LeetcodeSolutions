// [3074] Apple Redistribution into Boxes
// Difficulty: Easy

// You are given an array apple of size n and an array capacity of size m.
// There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
// Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
// Note that, apples from the same pack can be distributed into different boxes.

// Example 1:
// Input: apple = [1,3,2], capacity = [4,3,1,5,2]
// Output: 2
// Explanation: We will use boxes with capacities 4 and 5.
// It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.

// Example 2:
// Input: apple = [5,5,5], capacity = [2,4,2,7]
// Output: 4
// Explanation: We will need to use all the boxes.

// Constraints:
//     1 <= n == apple.length <= 50
//     1 <= m == capacity.length <= 50
//     1 <= apple[i], capacity[i] <= 50
//     The input is generated such that it's possible to redistribute packs of apples into boxes.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, mut capacity: Vec<i32>) -> i32 {
        capacity.sort_by(|a, b| b.cmp(a));
        let mut result = -1;
        capacity
            .into_iter()
            .enumerate()
            .fold(apple.into_iter().sum::<i32>(), |mut acc, (i, v)| {
                acc -= if acc > 0 { v } else { 0 };
                result = if acc <= 0 && result == -1 {
                    (i + 1) as i32
                } else {
                    result
                };
                acc
            });
        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_3074() {
        assert_eq!(
            Solution::minimum_boxes(vec![1, 3, 2], vec![4, 3, 1, 5, 2]),
            2
        );
        assert_eq!(Solution::minimum_boxes(vec![5, 5, 5], vec![2, 4, 2, 7]), 4);
        assert_eq!(
            Solution::minimum_boxes(vec![9, 8, 8, 2, 3, 1, 6], vec![10, 1, 4, 10, 8, 5]),
            5
        );
    }
}

fn main() {}
