// 60. Permutation Sequence
// Difficulty: Hard

// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//     "123"
//     "132"
//     "213"
//     "231"
//     "312"
//     "321"
// Given n and k, return the kth permutation sequence.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"

// Example 3:
// Input: n = 3, k = 1
// Output: "123"

// Constraints:
//     1 <= n <= 9
//     1 <= k <= n!

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn get_permutation(n: i32, k: i32) -> String {
        let factorials: [usize; 10] = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880];
        let (n, k) = (n as usize, k as usize);

        fn recurse(n: usize, k: usize, factorials: &[usize]) -> Vec<usize> {
            let mut nums = (1..=n).collect();
            if n == 1 || k == 0 {
                return nums;
            }
            let fac_n_1 = factorials[n - 1];
            let (si, pi) = (k / fac_n_1, k % fac_n_1);
            for i in (1..=si).rev() {
                nums.swap(i, i - 1);
            }
            let sub_arr = recurse(n - 1, pi, factorials);
            let clone = nums.clone();
            for i in 1..nums.len() {
                nums[i] = clone[sub_arr[i - 1]]
            }

            nums
        }

        recurse(n, k - 1, &factorials)
            .into_iter()
            .map(|x| char::from_digit(x as u32, 10).unwrap())
            .collect()
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::get_permutation(3, 3), "213");
    assert_eq!(Solution::get_permutation(4, 9), "2314");
    assert_eq!(Solution::get_permutation(3, 1), "123");
}
