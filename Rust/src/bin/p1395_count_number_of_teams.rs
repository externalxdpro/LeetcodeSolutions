// 1395. Count Number of Teams
// Difficulty: Medium

// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
// You have to form a team of 3 soldiers amongst them under the following rules:
//     Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
//     A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

// Example 1:
// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1).

// Example 2:
// Input: rating = [2,1,3]
// Output: 0
// Explanation: We can't form any team given the conditions.

// Example 3:
// Input: rating = [1,2,3,4]
// Output: 4

// Constraints:
//     n == rating.length
//     3 <= n <= 1000
//     1 <= rating[i] <= 10^5
//     All the integers in rating are unique.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn num_teams(rating: Vec<i32>) -> i32 {
        let mut ans = 0;
        for i in 1..(rating.len() - 1) {
            let (mut l_gt, mut l_lt) = (0, 0);
            let (mut r_gt, mut r_lt) = (0, 0);
            for j in 0..i {
                if rating[j] < rating[i] {
                    l_lt += 1;
                } else {
                    l_gt += 1;
                }
            }
            for j in (i + 1)..rating.len() {
                if rating[i] > rating[j] {
                    r_lt += 1;
                } else {
                    r_gt += 1;
                }
            }
            ans += l_gt * r_lt + l_lt * r_gt;
        }

        ans
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_73() {
        assert_eq!(Solution::num_teams(vec![2, 5, 3, 4, 1]), 3);
        assert_eq!(Solution::num_teams(vec![2, 1, 3]), 0);
        assert_eq!(Solution::num_teams(vec![1, 2, 3, 4]), 4);
    }
}

fn main() {}
