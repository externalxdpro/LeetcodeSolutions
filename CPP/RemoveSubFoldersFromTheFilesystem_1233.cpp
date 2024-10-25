// 1233. Remove Sub-Folders from the Filesystem
// Difficulty: Medium

// Given a list of folders folder, return the folders after removing all
// sub-folders in those folders. You may return the answer in any order.

// If a folder[i] is located within another folder[j], it is called a sub-folder
// of it. A sub-folder of folder[j] must start with folder[j], followed by a
// "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a
// sub-folder of "/a/b/c".

// The format of a path is one or more concatenated strings of the form: '/'
// followed by one or more lowercase English letters.

//     For example, "/leetcode" and "/leetcode/problems" are valid paths while
//     an empty string and "/" are not.

// Example 1:

// Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
// Output: ["/a","/c/d","/c/f"]
// Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of
// folder "/c/d" in our filesystem.

// Example 2:

// Input: folder = ["/a","/a/b/c","/a/b/d"]
// Output: ["/a"]
// Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are
// subfolders of "/a".

// Example 3:

// Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
// Output: ["/a/b/c","/a/b/ca","/a/b/d"]

// Constraints:

//     1 <= folder.length <= 4 * 104
//     2 <= folder[i].length <= 100
//     folder[i] contains only lowercase letters and '/'.
//     folder[i] always starts with the character '/'.
//     Each folder name is unique.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class Solution {
  public:
    std::vector<std::string>
    removeSubfolders(std::vector<std::string> &folder) {
        std::ranges::sort(folder);
        std::vector<std::string> result;
        result.reserve(folder.size());

        int i;
        for (i = 0; i < folder.size(); i++) {
            result.push_back(folder[i]);
            for (i = i + 1; i < folder.size(); i++) {
                if (!folder[i].starts_with(result.back() + '/')) {
                    i--;
                    break;
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::vector<std::string>, std::vector<std::string>>>
        tests = {
            {{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}, {"/a", "/c/d", "/c/f"}},
            {{"/a", "/a/b/c", "/a/b/d"}, {"/a"}},
            {{"/a/b/c", "/a/b/ca", "/a/b/d"}, {"/a/b/c", "/a/b/ca", "/a/b/d"}},
        };

    Solution solution;
    for (auto &[test, ans] : tests) {
        auto result = solution.removeSubfolders(test);
        fmt::println("{} {}: {}", result == ans ? "✅" : "❌", test, result);
    }

    return 0;
}
