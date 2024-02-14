#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

// O(nlogn)
// class Solution {
//   public:
//     std::vector<int> sortedSquares(std::vector<int> &nums) {
//         std::vector<int> squared(nums.size());
//         for (int i = 0; i < nums.size(); i++) {
//             squared[i] = nums[i] * nums[i];
//         }

//         std::ranges::sort(squared.begin(), squared.end());
//         return squared;
//     }
// };

// O(n) with linear search
// class Solution {
//   public:
//     std::vector<int> sortedSquares(std::vector<int> &nums) {
//         std::vector<int> squared(nums.size(), 0);
//         if (nums[0] >= 0) {
//             for (int i = 0; i < nums.size(); i++) {
//                 squared[i] = nums[i] * nums[i];
//             }
//             return squared;
//         }

//         int left = -1;
//         int right = nums.size();
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] >= 0) {
//                 left = i - 1;
//                 right = i;
//                 break;
//             }
//         }

//         if (right == nums.size()) {
//             for (int i = 0; i < nums.size(); i++) {
//                 squared[nums.size() - 1 - i] = nums[i] * nums[i];
//             }
//             return squared;
//         }

//         int i = 0;
//         while (left >= 0 || right < nums.size()) {
//             if (right >= nums.size()) {
//                 squared[i] = nums[left] * nums[left];
//                 i++;
//                 left--;
//             } else if (left < 0) {
//                 squared[i] = nums[right] * nums[right];
//                 i++;
//                 right++;
//             } else if (abs(nums[left]) <= abs(nums[right])) {
//                 squared[i] = nums[left] * nums[left];
//                 i++;
//                 left--;
//             } else {
//                 squared[i] = nums[right] * nums[right];
//                 i++;
//                 right++;
//             }
//         }

//         return squared;
//     }
// };

// O(n) with binary search
// class Solution {
//   public:
//     std::vector<int> sortedSquares(std::vector<int> &nums) {
//         std::vector<int> squared(nums.size());
//         int              leftI  = -1;
//         int              rightI = nums.size();

//         if (nums.front() >= 0) {
//             for (int i = 0; i < nums.size(); i++) {
//                 squared[i] = nums[i] * nums[i];
//             }
//             return squared;
//         } else if (nums.back() <= 0) {
//             for (int i = 0; i < nums.size(); i++) {
//                 squared[nums.size() - i - 1] = nums[i] * nums[i];
//             }
//             return squared;
//         }

//         int l = 0;
//         int r = nums.size() - 1;
//         while (l <= r) {
//             int m = l + (r - l) / 2;
//             if (nums[m] >= 0 && nums[m - 1] <= 0) {
//                 leftI  = m - 1;
//                 rightI = m;
//                 break;
//             }

//             if (nums[m] < 0) {
//                 l = m + 1;
//             } else {
//                 r = m - 1;
//             }
//         }

//         if (rightI == nums.size()) {
//             leftI  = nums.size() - 2;
//             rightI = nums.size() - 1;
//         }

//         int i = 0;
//         while (leftI >= 0 || rightI < nums.size()) {
//             if (rightI >= nums.size()) {
//                 squared[i] = nums[leftI] * nums[leftI];
//                 i++;
//                 leftI--;
//             } else if (leftI < 0) {
//                 squared[i] = nums[rightI] * nums[rightI];
//                 i++;
//                 rightI++;
//             } else if (abs(nums[leftI]) <= abs(nums[rightI])) {
//                 squared[i] = nums[leftI] * nums[leftI];
//                 i++;
//                 leftI--;
//             } else {
//                 squared[i] = nums[rightI] * nums[rightI];
//                 i++;
//                 rightI++;
//             }
//         }

//         return squared;
//     }
// };

class Solution {
  public:
    std::vector<int> sortedSquares(std::vector<int> &nums) {
        std::vector<int> squared(nums.size());
        int              left  = 0;
        int              right = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                squared[i] = nums[left] * nums[left];
                left++;
            } else {
                squared[i] = nums[right] * nums[right];
                right--;
            }
        }

        return squared;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{-4, -1, 0, 3, 10}, {0, 1, 9, 16, 100}},
        {{-7, -3, 2, 3, 11}, {4, 9, 9, 49, 121}},
        {{1, 2, 3, 4, 7}, {1, 4, 9, 16, 49}},
        {{-7, -4, -3, -2, -1}, {1, 4, 9, 16, 49}},
        {{-1, 1}, {1, 1}},
        {{-1, 0, 1}, {0, 1, 1}},
        {{-2, -1, 3}, {1, 4, 9}},
        {{-10, -6, -5, -3, -2, -2, 3, 3, 3, 5},
         {4, 4, 9, 9, 9, 9, 25, 25, 36, 100}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.sortedSquares(test);
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
