// 3480. Maximize Subarrays After Removing One Conflicting Pair
// Difficulty: Hard

// You are given an integer n which represents an array nums containing the numbers from 1 to n in order. Additionally, you are given a 2D array conflictingPairs, where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting pair.

// Remove exactly one element from conflictingPairs. Afterward, count the number of non-empty subarrays of nums which do not contain both a and b for any remaining conflicting pair [a, b].

// Return the maximum number of subarrays possible after removing exactly one conflicting pair.

// Example 1:

// Input: n = 4, conflictingPairs = [[2,3],[1,4]]

// Output: 9

// Explanation:

// Remove [2, 3] from conflictingPairs. Now, conflictingPairs = [[1, 4]].
// There are 9 subarrays in nums where [1, 4] do not appear together. They are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3] and [2, 3, 4].
// The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 9.
// Example 2:

// Input: n = 5, conflictingPairs = [[1,2],[2,5],[3,5]]

// Output: 12

// Explanation:

// Remove [1, 2] from conflictingPairs. Now, conflictingPairs = [[2, 5], [3, 5]].
// There are 12 subarrays in nums where [2, 5] and [3, 5] do not appear together.
// The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 12.

// Constraints:

// 2 <= n <= 105
// 1 <= conflictingPairs.length <= 2 * n
// conflictingPairs[i].length == 2
// 1 <= conflictingPairs[i][j] <= n
// conflictingPairs[i][0] != conflictingPairs[i][1]

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_subarrays(n: i32, mut conflicting_pairs: Vec<Vec<i32>>) -> i64 {
        let n = n as i64 + 1;
        conflicting_pairs.sort_unstable_by_key(|x| x[0].max(x[1]));
        conflicting_pairs.push(vec![n as i32, n as i32]);
        let (mut max_diff, mut max_l, mut rem) = (0, 0, 0);
        let (mut max_alt_l, mut alt_rem) = (0, 0);
        for x in conflicting_pairs {
            let (l, r) = (x[0].min(x[1]) as i64, x[0].max(x[1]) as i64);
            if l > max_l {
                max_diff = max_diff.max((max_alt_l - max_l) * (n - r) + rem - alt_rem);
                alt_rem = rem;
                max_alt_l = max_l;
                rem += (l - max_l) * (n - r);
                max_l = l;
            } else if l > max_alt_l {
                alt_rem += (l - max_alt_l) * (n - r);
                max_alt_l = l;
            }
        }
        ((n - 1) * n / 2 - rem + max_diff) as i64
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::max_subarrays(4, vec![vec![2, 3], vec![1, 4]]), 9);
    assert_eq!(
        Solution::max_subarrays(5, vec![vec![1, 2], vec![2, 5], vec![3, 5]]),
        12
    );
}
