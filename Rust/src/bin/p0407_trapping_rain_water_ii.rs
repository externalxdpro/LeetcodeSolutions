// 407. Trapping Rain Water II
// Difficulty: Hard

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

// Example 1:

// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.

// Example 2:

// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10

// Constraints:

//     m == heightMap.length
//     n == heightMap[i].length
//     1 <= m, n <= 200
//     0 <= heightMap[i][j] <= 2 * 104

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn trap_rain_water(height_map: Vec<Vec<i32>>) -> i32 {
        use {core::cmp::Reverse, std::collections::BinaryHeap};

        const DIRS: [(i32, i32); 4] = [(0, -1), (0, 1), (-1, 0), (1, 0)];
        let (m, n) = (height_map.len(), height_map[0].len());

        let mut visited = vec![vec![false; n]; m];
        let mut bounds: BinaryHeap<Reverse<(i32, usize, usize)>> = BinaryHeap::new();

        for i in 0..m {
            bounds.push(Reverse((height_map[i][0], i, 0)));
            bounds.push(Reverse((height_map[i][n - 1], i, n - 1)));
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for j in 0..n {
            bounds.push(Reverse((height_map[0][j], 0, j)));
            bounds.push(Reverse((height_map[m - 1][j], m - 1, j)));
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        let mut result = 0;
        while !bounds.is_empty() {
            let Reverse((h, i, j)) = bounds.pop().unwrap();

            for d in 0..4 {
                let dir = DIRS[d];
                let (di, dj) = (i as i32 + dir.0, j as i32 + dir.1);
                if !Self::in_bounds(&height_map, di, dj) {
                    continue;
                }
                let (di, dj) = (di as usize, dj as usize);
                if visited[di][dj] {
                    continue;
                }
                let dh = height_map[di][dj];
                if dh < h {
                    result += h - dh;
                }
                bounds.push(Reverse((h.max(dh), di, dj)));
                visited[di][dj] = true;
            }
        }
        result
    }

    fn in_bounds(grid: &Vec<Vec<i32>>, i: i32, j: i32) -> bool {
        i >= 0 && i < grid.len() as i32 && j >= 0 && j < grid[0].len() as i32
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::trap_rain_water(vec![
            vec![1, 4, 3, 1, 3, 2],
            vec![3, 2, 1, 3, 2, 4],
            vec![2, 3, 3, 2, 3, 1]
        ]),
        4
    );
    assert_eq!(
        Solution::trap_rain_water(vec![
            vec![3, 3, 3, 3, 3],
            vec![3, 2, 2, 2, 3],
            vec![3, 2, 1, 2, 3],
            vec![3, 2, 2, 2, 3],
            vec![3, 3, 3, 3, 3]
        ]),
        10
    );
}
