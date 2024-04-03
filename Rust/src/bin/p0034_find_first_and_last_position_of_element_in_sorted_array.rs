// [34] Find First and Last Position of Element in Sorted Array
// Medium

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

// Constraints:
//     0 <= nums.length <= 10^5
//     -10^9 <= nums[i] <= 10^9
//     nums is a non-decreasing array.
//     -10^9 <= target <= 10^9

pub struct Solution {}

// submission codes start here

// Manually
impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        fn find(nums: &Vec<i32>, target: i32, find_first: bool) -> i32 {
            let (mut l, mut r) = (0, nums.len() as i32 - 1);
            let mut result = -1;
            while l <= r {
                let m = (r + l) / 2;

                if nums[m as usize] == target {
                    result = m;
                    if find_first {
                        r = m - 1
                    } else {
                        l = m + 1
                    };
                } else if nums[m as usize] > target {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            result
        }

        vec![find(&nums, target, true), find(&nums, target, false)]
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_34() {
        assert_eq!(
            Solution::search_range(vec![5, 7, 7, 8, 8, 10], 8),
            vec![3, 4]
        );
        assert_eq!(
            Solution::search_range(vec![5, 7, 7, 8, 8, 10], 6),
            vec![-1, -1]
        );
        assert_eq!(Solution::search_range(vec![], 0), vec![-1, -1]);
        assert_eq!(Solution::search_range(vec![1], 0), vec![-1, -1]);
    }
}

fn main() {}
