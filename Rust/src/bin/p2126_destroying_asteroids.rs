// [2126] Destroying Asteroids
// Difficulty: Medium

// You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.
// You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.
// Return true if all asteroids can be destroyed. Otherwise, return false.

// Example 1:
// Input: mass = 10, asteroids = [3,9,19,5,21]
// Output: true
// Explanation: One way to order the asteroids is [9,19,5,3,21]:
// - The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
// - The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
// - The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
// - The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
// - The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
// All asteroids are destroyed.

// Example 2:
// Input: mass = 5, asteroids = [4,9,23,4]
// Output: false
// Explanation:
// The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
// After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
// This is less than 23, so a collision would not destroy the last asteroid.

// Constraints:
//     1 <= mass <= 10^5
//     1 <= asteroids.length <= 10^5
//     1 <= asteroids[i] <= 10^5

pub struct Solution {}

// submission codes start here

use std::{cmp::Reverse, collections::BinaryHeap};

impl Solution {
    pub fn asteroids_destroyed(mass: i32, asteroids: Vec<i32>) -> bool {
        let mut mass = mass as u64;
        let mut heap: BinaryHeap<Reverse<u64>> =
            asteroids.into_iter().map(|x| Reverse(x as u64)).collect();
        while let Some(x) = heap.pop() {
            match x.0 {
                n if (1..=mass).contains(&n) => mass += n,
                _ => return false,
            }
        }
        true
    }
}

// submission codes end

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_2126() {
        assert_eq!(
            Solution::asteroids_destroyed(10, vec![3, 9, 19, 5, 21]),
            true
        );
        assert_eq!(Solution::asteroids_destroyed(5, vec![4, 9, 23, 4]), false);
    }
}

fn main() {}
