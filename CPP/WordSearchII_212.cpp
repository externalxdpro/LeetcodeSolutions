// 212. Word Search II
// Difficulty: Hard

// Given an m x n board of characters and a list of strings words, return all
// words on the board.

// Each word must be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring. The same
// letter cell may not be used more than once in a word.

// Example 1:

// Input: board =
// [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
// words = ["oath","pea","eat","rain"] Output: ["eat","oath"] Example 2:

// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <memory>
#include <unordered_set>
#include <vector>

class Solution {
    class Trie {
        struct Node {
            std::unique_ptr<Node> children[26];
            bool end = false;
        };

      public:
        Node root;

        Trie() : root(Node()) {}

        void insert(const std::string &word) {
            Node *curr = &root;
            for (char c : word) {
                if (curr->children[c - 'a'] == nullptr) {
                    curr->children[c - 'a'] = std::make_unique<Node>();
                }
                curr = curr->children[c - 'a'].get();
            }
            curr->end = true;
        }

        bool search(const std::string &word) {
            Node *curr = &root;
            for (char c : word) {
                if (curr->children[c - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[c - 'a'].get();
            }
            return curr->end;
        }

        bool startsWith(const std::string &prefix) {
            Node *curr = &root;
            for (char c : prefix) {
                if (curr->children[c - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[c - 'a'].get();
            }
            return true;
        }
    };

    Trie words;

  public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                       std::vector<std::string> &words) {
        for (std::string &word : words) {
            this->words.insert(word);
        }

        std::unordered_set<std::string> result;
        std::vector<std::vector<bool>> seen(
            board.size(), std::vector(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                recurse(board, i, j, "", seen, result);
            }
        }
        return std::vector(result.begin(), result.end());
    }

  private:
    void recurse(std::vector<std::vector<char>> &board, int i, int j,
                 std::string curr, std::vector<std::vector<bool>> &seen,
                 std::unordered_set<std::string> &result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            seen[i][j]) {
            return;
        }

        std::string newWord = curr + board[i][j];
        if (!words.startsWith(newWord)) {
            return;
        }
        seen[i][j] = true;

        if (words.search(newWord)) {
            result.insert(newWord);
        }

        recurse(board, i + 1, j, newWord, seen, result);
        recurse(board, i - 1, j, newWord, seen, result);
        recurse(board, i, j + 1, newWord, seen, result);
        recurse(board, i, j - 1, newWord, seen, result);

        seen[i][j] = false;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<
        std::pair<std::vector<std::vector<char>>, std::vector<std::string>>,
        std::vector<std::string>>>
        tests = {
            {{{{'o', 'a', 'a', 'n'},
               {'e', 't', 'a', 'e'},
               {'i', 'h', 'k', 'r'},
               {'i', 'f', 'l', 'v'}},
              {"oath", "pea", "eat", "rain"}},
             {"eat", "oath"}},
            {{{{'a', 'b'}, {'c', 'd'}}, {"abcb"}}, {}},
            {{{{'a', 'a'}}, {"aaa"}}, {}},
        };

    for (auto &[test, ans] : tests) {
        Solution solution;
        auto result = solution.findWords(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
