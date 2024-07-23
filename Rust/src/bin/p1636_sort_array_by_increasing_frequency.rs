// 1636. Sort Array by Increasing Frequency
// Difficulty: Easy

// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
// Return the sorted array.

// Example 1:
// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

// Example 2:
// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

// Example 3:
// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]

// Constraints:
//     1 <= nums.length <= 100
//     -100 <= nums[i] <= 100

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn frequency_sort(nums: Vec<i32>) -> Vec<i32> {
        use std::collections::{BTreeMap, BTreeSet};

        let mut map: BTreeMap<i32, usize> = BTreeMap::new();
        for &i in nums.iter() {
            map.entry(i).and_modify(|x| *x += 1).or_insert(1);
        }

        let mut freqs: BTreeMap<usize, BTreeSet<i32>> = BTreeMap::new();
        for &k in map.keys() {
            let v = *map.get(&k).unwrap();
            freqs
                .entry(v)
                .and_modify(|x| {
                    x.insert(k);
                })
                .or_insert(BTreeSet::from([k]));
        }

        let mut sorted: Vec<i32> = Vec::with_capacity(nums.len());
        for k in freqs.keys() {
            let v = freqs.get(k).unwrap();
            for &i in v.iter().rev() {
                sorted.append(&mut vec![i; *k]);
            }
        }

        sorted
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_num() {
        assert_eq!(
            Solution::frequency_sort(vec![1, 1, 2, 2, 2, 3]),
            vec![3, 1, 1, 2, 2, 2]
        );
        assert_eq!(
            Solution::frequency_sort(vec![2, 3, 1, 3, 2]),
            vec![1, 3, 3, 2, 2]
        );
        assert_eq!(
            Solution::frequency_sort(vec![-1, 1, -6, 4, 5, -6, 1, 4, 1]),
            vec![5, -1, 4, 4, -6, -6, 1, 1, 1]
        );
    }
}

fn main() {}
