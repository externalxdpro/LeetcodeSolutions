// 515. Find Largest Value in Each Tree Row
// Difficulty: Medium

// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

// Example 1:

// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]

// Example 2:

// Input: root = [1,2,3]
// Output: [1,3]

// Constraints:

//     The number of nodes in the tree will be in the range [0, 104].
//     -231 <= Node.val <= 231 - 1

mod _binary_tree;
use _binary_tree::TreeNode;

pub struct Solution {}

// submission codes start here

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        if let None = root {
            return vec![];
        }

        use std::collections::VecDeque;
        let mut dq = VecDeque::from([root.unwrap()]);
        let mut result = vec![];

        while !dq.is_empty() {
            let sz = dq.len();
            let mut max: Option<i32> = None;
            for _ in 0..sz {
                let front_ref = dq.pop_front().unwrap();
                let front = front_ref.borrow();
                if max.is_none() || max.unwrap() < front.val {
                    max = Some(front.val);
                }
                if let Some(l) = &front.left {
                    dq.push_back(Rc::clone(l));
                }
                if let Some(r) = &front.right {
                    dq.push_back(Rc::clone(r));
                }
            }
            result.push(max.unwrap());
        }

        result
    }
}

// submission codes end

fn main() {}
