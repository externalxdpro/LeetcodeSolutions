// Difficulty: Easy
// You are given a string s of even length. Split this string into two halves of
// equal lengths, and let a be the first half and b be the second half.

// Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
// 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
// lowercase letters.

// Return true if a and b are alike. Otherwise, return false.

// Example 1:
// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
// Therefore, they are alike.

// Example 2:
// Input: s = "textbook"
// Output: false
// Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
// Therefore, they are not alike. Notice that the vowel o is counted twice.

// Constraints:
//     2 <= s.length <= 1000
//     s.length is even.
//     s consists of uppercase and lowercase letters.

#include <fmt/ranges.h>
#include <unordered_set>
#include <vector>

bool halvesAreAlike(std::string s) {
    std::unordered_set<int> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
    auto a = s.substr(0, s.size() / 2);
    auto b = s.substr(s.size() / 2);
    int numA = 0;
    int numB = 0;

    for (int i = 0; i < s.size() / 2; i++) {
        if (vowels.contains(a[i])) {
            numA++;
        }
        if (vowels.contains(b[i])) {
            numB++;
        }
    }

    return numA == numB;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, bool>> tests = {
        {"book", true},
        {"textbook", false},
    };

    for (const auto &[test, ans] : tests) {
        bool result = halvesAreAlike(test);
        fmt::print("{}: {} {}\n", test, result, result == ans ? "✅" : "❌");
    }

    return 0;
}
