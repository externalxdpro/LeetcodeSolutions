// 1792. Maximum Average Pass Ratio
// Difficulty: Medium

// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

// Example 2:

// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485

// Constraints:

//     1 <= classes.length <= 105
//     classes[i].length == 2
//     1 <= passi <= totali <= 105
//     1 <= extraStudents <= 105

pub struct Solution {}

// submission codes start here

#[derive(PartialEq)]
struct NonNan(f64);

impl PartialOrd for NonNan {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        other.0.partial_cmp(&self.0)
    }
}
impl Eq for NonNan {}
impl Ord for NonNan {
    fn cmp(&self, other: &NonNan) -> std::cmp::Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl Solution {
    pub fn max_average_ratio(classes: Vec<Vec<i32>>, extra_students: i32) -> f64 {
        use std::{cmp::Reverse, collections::BinaryHeap};
        fn gain(passes: i32, total: i32) -> f64 {
            (passes + 1) as f64 / (total + 1) as f64 - passes as f64 / total as f64
        }
        let mut heap: BinaryHeap<Reverse<(NonNan, i32, i32)>> = BinaryHeap::new();
        for c in classes.iter() {
            heap.push(Reverse((NonNan(gain(c[0], c[1])), c[0], c[1])));
        }

        for _ in 0..extra_students {
            let (_, passes, total) = heap.pop().unwrap().0;
            heap.push(Reverse((
                NonNan(gain(passes + 1, total + 1)),
                passes + 1,
                total + 1,
            )));
        }

        let mut ratio = 0.;
        while !heap.is_empty() {
            let (_, passes, total) = heap.pop().unwrap().0;
            ratio += passes as f64 / total as f64;
        }
        ratio / classes.len() as f64
    }
}

// submission codes end

fn main() {
    fn round(n: f64, digs: i32) -> f64 {
        let factor = 10f64.powi(digs);
        (n * factor).round() / factor
    }

    assert_eq!(
        round(
            Solution::max_average_ratio(vec![vec![1, 2], vec![3, 5], vec![2, 2]], 2),
            5
        ),
        0.78333
    );
    assert_eq!(
        round(
            Solution::max_average_ratio(vec![vec![2, 4], vec![3, 9], vec![4, 5], vec![2, 10]], 4),
            5
        ),
        0.53485
    );
}
