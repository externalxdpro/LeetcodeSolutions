// 2528. Maximize the Minimum Powered City
// Difficulty: Hard

// You are given a 0-indexed integer array stations of length n, where
// stations[i] represents the number of power stations in the ith city.

// Each power station can provide power to every city in a fixed range. In other
// words, if the range is denoted by r, then a power station at city i can
// provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.

//     Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 -
//     10| = 7.

// The power of a city is the total number of power stations it is being
// provided power from.

// The government has sanctioned building k more power stations, each of which
// can be built in any city, and have the same range as the pre-existing ones.

// Given the two integers r and k, return the maximum possible minimum power of
// a city, if the additional power stations are built optimally.

// Note that you can build the k power stations in multiple cities.

// Example 1:

// Input: stations = [1,2,4,5,0], r = 1, k = 2
// Output: 5
// Explanation:
// One of the optimal ways is to install both the power stations at city 1.
// So stations will become [1,4,4,5,0].
// - City 0 is provided by 1 + 4 = 5 power stations.
// - City 1 is provided by 1 + 4 + 4 = 9 power stations.
// - City 2 is provided by 4 + 4 + 5 = 13 power stations.
// - City 3 is provided by 5 + 4 = 9 power stations.
// - City 4 is provided by 5 + 0 = 5 power stations.
// So the minimum power of a city is 5.
// Since it is not possible to obtain a larger power, we return 5.

// Example 2:

// Input: stations = [4,4,4,4], r = 0, k = 3
// Output: 4
// Explanation:
// It can be proved that we cannot make the minimum power of a city greater
// than 4.

// Constraints:

//     n == stations.length
//     1 <= n <= 105
//     0 <= stations[i] <= 105
//     0 <= r <= n - 1
//     0 <= k <= 109

#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
    int n;

  public:
    long long maxPower(std::vector<int> &stations, int range, int k) {
        namespace rng = std::ranges;
        n = stations.size();
        std::vector<long long> counts(n + 1);
        for (int i = 0; i < n; i++) {
            int l = std::max(0, i - range), r = std::min(n, i + range + 1);
            counts[l] += stations[i];
            counts[r] -= stations[i];
        }

        long long l = *rng::min_element(stations);
        long long r = rng::fold_left(stations, 0LL, std::plus{}) + k;
        long long result = 0;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (check(counts, k, range, m)) {
                result = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }

    bool check(std::vector<long long> &counts, int k, int range,
               long long val) {
        std::vector<long long> diffs = counts;
        long long sum = 0, rem = k;

        for (int i = 0; i < n; i++) {
            sum += diffs[i];
            if (sum < val) {
                long long add = val - sum;
                if (rem < add) {
                    return false;
                }
                rem -= add;
                int end = std::min(n, i + 2 * range + 1);
                diffs[end] -= add;
                sum += add;
            }
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::tuple<std::vector<int>, int, int>, long long>>
        tests = {
            {{{1, 2, 4, 5, 0}, 1, 2}, 5},
            {{{4, 4, 4, 4}, 0, 3}, 4},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxPower(std::get<0>(test), std::get<1>(test),
                                        std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
