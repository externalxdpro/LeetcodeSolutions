// 1233. Remove Sub-Folders from the Filesystem
// Difficulty: Medium

// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

// If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

// The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

//     For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.

// Example 1:

// Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
// Output: ["/a","/c/d","/c/f"]
// Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.

// Example 2:

// Input: folder = ["/a","/a/b/c","/a/b/d"]
// Output: ["/a"]
// Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".

// Example 3:

// Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
// Output: ["/a/b/c","/a/b/ca","/a/b/d"]

// Constraints:

//     1 <= folder.length <= 4 * 104
//     2 <= folder[i].length <= 100
//     folder[i] contains only lowercase letters and '/'.
//     folder[i] always starts with the character '/'.
//     Each folder name is unique.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn remove_subfolders(mut folder: Vec<String>) -> Vec<String> {
        folder.sort_unstable();
        let mut result = Vec::with_capacity(folder.len());

        let mut i = 0;
        while i < folder.len() {
            result.push(folder[i].clone());
            let prefix = result.last().unwrap().clone() + "/";
            i += 1;
            while i < folder.len() {
                if !folder[i].starts_with(&prefix) {
                    i -= 1;
                    break;
                }
                i += 1;
            }
            i += 1;
        }
        result
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::remove_subfolders(vec![
            "/a".to_string(),
            "/a/b".to_string(),
            "/c/d".to_string(),
            "/c/d/e".to_string(),
            "/c/f".to_string()
        ]),
        ["/a", "/c/d", "/c/f"]
    );
    assert_eq!(
        Solution::remove_subfolders(vec![
            "/a".to_string(),
            "/a/b/c".to_string(),
            "/a/b/d".to_string(),
        ]),
        ["/a"]
    );
    assert_eq!(
        Solution::remove_subfolders(vec![
            "/a/b/c".to_string(),
            "/a/b/ca".to_string(),
            "/a/b/d".to_string()
        ]),
        ["/a/b/c", "/a/b/ca", "/a/b/d"]
    );
}
