// 2818. Apply Operations to Maximize Score
// Difficulty: Hard

// You are given an array nums of n positive integers and an integer k.

// Initially, you start with a score of 1. You have to maximize your score by
// applying the following operation at most k times:

//     Choose any non-empty subarray nums[l, ..., r] that you haven't chosen
//     previously. Choose an element x of nums[l, ..., r] with the highest prime
//     score. If multiple such elements exist, choose the one with the smallest
//     index. Multiply your score by x.

// Here, nums[l, ..., r] denotes the subarray of nums starting at index l and
// ending at the index r, both ends being inclusive.

// The prime score of an integer x is equal to the number of distinct prime
// factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3
// * 5 * 5.

// Return the maximum possible score after applying at most k operations.

// Since the answer may be large, return it modulo 109 + 7.

// Example 1:

// Input: nums = [8,3,9,3,8], k = 2
// Output: 81
// Explanation: To get a score of 81, we can apply the following operations:
// - Choose subarray nums[2, ..., 2]. nums[2] is the only element in this
// subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9
// = 9.
// - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime
// score of 1, but nums[2] has the smaller index. Hence, we multiply the score
// by nums[2]. The score becomes 9 * 9 = 81. It can be proven that 81 is the
// highest score one can obtain.

// Example 2:

// Input: nums = [19,12,14,6,10,18], k = 3
// Output: 4788
// Explanation: To get a score of 4788, we can apply the following operations:
// - Choose subarray nums[0, ..., 0]. nums[0] is the only element in this
// subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19
// = 19.
// - Choose subarray nums[5, ..., 5]. nums[5] is the only element in this
// subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18
// = 342.
// - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime
// score of 2, but nums[2] has the smaller index. Hence, we multipy the score by
// nums[2]. The score becomes 342 * 14 = 4788. It can be proven that 4788 is the
// highest score one can obtain.

// Constraints:

//     1 <= nums.length == n <= 105
//     1 <= nums[i] <= 105
//     1 <= k <= min(n * (n + 1) / 2, 109)

#include <algorithm>
#include <fmt/ranges.h>
#include <stack>
#include <vector>

class Solution {
    const int MOD = 1e9 + 7;

  public:
    int maximumScore(std::vector<int> &nums, int k) {
        std::vector<int> scores(nums.size());
        int              max    = *std::ranges::max_element(nums);
        std::vector<int> primes = getPrimes(max);
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = 0; j < primes.size() && primes[j] * primes[j] <= num;
                 j++) {
                if (num % primes[j] != 0) {
                    continue;
                }
                scores[i]++;
                while (num % primes[j] == 0) {
                    num /= primes[j];
                }
            }
            if (num > 1) {
                scores[i]++;
            }
        }

        std::vector<int> next(nums.size(), nums.size());
        std::vector<int> prev(nums.size(), -1);
        std::stack<int>  stk;
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && scores[stk.top()] < scores[i]) {
                int top = stk.top();
                stk.pop();
                next[top] = i;
            }
            if (!stk.empty()) {
                prev[i] = stk.top();
            }
            stk.push(i);
        }

        std::vector<long long> subs(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            subs[i] = (long long)(next[i] - i) * (i - prev[i]);
        }
        std::vector<std::pair<int, int>> sorted(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sorted[i] = {i, nums[i]};
        }
        std::ranges::sort(sorted, [](auto a, auto b) {
            return a.second == b.second ? a.first > b.first
                                        : a.second > b.second;
        });
        long long result = 1;
        int       curr   = 0;
        while (k) {
            auto [i, num] = sorted[curr++];
            long long ops = std::min((long long)k, subs[i]);
            result        = (result * pow(num, ops)) % MOD;
            k -= ops;
        }
        return result;
    }

  private:
    std::vector<int> getPrimes(int n) {
        std::vector<bool> isPrime(n + 1, true);
        std::vector<int>  result;

        for (int i = 2; i <= n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            result.push_back(i);
            for (long long j = (long long)i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        return result;
    }

    long long pow(long long base, long long exp) {
        long long result = 1;
        while (exp) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<int>, int>, int>> tests = {
        {{{8, 3, 9, 3, 8}, 2}, 81},
        {{{19, 12, 14, 6, 10, 18}, 3}, 4788},
        {{{3289, 2832, 14858, 22011}, 6}, 256720975},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maximumScore(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
