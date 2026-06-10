// 127. Word Ladder
// Difficulty: Hard

// A transformation sequence from word beginWord to word endWord using a
// dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
// such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to
// be in wordList. sk == endWord Given two words, beginWord and endWord, and a
// dictionary wordList, return the number of words in the shortest
// transformation sequence from beginWord to endWord, or 0 if no such sequence
// exists.

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log","cog"] Output: 5 Explanation: One shortest
// transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is
// 5 words long. Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log"] Output: 0 Explanation: The endWord "cog" is
// not in wordList, therefore there is no valid transformation sequence.

// Constraints:

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int ladderLength(std::string beginWord, std::string endWord,
                     std::vector<std::string> &wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(),
                                                wordList.end());
        if (!wordSet.contains(endWord)) {
            return 0;
        }

        std::queue<std::string> q{{beginWord}};
        int result = 1;

        while (!q.empty()) {
            size_t sz = q.size();
            while (sz--) {
                std::string word = q.front();
                q.pop();
                if (word == endWord) {
                    return result;
                }

                for (size_t i = 0; i < word.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        std::string temp = word;
                        temp[i] = c;

                        if (wordSet.contains(temp) && wordSet.contains(temp)) {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
            result++;
        }

        return 0;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::tuple<std::string, std::string, std::vector<std::string>>, int>>
        tests = {
            {{"hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}}, 5},
            {{"hit", "cog", {"hot", "dot", "dog", "lot", "log"}}, 0},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.ladderLength(
            std::get<0>(test), std::get<1>(test), std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
