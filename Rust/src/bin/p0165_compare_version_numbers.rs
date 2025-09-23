// 165. Compare Version Numbers
// Difficulty: Medium

// Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

// To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

// Return the following:

//     If version1 < version2, return -1.
//     If version1 > version2, return 1.
//     Otherwise, return 0.

// Example 1:

// Input: version1 = "1.2", version2 = "1.10"

// Output: -1

// Explanation:

// version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

// Example 2:

// Input: version1 = "1.01", version2 = "1.001"

// Output: 0

// Explanation:

// Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

// Example 3:

// Input: version1 = "1.0", version2 = "1.0.0.0"

// Output: 0

// Explanation:

// version1 has less revisions, which means every missing revision are treated as "0".

// Constraints:

//     1 <= version1.length, version2.length <= 500
//     version1 and version2 only contain digits and '.'.
//     version1 and version2 are valid version numbers.
//     All the given revisions in version1 and version2 can be stored in a 32-bit integer.

pub struct Solution {}

// submission codes start here

impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let mut v1: Vec<i32> = version1.split(".").map(|s| s.parse().unwrap()).collect();
        let mut v2: Vec<i32> = version2.split(".").map(|s| s.parse().unwrap()).collect();
        let (n1, n2) = (v1.len(), v2.len());
        if n1 < n2 {
            v1.extend_from_slice(vec![0; n2 - n1].as_slice());
        }
        if n2 < n1 {
            v2.extend_from_slice(vec![0; n1 - n2].as_slice());
        }
        for i in 0..v1.len() {
            if v1[i] < v2[i] {
                return -1;
            } else if v1[i] > v2[i] {
                return 1;
            }
        }
        0
    }
}

// submission codes end

fn main() {
    assert_eq!(
        Solution::compare_version("1.2".to_string(), "1.10".to_string()),
        -1
    );
    assert_eq!(
        Solution::compare_version("1.01".to_string(), "1.001".to_string()),
        0
    );
    assert_eq!(
        Solution::compare_version("1.0".to_string(), "1.0.0.0".to_string()),
        0
    );
}
