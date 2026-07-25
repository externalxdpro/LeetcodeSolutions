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
      public:
        struct Node {
            std::unique_ptr<Node> children[26];
            bool end = false;
        };

        Node root;

        Trie() = default;

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
    };

    Trie words;

  public:
    std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                       std::vector<std::string> &words) {
        for (std::string &word : words) {
            this->words.insert(word);
        }

        std::unordered_set<std::string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                recurse(board, i, j, &this->words.root, "", result);
            }
        }
        return std::vector(result.begin(), result.end());
    }

  private:
    void recurse(std::vector<std::vector<char>> &board, int i, int j,
                 Trie::Node *node, std::string word,
                 std::unordered_set<std::string> &result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == '.') {
            return;
        }

        Trie::Node *newNode = node->children[board[i][j] - 'a'].get();
        if (newNode == nullptr) {
            return;
        }
        char c = board[i][j];
        board[i][j] = '.';

        word.push_back(c);
        if (newNode->end) {
            result.insert(word);
        }

        recurse(board, i + 1, j, newNode, word, result);
        recurse(board, i - 1, j, newNode, word, result);
        recurse(board, i, j + 1, newNode, word, result);
        recurse(board, i, j - 1, newNode, word, result);

        board[i][j] = c;
        word.pop_back();
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
