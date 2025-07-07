// 1353. Maximum Number of Events That Can Be Attended
// Difficulty: Medium

// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

// Return the maximum number of events you can attend.

// Example 1:

// Input: events = [[1,2],[2,3],[3,4]]
// Output: 3
// Explanation: You can attend all the three events.
// One way to attend them all is as shown.
// Attend the first event on day 1.
// Attend the second event on day 2.
// Attend the third event on day 3.

// Example 2:

// Input: events= [[1,2],[2,3],[3,4],[1,2]]
// Output: 4

// Constraints:

//     1 <= events.length <= 105
//     events[i].length == 2
//     1 <= startDayi <= endDayi <= 105

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_events(mut events: Vec<Vec<i32>>) -> i32 {
        use std::{cmp::Reverse, collections::BinaryHeap};
        let max = events.iter().map(|x| x[1]).max().unwrap_or_default();
        let mut heap = BinaryHeap::new();
        events.sort_unstable();

        let mut result = 0;
        let mut j = 0;
        for i in 0..=max {
            while j < events.len() && events[j][0] <= i {
                heap.push(Reverse(events[j][1]));
                j += 1;
            }
            while !heap.is_empty() && heap.peek().unwrap().0 < i {
                heap.pop();
            }
            if !heap.is_empty() {
                heap.pop();
                result += 1;
            }
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::max_events(vec![vec![1, 2], vec![2, 3], vec![3, 4]]),
        3
    );
    assert_eq!(
        Solution::max_events(vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![1, 2]]),
        4
    );
}
