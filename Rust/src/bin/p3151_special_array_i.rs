// 3151. Special Array I
// Difficulty: Easy

// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

// Example 1:

// Input: nums = [1]

// Output: true

// Explanation:

// There is only one element. So the answer is true.

// Example 2:

// Input: nums = [2,1,4]

// Output: true

// Explanation:

// There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

// Example 3:

// Input: nums = [4,3,1,6]

// Output: false

// Explanation:

// nums[1] and nums[2] are both odd. So the answer is false.

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i] <= 100

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn is_array_special(nums: Vec<i32>) -> bool {
        nums.windows(2).into_iter().all(|x| x[0] % 2 != x[1] % 2)
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::is_array_special(vec![1]), true);
    assert_eq!(Solution::is_array_special(vec![2, 1, 4]), true);
    assert_eq!(Solution::is_array_special(vec![4, 3, 1, 6]), false);
}
