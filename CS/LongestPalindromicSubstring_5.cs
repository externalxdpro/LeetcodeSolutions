namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given a string s, return the longest palindromic substring in s.

    // Example 1:
    // Input: s = "babad"
    // Output: "bab"
    // Explanation: "aba" is also a valid answer.

    // Example 2:
    // Input: s = "cbbd"
    // Output: "bb"
    
    // Constraints:
    // 1 <= s.length <= 1000
    // s consist of only digits and English letters.

    public class LongestPalindromicSubstring_5
    {
        public bool CheckPalindrome(string substring)
        {
            int start = 0;
            int end = substring.Length - 1;

            while (end >= start)
            {
                if (substring[start] != substring[end]) return false;

                start++;
                end--;
            }

            return true;
        }

        public string LongestPalindrome(string s)
        {
            // Works, but too slow for Leetcode
            // string result = "";

            // for (int i = 0; i < s.Length; i++)
            // {
            //     string temp = "" + s[i];

            //     for (int j = i; j < s.Length; j++)
            //     {
            //         if (j != i) temp += s[j];
            //         if (s[i] == s[j])
            //         {
            //             if (temp == MakePalindrome(temp) && temp.Length > result.Length)
            //             {
            //                 result = temp;
            //             }
            //         }
            //     }
            // }

            // return result;

            int start = 0;
            string result = "";
            while (start < s.Length)
            {
                for (int i = s.Length - 1; i >= start; i--)
                {
                    if (s[start] == s[i])
                    {
                        string temp = s.Substring(start, i - start + 1);

                        if (CheckPalindrome(temp) && temp.Length > result.Length)
                        {
                            result = temp;
                            break;
                        }
                    }
                }

                start++;
            }

            return result;
        }
    }
}