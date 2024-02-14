#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

// char repeatedCharacter(std::string s) {
//     std::unordered_set<char> set;

//     for (char i : s) {
//         if (set.contains(i)) {
//             return i;
//         }
//         set.insert(i);
//     }

//     return ' ';
// }

char repeatedCharacter(std::string s) {
    int map[26] = {0};

    for (char i : s) {
        if (map[i - 'a']) {
            return i;
        }
        map[i - 'a'] = 1;
    }

    return ' ';
}

int main(int argc, char *argv[]) {
    std::vector<std::string> tests = {
        "abccbaacz",
        "abcdd",
    };

    for (auto test : tests) {
        fmt::print("{}: {}\n", test, repeatedCharacter(test));
    }

    return 0;
}
