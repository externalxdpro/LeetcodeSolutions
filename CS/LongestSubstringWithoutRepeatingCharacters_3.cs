namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Given a string s, find the length of the longest substring without repeating characters.

    // Example 1:
    // Input: s = "abcabcbb"
    // Output: 3
    // Explanation: The answer is "abc", with the length of 3.

    // Example 2:
    // Input: s = "bbbbb"
    // Output: 1
    // Explanation: The answer is "b", with the length of 1.

    // Example 3:
    // Input: s = "pwwkew"
    // Output: 3
    // Explanation: The answer is "wke", with the length of 3.
    // Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

    // Constraints:
    // 0 <= s.length <= 5 * 104
    // s consists of English letters, digits, symbols and spaces.
    public class LongestSubstringWithoutRepeatingCharacters_3
    {
        public int LengthOfLongestSubstring(string s)
        {
            string result = "";

            for (int i = 0; i < s.Length; i++)
            {
                string temp = "" + s[i];

                for (int j = i + 1; j < s.Length; j++)
                {
                    if (temp.IndexOf(s[j]) < 0)
                    {
                        temp += s[j];
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }

                if (result.Length < temp.Length)
                    {
                        result = temp;
                    }
            }

            return result.Length;
        }
    }
}