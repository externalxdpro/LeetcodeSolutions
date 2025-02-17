// 1079. Letter Tile Possibilities
// Difficulty: Medium

// You have n  tiles, where each tile has one letter tiles[i] printed on it.

// Return the number of possible non-empty sequences of letters you can make
// using the letters printed on those tiles.

// Example 1:

// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB",
// "ABA", "BAA".

// Example 2:

// Input: tiles = "AAABBC"
// Output: 188

// Example 3:

// Input: tiles = "V"
// Output: 1

// Constraints:

//     1 <= tiles.length <= 7
//     tiles consists of uppercase English letters.

#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int numTilePossibilities(std::string &tiles) {
        std::unordered_set<std::string> sequences;
        std::vector<bool>               used(tiles.size());
        getSequences(tiles, "", used, sequences);
        return sequences.size() - 1;
    }

  private:
    void getSequences(std::string &tiles, std::string curr,
                      std::vector<bool>               &used,
                      std::unordered_set<std::string> &sequences) {
        if (sequences.contains(curr)) {
            return;
        }
        sequences.insert(curr);
        for (int i = 0; i < tiles.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                getSequences(tiles, curr + tiles[i], used, sequences);
                used[i] = false;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> tests = {
        {"AAB", 8},
        {"AAABBC", 188},
        {"V", 1},
    };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.numTilePossibilities(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
