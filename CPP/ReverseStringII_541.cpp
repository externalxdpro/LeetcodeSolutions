#include <bits/stdc++.h>

// std::string rev(std::string s)
// {
//     std::string result = "";
//     for (int i = s.length() - 1; i >= 0; i--)
//     {
//         result += s[i];
//     }

//     return result;
// }

std::string reverseStr(std::string s, int k)
{
    std::string result = "";
    int count = 0;
    for (int i = 0; i < s.length(); i += k)
    {
        std::string substring = s.substr(i, k);
        if (count % 2 == 0)
        {
            std::reverse(substring.begin(), substring.end());
            result += substring;
        }
        else result += s.substr(i, k);
        count++;
    }

    return result;
}


int main()
{
    std::cout << reverseStr("abcdefg", 2) << "\n";
    std::cout << reverseStr("abcd", 2) << "\n";
    std::cout << reverseStr("abcdefgh", 3) << "\n";
}
