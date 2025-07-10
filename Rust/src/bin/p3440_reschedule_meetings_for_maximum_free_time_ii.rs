// 3440. Reschedule Meetings for Maximum Free Time II
// Difficulty: Medium

// You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.

// These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].

// You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.

// Return the maximum amount of free time possible after rearranging the meetings.

// Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.

// Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.

// Example 1:

// Input: eventTime = 5, startTime = [1,3], endTime = [2,5]

// Output: 2

// Explanation:

// Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].

// Example 2:

// Input: eventTime = 10, startTime = [0,7,9], endTime = [1,8,10]

// Output: 7

// Explanation:

// Reschedule the meeting at [0, 1] to [8, 9], leaving no meetings during the time [0, 7].

// Example 3:

// Input: eventTime = 10, startTime = [0,3,7,9], endTime = [1,4,8,10]

// Output: 6

// Explanation:

// Reschedule the meeting at [3, 4] to [8, 9], leaving no meetings during the time [1, 7].

// Example 4:

// Input: eventTime = 5, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]

// Output: 0

// Explanation:

// There is no time during the event not occupied by meetings.

// Constraints:

//     1 <= eventTime <= 109
//     n == startTime.length == endTime.length
//     2 <= n <= 105
//     0 <= startTime[i] < endTime[i] <= eventTime
//     endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].

pub struct Solution {}

// submission codes start here

// const maxFreeTime = (eventTime, startTime, endTime) => {
//     const len = startTime.length;
//     const gaps = new Array(len + 1);
//     let lastEnd = 0;

//     startTime.forEach((s, i) => {
//         gaps[i] = s - lastEnd;
//         lastEnd = endTime[i];
//     });

//     gaps[len] = eventTime - lastEnd;

//     const rightMax = new Array(len + 1).fill(0);
//     rightMax.reduceRight((a, val, i) => {
//         if (i < len) rightMax[i] = Math.max(rightMax[i + 1], gaps[i + 1]);
//         return a;
//     }, 0);

//     let leftMax = 0;
//     let maxGap = 0;

//     startTime.map((s, i) => i + 1).forEach(i => {
//         const dur = endTime[i - 1] - startTime[i - 1];
//         const gapL = gaps[i - 1];
//         const gapR = gaps[i];

//         if (leftMax >= dur || rightMax[i] >= dur)
//             maxGap = Math.max(maxGap, gapL + dur + gapR);

//         maxGap = Math.max(maxGap, gapL + gapR);
//         leftMax = Math.max(leftMax, gapL);
//     });

//     return maxGap;
// };

impl Solution {
    pub fn max_free_time(event_time: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
        let n = start_time.len();
        let mut gaps = vec![0; n + 1];
        let mut end = 0;
        for (i, &s) in start_time.iter().enumerate() {
            gaps[i] = s - end;
            end = end_time[i];
        }
        *gaps.last_mut().unwrap() = event_time - end;

        let mut max_gap = 0;
        let mut l_max = 0;
        let mut r_max = vec![0; n + 1];
        for i in (0..n).rev() {
            r_max[i] = r_max[i + 1].max(gaps[i + 1]);
        }

        for i in 1..=n {
            let duration = end_time[i - 1] - start_time[i - 1];
            if l_max >= duration || r_max[i] >= duration {
                max_gap = max_gap.max(gaps[i - 1] + duration + gaps[i]);
            }
            max_gap = max_gap.max(gaps[i - 1] + gaps[i]);
            l_max = l_max.max(gaps[i - 1]);
        }

        max_gap
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::max_free_time(5, vec![1, 3], vec![2, 5]), 2);
    assert_eq!(
        Solution::max_free_time(10, vec![0, 7, 9], vec![1, 8, 10]),
        7
    );
    assert_eq!(
        Solution::max_free_time(10, vec![0, 3, 7, 9], vec![1, 4, 8, 10]),
        6
    );
}
