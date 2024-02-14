// Difficulty: Medium
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//     0 <= a, b, c, d < n
//     a, b, c, and d are distinct.
//     nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:
//     1 <= nums.length <= 200
//     -109 <= nums[i] <= 109
//     -109 <= target <= 109

#include <bits/stdc++.h>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    std::set<std::vector<int>> set;
    for (auto i = nums.begin(); i < nums.end() - 1; i++)
    {
        for (auto j = nums.end() - 1; j > nums.begin(); j--)
        {
            std::vector<int>::iterator l = i + 1, r = j - 1;
            while (l < r)
            {
                std::vector<int> elems = {*i, *j, *l, *r};
                long long int sum = 0;
                for (int x : elems) sum += x;

                if (sum == target) set.insert(elems);

                if (sum < target) l++;
                else r--;
            }
        }
    }

    std::vector<std::vector<int>> result;
    for (auto combs : set) result.push_back(combs);
    return result;
}

int main()
{
    std::vector<std::pair<std::vector<int>, int>> cases = {
        {{1,0,-1,0,-2,2}, 0},
        {{2,2,2,2,2}, 8},
        {{1000000000,1000000000,1000000000,1000000000}, 0},
    };

    for (auto [nums, target] : cases)
    {
        std::cout << '{';
        for (auto vec : fourSum(nums, target))
        {
            std::cout << '{';
            for (int num : vec)
                std::cout << num << ',';
            std::cout << "},";
        }
        std::cout << "}\n";
    }
}
