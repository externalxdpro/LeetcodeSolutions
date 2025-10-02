// 3100. Water Bottles II
// Difficulty: Medium

// You are given two integers numBottles and numExchange.

// numBottles represents the number of full water bottles that you initially have. In one operation, you can perform one of the following operations:

//     Drink any number of full water bottles turning them into empty bottles.
//     Exchange numExchange empty bottles with one full water bottle. Then, increase numExchange by one.

// Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange. For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.

// Return the maximum number of water bottles you can drink.

// Example 1:

// Input: numBottles = 13, numExchange = 6
// Output: 15
// Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.

// Example 2:

// Input: numBottles = 10, numExchange = 3
// Output: 13
// Explanation: The table above shows the number of full water bottles, empty water bottles, the value of numExchange, and the number of bottles drunk.

// Constraints:

//     1 <= numBottles <= 100
//     1 <= numExchange <= 100

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn max_bottles_drunk(num_bottles: i32, mut num_exchange: i32) -> i32 {
        let (mut full, mut empty) = (num_bottles, 0);
        let mut result = 0;
        while full > 0 {
            result += full;
            empty += full;
            full = 0;
            while empty >= num_exchange {
                full += 1;
                empty -= num_exchange;
                num_exchange += 1;
            }
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(Solution::max_bottles_drunk(13, 6), 15);
    assert_eq!(Solution::max_bottles_drunk(10, 3), 13);
}
