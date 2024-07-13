// 2657. Find the Prefix Common Array of Two Arrays
// Difficulty: Medium

// You are given two 0-indexed integer permutations A and B of length n.
// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
// Return the prefix common array of A and B.
// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

// Example 1:
// Input: A = [1,3,2,4], B = [3,1,2,4]
// Output: [0,2,3,4]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
// At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

// Example 2:
// Input: A = [2,3,1], B = [3,1,2]
// Output: [0,1,3]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: only 3 is common in A and B, so C[1] = 1.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.

// Constraints:
//     1 <= A.length == B.length == n <= 50
//     1 <= A[i], B[i] <= n
//     It is guaranteed that A and B are both a permutation of n integers.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        use std::collections::HashSet;

        let mut a_set = HashSet::<i32>::new();
        let mut b_set = HashSet::<i32>::new();
        let mut result = vec![0; a.len()];

        for i in 0..a.len() {
            a_set.insert(a[i]);
            b_set.insert(b[i]);
            result[i] = a_set.intersection(&b_set).count() as i32;
        }

        result
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2657() {
        assert_eq!(
            Solution::find_the_prefix_common_array(vec![1, 3, 2, 4], vec![3, 1, 2, 4]),
            vec![0, 2, 3, 4]
        );
        assert_eq!(
            Solution::find_the_prefix_common_array(vec![2, 3, 1], vec![3, 1, 2]),
            vec![0, 1, 3]
        );
    }
}

fn main() {}
