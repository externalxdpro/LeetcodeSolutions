// [#] Name
// Difficulty:

// Description

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn second_minimum(n: i32, edges: Vec<Vec<i32>>, time: i32, change: i32) -> i32 {
        use std::{cmp::Reverse, collections::BinaryHeap};

        let mut adj: Vec<Vec<i32>> = vec![vec![]; (n + 1) as usize];
        for edge in edges {
            let (from, to) = (edge[0], edge[1]);
            adj[from as usize].push(to);
            adj[to as usize].push(from);
        }

        let mut dist1 = vec![i32::MAX; (n + 1) as usize];
        let mut dist2 = vec![i32::MAX; (n + 1) as usize];
        let mut freq = vec![0; (n + 1) as usize];
        let mut heap: BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::from([Reverse((0, 1))]);
        dist1[1] = 0;

        while !heap.is_empty() {
            let (mut time_taken, node) = heap.pop().unwrap().0;

            freq[node as usize] += 1;
            if freq[node as usize] == 2 && node == n {
                return time_taken;
            }
            if (time_taken / change) % 2 == 1 {
                time_taken = change * (time_taken / change + 1) + time;
            } else {
                time_taken = time_taken + time;
            }

            for &neighbour in adj[node as usize].iter() {
                if freq[neighbour as usize] == 2 {
                    continue;
                }

                if dist1[neighbour as usize] > time_taken {
                    dist2[neighbour as usize] = dist1[neighbour as usize];
                    dist1[neighbour as usize] = time_taken;
                    heap.push(Reverse((time_taken, neighbour)));
                } else if dist2[neighbour as usize] > time_taken
                    && dist1[neighbour as usize] != time_taken
                {
                    dist2[neighbour as usize] = time_taken;
                    heap.push(Reverse((time_taken, neighbour)));
                }
            }
        }

        0
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_num() {
        assert_eq!(
            Solution::second_minimum(
                5,
                vec![vec![1, 2], vec![1, 3], vec![1, 4], vec![3, 4], vec![4, 5]],
                3,
                5
            ),
            13
        );
        assert_eq!(Solution::second_minimum(2, vec![vec![1, 2]], 3, 2), 11);
    }
}

fn main() {}
