#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                       int valueDiff) {
        std::set<int> curr;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > indexDiff) {
                curr.erase(nums[i - indexDiff - 1]);
            }

            auto pos = curr.lower_bound(nums[i] - valueDiff);
            if (pos != curr.end() && *pos - nums[i] <= valueDiff) {
                return true;
            }

            curr.insert(nums[i]);
        }

        return false;
    }
};

// code_end
