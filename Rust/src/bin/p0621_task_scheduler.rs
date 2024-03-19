// [621] Task Scheduler
// Difficulty: Medium

// You are given an array of CPU tasks, each represented by letters A to Z, and
// a cooling time, n. Each cycle or interval allows the completion of one task.
// Tasks can be completed in any order, but there's a constraint: identical
// tasks must be separated by at least n intervals due to cooling time.
// ​Return the minimum number of intervals required to complete all tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A ->
// B.
// After completing task A, you must wait two cycles before doing A again. The
// same applies to task B. In the 3rd interval, neither A nor B can be done, so
// you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

// Example 2:
// Input: tasks = ["A","C","A","B","D","B"], n = 1
// Output: 6
// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
// With a cooling interval of 1, you can repeat a task after just one other
// task.

// Example 3:
// Input: tasks = ["A","A","A", "B","B","B"], n = 3
// Output: 10
// Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle
// -> idle -> A -> B.
// There are only two types of tasks, A and B, which need to be separated by 3
// intervals. This leads to idling twice between repetitions of these tasks.

// Constraints:
//     1 <= tasks.length <= 10^4
//     tasks[i] is an uppercase English letter.
//     0 <= n <= 100

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        let occ = tasks.iter().fold(vec![0; 26], |mut acc, &i| {
            acc[i as usize - 'A' as usize] += 1;
            acc
        });
        let max_freq = *occ.iter().max().unwrap();
        let num_max_freq = occ.iter().filter(|&&x| x == max_freq).count() as i32;

        std::cmp::max((max_freq - 1) * (n + 1) + num_max_freq, tasks.len() as i32)
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_621() {
        assert_eq!(
            Solution::least_interval(vec!['A', 'A', 'A', 'B', 'B', 'B'], 2),
            8
        );
        assert_eq!(
            Solution::least_interval(vec!['A', 'C', 'A', 'B', 'D', 'B'], 1),
            6
        );
        assert_eq!(
            Solution::least_interval(vec!['A', 'A', 'A', 'B', 'B', 'B'], 3),
            10
        );
    }
}

fn main() {}
