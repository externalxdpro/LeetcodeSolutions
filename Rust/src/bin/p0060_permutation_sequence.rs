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
        let mut nums: Vec<char> = ('1'..=(char::from_digit(n as u32, 10).unwrap())).collect();

        for _ in 1..k {
            Self::next_permutation(&mut nums);
        }

        nums.into_iter().collect()
    }

    fn next_permutation(nums: &mut [char]) {
        let len = nums.len();
        let mut i = (len - 2) as i32;
        while i >= 0 {
            if nums[i as usize] < nums[i as usize + 1] {
                break;
            }
            i -= 1;
        }
        if i < 0 {
            nums.reverse();
            return;
        }

        let mut j = (len - 1) as i32;
        while j > i {
            if nums[j as usize] > nums[i as usize] {
                break;
            }
            j -= 1;
        }
        nums.swap(i as usize, j as usize);

        nums[(i as usize + 1)..].reverse();
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::get_permutation(3, 3), "213");
    assert_eq!(Solution::get_permutation(4, 9), "2314");
    assert_eq!(Solution::get_permutation(3, 1), "123");
}
