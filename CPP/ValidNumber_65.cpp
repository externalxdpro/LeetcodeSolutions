#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <vector>

bool isDigit(char c) {
    if (c - 48 >= 0 && c - 48 <= 9) {
        return true;
    }
    return false;
}

bool isNumber(std::string s) {
    bool foundDot = false;
    bool foundE = false;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isDigit(c)) {
            continue;
        } else if (c == '.') {
            if (foundE || foundDot) {
                return false;
            }
            foundDot = true;

            if ((s.size() == 1)) {
                return false;
            }
            if ((i != 0 && isDigit(s[i - 1])) ||
                (i < s.size() - 1 && isDigit(s[i + 1]))) {
                continue;
            }
            return false;
        } else if (c == 'e' || c == 'E') {
            if (foundE) {
                return false;
            }
            foundE = true;

            if (i == 0 || (!isDigit(s[i - 1]) && s[i - 1] != '.')) {
                return false;
            }
            if (i == s.size() - 1 ||
                (!isDigit(s[i + 1]) && s[i + 1] != '-' && s[i + 1] != '+')) {
                return false;
            }
        } else if (c == '-' || c == '+') {
            if (i == s.size() - 1) {
                return false;
            }
            if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string, bool>> tests = {
        {"0", true},    {"e", false},     {".", false},  {"123.E4", true},
        {".1", true},   {"..", false},    {"e9", false}, {"inf", false},
        {".1.", false}, {"1e2e3", false}, {"-1.", true}, {"-1e-2", true},
        {"6+1", false}, {"6e6.5", false}};

    for (auto [test, ans] : tests) {
        bool result = isNumber(test);
        std::cout << std::format("{}: {} {}\n", test, result,
                                 result == ans ? "✅" : "❌");
    }

    return 0;
}
