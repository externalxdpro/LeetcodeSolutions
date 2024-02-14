#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// Not O(n)
// int firstMissingPositive(vector<int>& nums)
// {
//     sort(nums.begin(), nums.end());

//     int num = 1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] < num) continue;
//         if (nums[i] != num)
//         {
//             return num;
//         }

//         num++;
//     }

//     return num;
// }

int firstMissingPositive(vector<int> &nums) {
    unordered_map<int, int> map;

    for (int num : nums) {
        map[num]++;
    }

    for (int i = 1; i <= nums.size(); i++) {
        if (!map[i]) {
            return i;
        }
    }

    return nums.size() + 1;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive(nums) << "\n";

    return 0;
}
