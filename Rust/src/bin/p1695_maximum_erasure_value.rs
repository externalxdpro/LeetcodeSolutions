// 1695. Maximum Erasure Value
// Difficulty: Medium

// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

// Example 1:

// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].
// Example 2:

// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8
// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, 0);
        let (mut sum, mut result) = (0, 0);
        let mut seen = vec![false; *nums.iter().max().unwrap() as usize + 1];
        while r < nums.len() && l <= r {
            match seen[nums[r] as usize] {
                true => {
                    result = result.max(sum);
                    while nums[l] != nums[r] {
                        seen[nums[l] as usize] = false;
                        sum -= nums[l];
                        l += 1;
                    }
                    sum -= nums[l];
                    seen[nums[l] as usize] = false;
                    l += 1;
                    result = result.max(sum);
                }
                false => {
                    seen[nums[r] as usize] = true;
                    sum += nums[r];
                    r += 1;
                }
            }
        }
        result = result.max(nums[l..r].into_iter().sum());
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::maximum_unique_subarray(vec![4, 2, 4, 5, 6]), 17);
    assert_eq!(
        Solution::maximum_unique_subarray(vec![5, 2, 1, 2, 5, 2, 1, 2, 5]),
        8
    );
}
