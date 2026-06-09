// 126. Word Ladder II
// Difficulty: Hard

// A transformation sequence from word beginWord to word endWord using a
// dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
// such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to
// be in wordList. sk == endWord Given two words, beginWord and endWord, and a
// dictionary wordList, return all the shortest transformation sequences from
// beginWord to endWord, or an empty list if no such sequence exists. Each
// sequence should be returned as a list of the words [beginWord, s1, s2, ...,
// sk].

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log","cog"] Output:
// [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList =
// ["hot","dot","dog","lot","log"] Output: [] Explanation: The endWord "cog" is
// not in wordList, therefore there is no valid transformation sequence.

// Constraints:

// 1 <= beginWord.length <= 5
// endWord.length == beginWord.length
// 1 <= wordList.length <= 500
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.
// The sum of all shortest transformation sequences does not exceed 105.

#include <algorithm>
#include <fmt/ranges.h>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>>
    findLadders(std::string beginWord, std::string endWord,
                std::vector<std::string> &wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) ==
            wordList.end()) {
            return {};
        }

        std::unordered_map<std::string, std::vector<std::string>> tree =
            getTree(beginWord, endWord, wordList);
        return getPaths(beginWord, endWord, tree);
    }

  private:
    std::unordered_map<std::string, std::vector<std::string>>
    getTree(std::string &beginWord, std::string &endWord,
            std::vector<std::string> &wordList) {
        std::unordered_map<std::string, std::vector<std::string>> adj;
        for (std::string &word : wordList) {
            for (size_t i = 0; i < word.size(); ++i) {
                std::string pattern =
                    word.substr(0, i) + '.' + word.substr(i + 1);
                adj[pattern].push_back(word);
            }
        }

        std::unordered_map<std::string, std::vector<std::string>> tree{
            {beginWord, {}}};
        bool found = false;
        std::queue<std::string> q{{beginWord}};

        while (q.size() && !found) {
            size_t sz = q.size();
            std::unordered_map<std::string, std::vector<std::string>> currLevel;

            for (size_t i = 0; i < sz; ++i) {
                std::string word = q.front();
                q.pop();

                for (size_t i = 0; i < word.size(); i++) {
                    std::string pattern =
                        word.substr(0, i) + '.' + word.substr(i + 1);

                    for (std::string &next : adj[pattern]) {
                        if (next == endWord) {
                            found = true;
                        }
                        if (!tree.contains(next)) {
                            if (!currLevel.contains(next)) {
                                currLevel[next] = {word};
                                q.push(next);
                            } else {
                                currLevel[next].push_back(word);
                            }
                        }
                    }
                }
            }

            tree.insert(currLevel.begin(), currLevel.end());
        }

        return tree;
    }

    std::vector<std::vector<std::string>>
    getPaths(std::string &beginWord, std::string &endWord,
             std::unordered_map<std::string, std::vector<std::string>> &tree) {
        std::function<std::vector<std::vector<std::string>>(std::string &)>
            dfs = [&](std::string &word)
            -> std::vector<std::vector<std::string>> {
            if (word == beginWord) {
                return {{beginWord}};
            }
            if (!tree.contains(word)) {
                return {};
            }

            std::vector<std::vector<std::string>> result;
            std::vector<std::string> parents = tree[word];
            for (std::string &parent : parents) {
                auto dfsParent = dfs(parent);
                result.insert(result.end(), dfsParent.begin(), dfsParent.end());
            }
            for (std::vector<std::string> &r : result) {
                r.push_back(word);
            }

            return result;
        };
        return dfs(endWord);
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::tuple<std::string, std::string, std::vector<std::string>>,
        std::vector<std::vector<std::string>>>>
        tests = {
            {{"hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}},
             {{"hit", "hot", "dot", "dog", "cog"},
              {"hit", "hot", "lot", "log", "cog"}}},
            {{"hit", "cog", {"hot", "dot", "dog", "lot", "log"}}, {}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findLadders(std::get<0>(test), std::get<1>(test),
                                           std::get<2>(test));
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
