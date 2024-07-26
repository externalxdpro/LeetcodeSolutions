// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Difficulty: Medium

// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

// Example 1:
// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
// Explanation: The figure above describes the graph.
// The neighboring cities at a distanceThreshold = 4 for each city are:
// City 0 -> [City 1, City 2]
// City 1 -> [City 0, City 2, City 3]
// City 2 -> [City 0, City 1, City 3]
// City 3 -> [City 1, City 2]
// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

// Example 2:
// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
// Output: 0
// Explanation: The figure above describes the graph.
// The neighboring cities at a distanceThreshold = 2 for each city are:
// City 0 -> [City 1]
// City 1 -> [City 0, City 4]
// City 2 -> [City 3, City 4]
// City 3 -> [City 2, City 4]
// City 4 -> [City 1, City 2, City 3]
// The city 0 has 1 neighboring city at a distanceThreshold = 2.

// Constraints:
//     2 <= n <= 100
//     1 <= edges.length <= n * (n - 1) / 2
//     edges[i].length == 3
//     0 <= fromi < toi < n
//     1 <= weighti, distanceThreshold <= 10^4
//     All pairs (fromi, toi) are distinct.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn find_the_city(n: i32, edges: Vec<Vec<i32>>, distance_threshold: i32) -> i32 {
        let mut adj: Vec<Vec<(i32, i32)>> = vec![vec![]; n as usize];
        for e in edges {
            let (from, to, weight) = (e[0], e[1], e[2]);
            adj[from as usize].push((to, weight));
            adj[to as usize].push((from, weight));
        }

        let mut count = n;
        let mut num = -1;

        for i in 0..n {
            let mut curr_count = 0;
            let v = Self::djikstra(i, n, &adj);
            for a in v {
                if a <= distance_threshold {
                    curr_count += 1;
                }
            }

            if curr_count <= count {
                count = curr_count;
                num = i;
            }
        }

        num
    }

    fn djikstra(src: i32, n: i32, adj: &Vec<Vec<(i32, i32)>>) -> Vec<i32> {
        use std::collections::BinaryHeap;

        let mut heap: BinaryHeap<(i32, i32)> = BinaryHeap::new();
        let mut dists: Vec<i32> = vec![i32::MAX; n as usize];

        dists[src as usize] = 0;
        heap.push((0, src));

        while !heap.is_empty() {
            let (dist, node) = heap.pop().unwrap();

            for &(adj_node, weight) in adj[node as usize].iter() {
                if dist + weight < dists[adj_node as usize] {
                    dists[adj_node as usize] = dist + weight;
                    heap.push((dists[adj_node as usize], adj_node));
                }
            }
        }

        dists
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1334() {
        assert_eq!(
            Solution::find_the_city(
                4,
                vec![vec![0, 1, 3], vec![1, 2, 1], vec![1, 3, 4], vec![2, 3, 1]],
                4
            ),
            3
        );
        assert_eq!(
            Solution::find_the_city(
                5,
                vec![
                    vec![0, 1, 2],
                    vec![0, 4, 8],
                    vec![1, 2, 3],
                    vec![1, 4, 2],
                    vec![2, 3, 1],
                    vec![3, 4, 1]
                ],
                2
            ),
            0
        );
    }
}

fn main() {}
