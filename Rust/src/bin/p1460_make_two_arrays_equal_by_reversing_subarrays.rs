// 1460. Make Two Arrays Equal by Reversing Subarrays
// Difficulty: Easy

// You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.
// Return true if you can make arr equal to target or false otherwise.

// Example 1:
// Input: target = [1,2,3,4], arr = [2,4,1,3]
// Output: true
// Explanation: You can follow the next steps to convert arr to target:
// 1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
// 2- Reverse subarray [4,2], arr becomes [1,2,4,3]
// 3- Reverse subarray [4,3], arr becomes [1,2,3,4]
// There are multiple ways to convert arr to target, this is not the only way to do so.

// Example 2:
// Input: target = [7], arr = [7]
// Output: true
// Explanation: arr is equal to target without any reverses.

// Example 3:
// Input: target = [3,7,9], arr = [3,7,11]
// Output: false
// Explanation: arr does not have value 9 and it can never be converted to target.

// Constraints:
//     target.length == arr.length
//     1 <= target.length <= 1000
//     1 <= target[i] <= 1000
//     1 <= arr[i] <= 1000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn can_be_equal(tar: Vec<i32>, arr: Vec<i32>) -> bool {
        use std::collections::HashMap;

        let mut tar_map: HashMap<i32, usize> = HashMap::new();
        let mut arr_map: HashMap<i32, usize> = HashMap::new();
        for i in 0..arr.len() {
            tar_map.entry(tar[i]).and_modify(|x| *x += 1).or_insert(1);
            arr_map.entry(arr[i]).and_modify(|x| *x += 1).or_insert(1);
        }

        tar_map == arr_map
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1460() {
        assert_eq!(
            Solution::can_be_equal(vec![1, 2, 3, 4], vec![2, 4, 1, 3]),
            true
        );
        assert_eq!(Solution::can_be_equal(vec![7], vec![7]), true);
        assert_eq!(Solution::can_be_equal(vec![3, 7, 9], vec![3, 7, 11]), false);
    }
}

fn main() {}
