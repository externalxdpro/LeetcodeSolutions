#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        std::vector<std::string> result;
        for (size_t i = 0; i < nums.size(); i++) {
            int start = i;
            while (i < nums.size() - 1 && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            int end = i;
            std::string range =
                start == end ? std::format("{}", nums[i])
                             : std::format("{}->{}", nums[start], nums[end]);
            result.push_back(range);
        }
        return result;
    }
};

// code_end
