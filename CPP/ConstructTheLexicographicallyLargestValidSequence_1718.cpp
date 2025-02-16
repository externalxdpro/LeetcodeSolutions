// 1718. Construct the Lexicographically Largest Valid Sequence
// Difficulty: Medium

// Given an integer n, find a sequence that satisfies all of the following:

//     The integer 1 occurs once in the sequence.
//     Each integer between 2 and n occurs twice in the sequence.
//     For every integer i between 2 and n, the distance between the two
//     occurrences of i is exactly i.

// The distance between two numbers on the sequence, a[i] and a[j], is the
// absolute difference of their indices, |j - i|.

// Return the lexicographically largest sequence. It is guaranteed that under
// the given constraints, there is always a solution.

// A sequence a is lexicographically larger than a sequence b (of the same
// length) if in the first position where a and b differ, sequence a has a
// number greater than the corresponding number in b. For example, [0,1,9,0] is
// lexicographically larger than [0,1,5,6] because the first position they
// differ is at the third number, and 9 is greater than 5.

// Example 1:

// Input: n = 3
// Output: [3,1,2,3,2]
// Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the
// lexicographically largest valid sequence.

// Example 2:

// Input: n = 5
// Output: [5,3,1,4,3,5,2,4,2]

// Constraints:

//     1 <= n <= 20

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<int> constructDistancedSequence(int n) {
        std::vector<int>  result(n * 2 - 1);
        std::vector<bool> used(n + 1, false);
        find(n, 0, result, used);

        return result;
    }

  private:
    bool find(int n, int curr, std::vector<int> &result,
              std::vector<bool> &used) {
        if (curr == result.size()) {
            return true;
        }
        if (result[curr] != 0) {
            return find(n, curr + 1, result, used);
        }
        for (int next = n; next >= 1; next--) {
            if (used[next]) {
                continue;
            }
            used[next]   = true;
            result[curr] = next;
            if (next == 1) {
                if (find(n, curr + 1, result, used)) {
                    return true;
                }
            } else if (curr + next < result.size() &&
                       result[curr + next] == 0) {
                result[curr + next] = next;
                if (find(n, curr + 1, result, used)) {
                    return true;
                }
                result[curr + next] = 0;
            }
            result[curr] = 0;
            used[next]   = false;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<int, std::vector<int>>> tests = {
        {3, {3, 1, 2, 3, 2}}, {5, {5, 3, 1, 4, 3, 5, 2, 4, 2}}};

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.constructDistancedSequence(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
