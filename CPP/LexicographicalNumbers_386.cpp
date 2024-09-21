// 386. Lexicographical Numbers
// Difficulty: Medium

// Given an integer n, return all the numbers in the range [1, n] sorted in
// lexicographical order.
// You must write an algorithm that runs in O(n) time and uses O(1) extra space.

// Example 1:
// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

// Example 2:
// Input: n = 2
// Output: [1,2]

// Constraints:
//     1 <= n <= 5 * 10^4

#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> result;
        result.reserve(n);
        for (int i = 1; i <= 9; i++) {
            recurse(i, n, result);
        }
        return result;
    }

  private:
    void recurse(int curr, int lim, std::vector<int> &result) {
        if (curr > lim) {
            return;
        }
        result.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            int num = curr * 10 + i;
            if (num > lim) {
                break;
            }
            recurse(num, lim, result);
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::vector<int>>> tests = {
        {13, {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9}},
        {2, {1, 2}},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.lexicalOrder(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
