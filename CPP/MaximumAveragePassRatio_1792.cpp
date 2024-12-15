// 1792. Maximum Average Pass Ratio
// Difficulty: Medium

// There is a school that has classes of students and each class will be having
// a final exam. You are given a 2D integer array classes, where classes[i] =
// [passi, totali]. You know beforehand that in the ith class, there are totali
// total students, but only passi number of students will pass the exam.

// You are also given an integer extraStudents. There are another extraStudents
// brilliant students that are guaranteed to pass the exam of any class they are
// assigned to. You want to assign each of the extraStudents students to a class
// in a way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class
// that will pass the exam divided by the total number of students of the class.
// The average pass ratio is the sum of pass ratios of all the classes divided
// by the number of the classes.

// Return the maximum possible average pass ratio after assigning the
// extraStudents students. Answers within 10-5 of the actual answer will be
// accepted.

// Example 1:

// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The
// average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

// Example 2:

// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485

// Constraints:

//     1 <= classes.length <= 105
//     classes[i].length == 2
//     1 <= passi <= totali <= 105
//     1 <= extraStudents <= 105

#include <fmt/ranges.h>
#include <queue>
#include <tuple>
#include <vector>

class Solution {
  public:
    double maxAverageRatio(const std::vector<std::vector<int>> &classes,
                           int                                  extraStudents) {
        std::priority_queue<std::tuple<double, int, int>> pq;
        for (std::vector c : classes) {
            pq.emplace(gain(c[0], c[1]), c[0], c[1]);
        }

        while (extraStudents--) {
            auto [g, passes, total] = pq.top();
            pq.pop();
            pq.emplace(gain(passes + 1, total + 1), passes + 1, total + 1);
        }

        double ratio = 0;
        while (!pq.empty()) {
            auto [_, passes, total] = pq.top();
            pq.pop();
            ratio += (double)(passes) / total;
        }

        return ratio / classes.size();
    }

  private:
    float gain(int passes, int total) {
        return (double)(passes + 1) / (total + 1) - (double)passes / total;
    }
};

int main(int argc, char *argv[]) {
    std::vector<
        std::pair<std::pair<std::vector<std::vector<int>>, int>, double>>
        tests = {
            {{{{1, 2}, {3, 5}, {2, 2}}, 2}, 0.7833333333333333},
            {{{{2, 4}, {3, 9}, {4, 5}, {2, 10}}, 4}, 0.5348484848484849},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.maxAverageRatio(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
