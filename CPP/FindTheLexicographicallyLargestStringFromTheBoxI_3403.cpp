// 3403. Find the Lexicographically Largest String From the Box I
// Difficulty: Medium

// You are given a string word, and an integer numFriends.

// Alice is organizing a game for her numFriends friends. There are multiple
// rounds in the game, where in each round:

//     word is split into numFriends non-empty strings, such that no previous
//     round has had the exact same split. All the split words are put into a
//     box.

// Find the

// string from the box after all the rounds are finished.

// Example 1:

// Input: word = "dbca", numFriends = 2

// Output: "dbc"

// Explanation:

// All possible splits are:

//     "d" and "bca".
//     "db" and "ca".
//     "dbc" and "a".

// Example 2:

// Input: word = "gggg", numFriends = 4

// Output: "g"

// Explanation:

// The only possible split is: "g", "g", "g", and "g".

// Constraints:

//     1 <= word.length <= 5 * 103
//     word consists only of lowercase English letters.
//     1 <= numFriends <= word.length

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::string answerString(std::string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        std::string result;
        for (int i = 0; i < word.size(); i++) {
            result = std::max(
                result, word.substr(i, std::min(n - numFriends + 1, n - i)));
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::string, int>, std::string>> tests = {
        {{"dbca", 2}, "dbc"},
        {{"gggg", 4}, "g"},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.answerString(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
