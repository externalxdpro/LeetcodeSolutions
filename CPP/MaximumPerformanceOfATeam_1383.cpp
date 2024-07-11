// 1383. Maximum Performance of a Team
// Difficulty: Hard

// You are given two integers n and k and two integer arrays speed and
// efficiency both of length n. There are n engineers numbered from 1 to n.
// speed[i] and efficiency[i] represent the speed and efficiency of the ith
// engineer respectively.
// Choose at most k different engineers out of the n engineers to form a team
// with the maximum performance.
// The performance of a team is the sum of its engineers' speeds multiplied by
// the minimum efficiency among its engineers.
// Return the maximum performance of this team. Since the answer can be a huge
// number, return it modulo 10^9 + 7.

// Example 1:
// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
// Output: 60
// Explanation:
// We have the maximum performance of the team by selecting engineer 2 (with
// speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7).
// That is, performance = (10 + 5) * min(4, 7) = 60.

// Example 2:
// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
// Output: 68
// Explanation:
// This is the same example as the first but k = 3. We can select engineer 1,
// engineer 2 and engineer 5 to get the maximum performance of the team. That
// is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.

// Example 3:
// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
// Output: 72

// Constraints:

//     1 <= k <= n <= 10^5
//     speed.length == n
//     efficiency.length == n
//     1 <= speed[i] <= 10^5
//     1 <= efficiency[i] <= 10^8

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <vector>

class Solution {
  public:
    int maxPerformance(int n, std::vector<int> &speed,
                       std::vector<int> &efficiency, int k) {
        std::vector<std::pair<int, int>> engineers(n);

        for (int i = 0; i < n; i++) {
            engineers[i] = {efficiency[i], speed[i]};
        }
        std::sort(engineers.rbegin(), engineers.rend());

        long currSpeed = 0, result = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minQ;

        for (auto &[eff, speed] : engineers) {
            if (minQ.size() == k) {
                currSpeed -= minQ.top();
                minQ.pop();
            }

            currSpeed += speed;
            minQ.push(speed);
            result = std::max(result, eff * currSpeed);
        }

        return (int)(result % 1'000'000'007);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::tuple<int, std::vector<int>, std::vector<int>, int>, int>>
        tests = {
            {{6, {2, 10, 3, 1, 5, 8}, {5, 4, 3, 9, 7, 2}, 2}, 60},
            {{6, {2, 10, 3, 1, 5, 8}, {5, 4, 3, 9, 7, 2}, 3}, 68},
            {{6, {2, 10, 3, 1, 5, 8}, {5, 4, 3, 9, 7, 2}, 4}, 72},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result =
            solution.maxPerformance(std::get<0>(test), std::get<1>(test),
                                    std::get<2>(test), std::get<3>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
