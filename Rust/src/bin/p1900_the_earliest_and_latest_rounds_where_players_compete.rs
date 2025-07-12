// 1900. The Earliest and Latest Rounds Where Players Compete
// Difficulty: Hard

// There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).

// The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the middle automatically advances to the next round.

//     For example, if the row consists of players 1, 2, 4, 6, 7
//         Player 1 competes against player 7.
//         Player 2 competes against player 6.
//         Player 4 automatically advances to the next round.

// After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).

// The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.

// Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and the latest possible round number in which these two players will compete against each other, respectively.

// Example 1:

// Input: n = 11, firstPlayer = 2, secondPlayer = 4
// Output: [3,4]
// Explanation:
// One possible scenario which leads to the earliest round number:
// First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
// Second round: 2, 3, 4, 5, 6, 11
// Third round: 2, 3, 4
// One possible scenario which leads to the latest round number:
// First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
// Second round: 1, 2, 3, 4, 5, 6
// Third round: 1, 2, 4
// Fourth round: 2, 4

// Example 2:

// Input: n = 5, firstPlayer = 1, secondPlayer = 5
// Output: [1,1]
// Explanation: The players numbered 1 and 5 compete in the first round.
// There is no way to make them compete in any other round.

// Constraints:

//     2 <= n <= 28
//     1 <= firstPlayer < secondPlayer <= n

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn earliest_and_latest(n: i32, first_player: i32, second_player: i32) -> Vec<i32> {
        let mut l = first_player.min(second_player);
        let mut r = first_player.max(second_player);

        if l + r == n + 1 {
            return vec![1, 1];
        }
        if n == 3 || n == 4 {
            return vec![2, 2];
        }

        if l - 1 > n - r {
            let t = n + 1 - l;
            l = n + 1 - r;
            r = t;
        }

        let next = (n + 1) / 2;
        let mut result = vec![];

        if r * 2 <= n + 1 {
            let prev_l = l - 1;
            let m = r - l - 1;
            for i in 0..=prev_l {
                for j in 0..=m {
                    if let [min, max] = Self::earliest_and_latest(next, i + 1, i + j + 2)[..] {
                        result.extend_from_slice(&[min + 1, max + 1]);
                    }
                }
            }
        } else {
            let mirrored = n + 1 - r;
            let prev_l = l - 1;
            let m = mirrored - l - 1;
            let inner = r - mirrored - 1;

            for i in 0..=prev_l {
                for j in 0..=m {
                    let second = i + j + 1 + ((inner + 1) / 2) + 1;
                    if let [min, max] = Self::earliest_and_latest(next, i + 1, second)[..] {
                        result.extend_from_slice(&[min + 1, max + 1]);
                    }
                }
            }
        }

        vec![*result.iter().min().unwrap(), *result.iter().max().unwrap()]
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::earliest_and_latest(11, 2, 4), [3, 4]);
    assert_eq!(Solution::earliest_and_latest(5, 1, 5), [1, 1]);
}
