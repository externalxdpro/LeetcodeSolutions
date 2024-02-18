// Difficulty: Hard
// You are given an integer n. There are n rooms numbered from 0 to n - 1.
// You are given a 2D integer array meetings where meetings[i] = [starti, endi]
// means that a meeting will be held during the half-closed time interval
// [starti, endi). All the values of starti are unique.

// Meetings are allocated to rooms in the following manner:
//     Each meeting will take place in the unused room with the lowest number.
//     If there are no available rooms, the meeting will be delayed until a room
//     becomes free. The delayed meeting should have the same duration as the
//     original meeting. When a room becomes unused, meetings that have an
//     earlier original start time should be given the room.

// Return the number of the room that held the most meetings. If there are
// multiple rooms, return the room with the lowest number.

// A half-closed interval [a, b) is the interval between a and b including a and
// not including b.

// Example 1:
// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
// Explanation:
// - At time 0, both rooms are not being used. The first meeting starts in room
// 0.
// - At time 1, only room 1 is not being used. The second meeting starts in
// room 1.
// - At time 2, both rooms are being used. The third meeting is delayed.
// - At time 3, both rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 1 finishes. The third meeting starts in room
// 1 for the time period [5,10).
// - At time 10, the meetings in both rooms finish. The fourth meeting starts in
// room 0 for the time period [10,11). Both rooms 0 and 1 held 2 meetings, so we
// return 0.

// Example 2:
// Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
// Output: 1
// Explanation:
// - At time 1, all three rooms are not being used. The first meeting starts in
// room 0.
// - At time 2, rooms 1 and 2 are not being used. The second meeting starts in
// room 1.
// - At time 3, only room 2 is not being used. The third meeting starts in
// room 2.
// - At time 4, all three rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 2 finishes. The fourth meeting starts in
// room 2 for the time period [5,10).
// - At time 6, all three rooms are being used. The fifth meeting is delayed.
// - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts
// in room 1 for the time period [10,12). Room 0 held 1 meeting while rooms 1
// and 2 each held 2 meetings, so we return 1.

// Constraints:
//     1 <= n <= 100
//     1 <= meetings.length <= 10^5
//     meetings[i].length == 2
//     0 <= starti < endi <= 5 * 10^5
//     All the values of starti are unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
  public:
    int mostBooked(int n, std::vector<std::vector<int>> &meetings) {
        if (n == 1) {
            return 0;
        }

        std::ranges::sort(meetings);

        std::vector<bool>      taken(n);
        std::vector<long long> counts(n);
        std::priority_queue<std::pair<long long, long long>,
                            std::vector<std::pair<long long, long long>>,
                            std::greater<std::pair<long long, long long>>>
            currTaken;

        for (int i = 0; i < meetings.size(); i++) {
            while (!currTaken.empty() &&
                   currTaken.top().first <= meetings[i][0]) {
                taken[currTaken.top().second] = false;
                currTaken.pop();
            }

            int takenI = std::ranges::find(taken, false) - taken.begin();
            if (takenI < n) {
                taken[takenI] = true;
                counts[takenI]++;
                currTaken.emplace(meetings[i][1], takenI);
            } else {
                std::pair<long long, long long> curr = currTaken.top();
                currTaken.pop();
                counts[curr.second]++;
                currTaken.emplace(meetings[i][1] + curr.first - meetings[i][0],
                                  curr.second);
            }
        }

        return std::ranges::max_element(counts) - counts.begin();
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<int, std::vector<std::vector<int>>>, int>>
        tests = {
            {{2, {{0, 10}, {1, 5}, {2, 7}, {3, 4}}}, 0},
            {{3, {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}}}, 1},
            {{4, {{18, 19}, {3, 12}, {17, 19}, {2, 13}, {7, 10}}}, 0},
            {{1, {{0, 1}, {2, 17}, {13, 16}, {1, 12}, {9, 15}}}, 0},
            {{4, {{19, 20}, {14, 15}, {13, 14}, {11, 20}}}, 1},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        fmt::print("{}: ", test);
        auto result = solution.mostBooked(test.first, test.second);
        fmt::print("{} {}\n", result, result == ans ? "✅" : "❌");
    }

    return 0;
}
