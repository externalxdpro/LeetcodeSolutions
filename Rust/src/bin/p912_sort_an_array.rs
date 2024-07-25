// 912. Sort an Array
// Difficulty: Medium

// Given an array of integers nums, sort the array in ascending order and return it.
// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.

// Constraints:
//     1 <= nums.length <= 5 * 10^4
//     -5 * 10^4 <= nums[i] <= 5 * 10^4

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        if nums.len() < 2 {
            return nums;
        }
        let l = Self::sort_array(nums[..nums.len() / 2].to_vec());
        let r = Self::sort_array(nums[nums.len() / 2..].to_vec());
        let mut result = vec![];
        let (mut li, mut ri) = (0, 0);

        loop {
            if li >= l.len() && ri >= r.len() {
                return result;
            } else if li >= l.len() {
                result.push(r[ri]);
                ri += 1;
            } else if ri >= r.len() {
                result.push(l[li]);
                li += 1;
            } else if l[li] < r[ri] {
                result.push(l[li]);
                li += 1;
            } else {
                result.push(r[ri]);
                ri += 1;
            }
        }
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_912() {
        assert_eq!(Solution::sort_array(vec![5, 2, 3, 1]), vec![1, 2, 3, 5]);
        assert_eq!(
            Solution::sort_array(vec![5, 1, 1, 2, 0, 0]),
            vec![0, 0, 1, 1, 2, 5]
        );
    }
}

fn main() {}
