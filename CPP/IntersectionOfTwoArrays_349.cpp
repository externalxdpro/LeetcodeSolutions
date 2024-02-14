// Difficulty: Easy
// Given two integer arrays nums1 and nums2, return an array of their
// intersection. Each element in the result must be unique and you may return
// the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

// Constraints:
//     1 <= nums1.length, nums2.length <= 1000
//     0 <= nums1[i], nums2[i] <= 1000

#include <array>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// std::vector<int> intersection(std::vector<int> &nums1,
//                               std::vector<int> &nums2) {
//     std::unordered_set<int> intersections;

//     for (int i : nums1) {
//         if (std::ranges::find(nums2, i) != nums2.end()) {
//             intersections.insert(i);
//         }
//     }

//     return std::vector<int>(intersections.begin(), intersections.end());
// }

// std::vector<int> intersection(std::vector<int> &nums1,
//                               std::vector<int> &nums2) {
//     std::unordered_map<int, int> found;
//     std::unordered_set<int> intersections;

//     for (int i : nums1) {
//         found[i]++;
//     }

//     for (int i : nums2) {
//         if (found[i]) {
//             intersections.insert(i);
//         }
//     }

//     return std::vector<int>(intersections.begin(), intersections.end());
// }

// std::vector<int> intersection(std::vector<int> &nums1,
//                               std::vector<int> &nums2) {
//     std::unordered_set<int> s;
//     std::unordered_set<int> result;

//     for (int i : nums1) {
//         s.insert(i);
//     }

//     for (int i : nums2) {
//         if (s.contains(i)) {
//             result.insert(i);
//         }
//     }

//     return std::vector<int>(result.begin(), result.end());
// }

std::vector<int> intersection(std::vector<int> &nums1,
                              std::vector<int> &nums2) {
    std::array<int, 1001> table{0};
    std::unordered_set<int> result;

    for (int i : nums1) {
        table[i] = 1;
    }

    for (int i : nums2) {
        if (table[i]) {
            result.insert(i);
        }
    }

    return std::vector<int>(result.begin(), result.end());
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1, 2, 2, 1}, {2, 2}},
        {{4, 9, 5}, {9, 4, 9, 8, 4}},
    };

    for (auto test : tests) {
        for (int i : intersection(test.first, test.second)) {
            std::cout << i << ',';
        }
        std::cout << std::endl;
    }

    return 0;
}
