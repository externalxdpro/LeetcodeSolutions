#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        std::map<int, int> counts;
        for (int i : nums) {
            counts[i]++;
        }

        std::vector<int> result;
        for (auto &[k, v] : counts) {
            if (v > n / 3) {
                result.push_back(k);
            }
        }
        return result;
    }
};

// code_end
