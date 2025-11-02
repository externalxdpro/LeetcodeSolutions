// 2257. Count Unguarded Cells in the Grid
// Difficulty: Medium

// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.

// Example 1:

// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.

// Example 2:

// Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output: 4
// Explanation: The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.

// Constraints:

//     1 <= m, n <= 105
//     2 <= m * n <= 105
//     1 <= guards.length, walls.length <= 5 * 104
//     2 <= guards.length + walls.length <= m * n
//     guards[i].length == walls[j].length == 2
//     0 <= rowi, rowj < m
//     0 <= coli, colj < n
//     All the positions in guards and walls are unique.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (m as usize, n as usize);
        let mut grid = vec![vec![0; n]; m];
        for w in walls {
            grid[w[0] as usize][w[1] as usize] = 2;
        }
        for g in guards.iter() {
            grid[g[0] as usize][g[1] as usize] = 2;
        }

        for g in guards {
            let (gi, gj) = (g[0] as usize, g[1] as usize);
            for i in (gi + 1)..m {
                if grid[i][gj] == 2 {
                    break;
                }
                grid[i][gj] = 1;
            }
            for i in (0..gi).rev() {
                if grid[i][gj] == 2 {
                    break;
                }
                grid[i][gj] = 1;
            }
            for j in (gj + 1)..n {
                if grid[gi][j] == 2 {
                    break;
                }
                grid[gi][j] = 1;
            }
            for j in (0..gj).rev() {
                if grid[gi][j] == 2 {
                    break;
                }
                grid[gi][j] = 1;
            }
        }

        grid.into_iter()
            .map(|r| r.into_iter().filter(|&x| x == 0).count() as i32)
            .sum()
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::count_unguarded(
            4,
            6,
            vec![vec![0, 0], vec![1, 1], vec![2, 3]],
            vec![vec![0, 1], vec![2, 2], vec![1, 4]]
        ),
        7
    );
    assert_eq!(
        Solution::count_unguarded(
            3,
            3,
            vec![vec![1, 1]],
            vec![vec![0, 1], vec![1, 0], vec![2, 1], vec![1, 2]]
        ),
        4
    );
}
