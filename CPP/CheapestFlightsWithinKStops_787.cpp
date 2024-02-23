#include <algorithm>
#include <fmt/ranges.h>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights,
                          int src, int dst, int k) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> adj;
        std::vector<int> dists(n, INT_MAX);
        dists[src] = 0;

        for (auto i : flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        std::queue<std::pair<int, int>> q;
        q.push({src, 0});
        k++;
        while (k--) {
            int size = q.size();
            while (size--) {
                int currPrice = q.front().second;
                for (auto i : adj[q.front().first]) {
                    int newPrice = i.second + currPrice;
                    if (newPrice < dists[i.first]) {
                        dists[i.first] = newPrice;
                        q.push({i.first, newPrice});
                    }
                }
                q.pop();
            }
        }

        int result = dists[dst];
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::tuple<int, std::vector<std::vector<int>>, int, int, int>, int>>
        tests = {
            {{4,
              {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}},
              0,
              3,
              1},
             700},
            {{3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 1}, 200},
            {{3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 0}, 500},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.findCheapestPrice(
            std::get<0>(test), std::get<1>(test), std::get<2>(test),
            std::get<3>(test), std::get<4>(test));
        fmt::print("{} {}: {}\n", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
