// 68. Text Justification
// Difficulty: Hard

// Given an array of strings words and a width maxWidth, format the text such
// that each line has exactly maxWidth characters and is fully (left and right)
// justified.
// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly maxWidth characters.
// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line does not divide evenly between words, the
// empty slots on the left will be assigned more spaces than the slots on the
// right.
// For the last line of text, it should be left-justified, and no extra space is
// inserted between words.
// Note:
//     A word is defined as a character sequence consisting of non-space
//     characters only. Each word's length is guaranteed to be greater than 0
//     and not exceed maxWidth. The input array words contains at least one
//     word.

// Example 1:
// Input: words = ["This", "is", "an", "example", "of", "text",
// "justification."], maxWidth = 16 Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

// Example 2:
// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth =
// 16 Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall be",
// because the last line must be left-justified instead of fully-justified. Note
// that the second line is also left-justified because it contains only one
// word.

// Example 3:
// Input: words =
// ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
// maxWidth = 20 Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

// Constraints:
//     1 <= words.length <= 300
//     1 <= words[i].length <= 20
//     words[i] consists of only English letters and symbols.
//     1 <= maxWidth <= 100
//     words[i].length <= maxWidth

#include <fmt/ranges.h>
#include <numeric>
#include <vector>

class Solution {
  public:
    std::vector<std::string> fullJustify(std::vector<std::string> &words,
                                         int                       maxWidth) {
        std::vector<std::vector<std::string>> lines;
        int                                   i = 0;
        while (i < words.size()) {
            int j;
            int len = 0;
            for (j = i; j < words.size(); j++) {
                len += words[j].size();
                if (len + j - i > maxWidth) {
                    break;
                }
            }
            lines.push_back(std::vector(words.begin() + i, words.begin() + j));
            i = j;
        }

        std::vector<std::string> result;
        for (int i = 0; i < lines.size() - 1; i++) {
            std::vector<std::string> line = lines[i];
            int                      len =
                std::accumulate(line.begin(), line.end(), std::string{}).size();
            int spaces = maxWidth - len;
            int sep =
                spaces / (line.size() > 1 ? line.size() - 1 : line.size());
            int extra = spaces -
                        sep * (line.size() > 1 ? line.size() - 1 : line.size());
            std::string newLine =
                line.front() + std::string(sep + (extra-- > 0), ' ');
            for (int j = 1; j < line.size(); j++) {
                newLine += line[j];
                if (newLine.size() < maxWidth) {
                    newLine += std::string(sep + (extra-- > 0), ' ');
                }
            }
            result.push_back(newLine);
        }
        std::string last = std::accumulate(
            lines.back().begin() + 1, lines.back().end(), lines.back().front(),
            [](auto a, auto b) { return a + ' ' + b; });
        result.push_back(last);
        for (int i = result.back().size(); i < maxWidth; i++) {
            result.back().push_back(' ');
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::pair<std::vector<std::string>, int>,
                          std::vector<std::string>>>
        tests = {
            {{{"This", "is", "an", "example", "of", "text", "justification."},
              16},
             {"This    is    an", "example  of text", "justification.  "}},
            {{{"What", "must", "be", "acknowledgment", "shall", "be"}, 16},
             {"What   must   be", "acknowledgment  ", "shall be        "}},
            {{{"Science", "is", "what", "we", "understand", "well", "enough",
               "to", "explain", "to", "a", "computer.", "Art", "is",
               "everything", "else", "we", "do"},
              20},
             {"Science  is  what we", "understand      well",
              "enough to explain to", "a  computer.  Art is",
              "everything  else  we", "do                  "}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.fullJustify(test.first, test.second);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
