// 1751. Maximum Number of Events That Can Be Attended II
// Difficulty: Hard

// You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

// You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

// Return the maximum sum of values that you can receive by attending events.

// Example 1:

// Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
// Output: 7
// Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

// Example 2:

// Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
// Output: 10
// Explanation: Choose event 2 for a total value of 10.
// Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.

// Example 3:

// Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
// Output: 9
// Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.

// Constraints:

//     1 <= k <= events.length
//     1 <= k * events.length <= 106
//     1 <= startDayi <= endDayi <= 109
//     1 <= valuei <= 106

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_value(mut events: Vec<Vec<i32>>, k: i32) -> i32 {
        use itertools::Itertools;
        events.sort_unstable();
        let starts = events.iter().map(|x| x[0]).collect_vec();
        let mut nexts = vec![0; events.len()];
        for i in 0..events.len() {
            nexts[i] = starts.partition_point(|&x| x <= events[i][1]);
        }
        let mut prev = vec![0; events.len() + 1];
        for i in (0..events.len()).rev() {
            prev[i] = prev[i + 1].max(events[i][2]);
        }

        let mut result = prev[0];
        for _ in 2..=k {
            let mut curr = vec![0; events.len() + 1];
            for i in (0..events.len()).rev() {
                let mut take = events[i][2];
                if nexts[i] <= events.len() {
                    take += prev[nexts[i]];
                }
                curr[i] = curr[i + 1].max(take);
            }
            result = result.max(curr[0]);
            prev.swap_with_slice(curr.as_mut_slice());
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::max_value(vec![vec![1, 2, 4], vec![3, 4, 3], vec![2, 3, 1]], 2),
        7
    );
    assert_eq!(
        Solution::max_value(vec![vec![1, 2, 4], vec![3, 4, 3], vec![2, 3, 10]], 2),
        10
    );
}
