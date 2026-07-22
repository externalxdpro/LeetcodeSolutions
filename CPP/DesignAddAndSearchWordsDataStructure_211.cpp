// 211. Design Add and Search Words Data Structure
// Difficulty: Medium

// Design a data structure that supports adding new words and finding if a
// string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure
// that matches word or false otherwise. word may contain dots '.' where dots
// can be matched with any letter.

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class WordDictionary {
    struct Node {
        Node *children[26];
        bool end = false;
    };

    Node *root;

  public:
    WordDictionary() : root(new Node()) {}

    void addWord(const std::string &word) {
        Node *curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
        }
        curr->end = true;
    }

    bool search(const std::string &word) { return searchRec(word, 0, root); }

  private:
    bool searchRec(const std::string &word, size_t i, Node *curr) {
        if (curr == nullptr) {
            return false;
        }
        if (i == word.size()) {
            return curr->end;
        }
        if (word[i] == '.') {
            for (size_t j = 0; j < 26; j++) {
                if (searchRec(word, i + 1, curr->children[j])) {
                    return true;
                }
            }
            return false;
        }
        return searchRec(word, i + 1, curr->children[word[i] - 'a']);
    }
};

int main(int argc, char *argv[]) {
    // std::vector<std::pair<>> tests = {};

    // for (auto &[test, ans] : tests) {
    //     Solution solution;
    //     auto result = solution.funcName(test);
    //     fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    // }

    return 0;
}
