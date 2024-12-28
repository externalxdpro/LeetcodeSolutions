// 689. Maximum Sum of 3 Non-Overlapping Subarrays
// Difficulty: Hard

// Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

// Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

// Example 1:

// Input: nums = [1,2,1,2,6,7,5,1], k = 2
// Output: [0,3,5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

// Example 2:

// Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
// Output: [0,2,4]

// Constraints:

//     1 <= nums.length <= 2 * 104
//     1 <= nums[i] < 216
//     1 <= k <= floor(nums.length / 3)

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_sum_of_three_subarrays(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let n = nums.len() - k + 1;

        let mut sums = vec![0; n];
        let mut sum = 0;
        for i in 0..k {
            sum += nums[i];
        }
        sums[0] = sum;
        for i in k..nums.len() {
            sum = sum - nums[i - k] + nums[i];
            sums[i - k + 1] = sum;
        }

        let mut memo = vec![vec![-1; 4]; n];
        let mut result = vec![];

        Self::recurse(&sums, k, 0, 3, &mut memo);
        Self::traverse(&sums, k, 0, 3, &mut memo, &mut result);
        result
    }

    fn recurse(sums: &Vec<i32>, k: usize, i: usize, rem: usize, memo: &mut Vec<Vec<i32>>) -> i32 {
        if rem == 0 {
            return 0;
        }
        if i >= sums.len() {
            return if rem > 0 { i32::MIN } else { 0 };
        }
        if memo[i][rem] != -1 {
            return memo[i][rem];
        }
        let keep = sums[i] + Self::recurse(sums, k, i + k, rem - 1, memo);
        let skip = Self::recurse(sums, k, i + 1, rem, memo);
        memo[i][rem] = keep.max(skip);
        memo[i][rem]
    }

    fn traverse(
        sums: &Vec<i32>,
        k: usize,
        i: usize,
        rem: usize,
        memo: &mut Vec<Vec<i32>>,
        result: &mut Vec<i32>,
    ) {
        if rem == 0 || i >= sums.len() {
            return;
        }

        let keep = sums[i] + Self::recurse(sums, k, i + k, rem - 1, memo);
        let skip = Self::recurse(sums, k, i + 1, rem, memo);

        if keep >= skip {
            result.push(i as i32);
            Self::traverse(sums, k, i + k, rem - 1, memo, result);
        } else {
            Self::traverse(sums, k, i + 1, rem, memo, result);
        }
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::max_sum_of_three_subarrays(vec![1, 2, 1, 2, 6, 7, 5, 1], 2),
        vec![0, 3, 5]
    );
    assert_eq!(
        Solution::max_sum_of_three_subarrays(vec![1, 2, 1, 2, 1, 2, 1, 2, 1], 2),
        vec![0, 2, 4]
    );
    assert_eq!(
        Solution::max_sum_of_three_subarrays(vec![7, 13, 20, 19, 19, 2, 10, 1, 1, 19], 3),
        vec![1, 4, 7]
    );
}
