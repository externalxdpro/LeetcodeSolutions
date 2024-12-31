// 983. Minimum Cost For Tickets
// Difficulty: Medium

// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

//     a 1-day pass is sold for costs[0] dollars,
//     a 7-day pass is sold for costs[1] dollars, and
//     a 30-day pass is sold for costs[2] dollars.

// The passes allow that many days of consecutive travel.

//     For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

// Return the minimum number of dollars you need to travel every day in the given list of days.

// Example 1:

// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
// On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
// On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
// In total, you spent $11 and covered all the days of your travel.

// Example 2:

// Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
// Output: 17
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
// On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
// In total, you spent $17 and covered all the days of your travel.

// Constraints:

//     1 <= days.length <= 365
//     1 <= days[i] <= 365
//     days is in strictly increasing order.
//     costs.length == 3
//     1 <= costs[i] <= 1000

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn mincost_tickets(days: Vec<i32>, costs: Vec<i32>) -> i32 {
        Self::recurse(&days, &costs, 1, &mut vec![-1; 366])
    }

    fn recurse(days: &[i32], costs: &[i32], curr: i32, dp: &mut [i32]) -> i32 {
        if curr > *days.last().unwrap() {
            return 0;
        }
        if dp[curr as usize] != -1 {
            return dp[curr as usize];
        }
        if days.binary_search(&curr).is_err() {
            return Self::recurse(days, costs, curr + 1, dp);
        }
        let one = costs[0] + Self::recurse(days, costs, curr + 1, dp);
        let seven = costs[1] + Self::recurse(days, costs, curr + 7, dp);
        let thirty = costs[2] + Self::recurse(days, costs, curr + 30, dp);
        dp[curr as usize] = [one, seven, thirty].into_iter().min().unwrap();
        dp[curr as usize]
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::mincost_tickets(vec![1, 4, 6, 7, 8, 20], vec![2, 7, 15]),
        11
    );
    assert_eq!(
        Solution::mincost_tickets(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31], vec![2, 7, 15]),
        17
    );
    assert_eq!(
        Solution::mincost_tickets(
            vec![
                1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 24, 25, 27, 28,
                29, 30, 31, 34, 37, 38, 39, 41, 43, 44, 45, 47, 48, 49, 54, 57, 60, 62, 63, 66, 69,
                70, 72, 74, 76, 78, 80, 81, 82, 83, 84, 85, 88, 89, 91, 93, 94, 97, 99
            ],
            vec![9, 38, 134]
        ),
        423
    );
}
