#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p)
{

    return true;
}

int main()
{
    vector<pair<string, string>> tests = {{"aa", "a"}, {"aa", "a*"}, {"ab", ".*"}};

    for (pair<string, string> test : tests)
        cout << isMatch(test.first, test.second) << endl;;

    return 0;
}
