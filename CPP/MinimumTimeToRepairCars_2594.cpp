// 2594. Minimum Time to Repair Cars
// Difficulty: Medium

// You are given an integer array ranks representing the ranks of some
// mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r
// can repair n cars in r * n2 minutes.

// You are also given an integer cars representing the total number of cars
// waiting in the garage to be repaired.

// Return the minimum time taken to repair all the cars.

// Note: All the mechanics can repair the cars simultaneously.

// Example 1:

// Input: ranks = [4,2,3,1], cars = 10
// Output: 16
// Explanation:
// - The first mechanic will repair two cars. The time required is 4 * 2 * 2 =
// 16 minutes.
// - The second mechanic will repair two cars. The time required is 2 * 2 * 2 =
// 8 minutes.
// - The third mechanic will repair two cars. The time required is 3 * 2 * 2 =
// 12 minutes.
// - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 =
// 16 minutes. It can be proved that the cars cannot be repaired in less than 16
// minutes.​​​​​

// Example 2:

// Input: ranks = [5,1,8], cars = 6
// Output: 16
// Explanation:
// - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5
// minutes.
// - The second mechanic will repair four cars. The time required is 1 * 4 * 4 =
// 16 minutes.
// - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8
// minutes. It can be proved that the cars cannot be repaired in less than 16
// minutes.​​​​​

// Constraints:

//     1 <= ranks.length <= 105
//     1 <= ranks[i] <= 100
//     1 <= cars <= 106

#include <algorithm>
#include <fmt/ranges.h>
#include <limits>
#include <vector>

class Solution {
  public:
    long long repairCars(std::vector<int> &ranks, int cars) {
        auto [minit, maxit] = std::ranges::minmax_element(ranks);
        int min = *minit, max = *maxit;

        std::vector<int> freq(max + 1);
        for (int rank : ranks) {
            freq[rank]++;
        }

        long long l = 1, r = std::numeric_limits<long long>::max();
        while (l < r) {
            long long m        = l + (r - l) / 2;
            long long repaired = 0;

            for (int i = 1; i <= max; i++) {
                repaired += freq[i] * (long long)std::sqrt(m / (long long)i);
            }
            if (repaired >= cars) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, long long>> tests =
        {
            {{{4, 2, 3, 1}, 10}, 16},
            {{{5, 1, 8}, 6}, 16},
            {{{1, 1, 3, 3}, 74}, 576},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.repairCars(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
