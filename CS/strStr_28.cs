namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Implement strStr().
    // Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
    // Clarification:
    // What should we return when needle is an empty string? This is a great question to ask during an interview.
    // For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

    // Example 1:
    // Input: haystack = "hello", needle = "ll"
    // Output: 2

    // Example 2:
    // Input: haystack = "aaaaa", needle = "bba"
    // Output: -1

    // Constraints:
    // 1 <= haystack.length, needle.length <= 104
    // haystack and needle consist of only lowercase English characters.

    class strStr_28
    {
        public int StrStr(string haystack, string needle)
        {
            if (needle.Length == 0)
            {
                return 0;
            }

            int i = 0;

            while (haystack.Length - i >= needle.Length)
            {
                while (i < haystack.Length && needle[0] != haystack[i])
                {
                    i++;
                }

                int j = 0;
                int len = 0;
                int result = i;

                while (j < needle.Length && i < haystack.Length && haystack[i] == needle[j])
                {
                    i++;
                    j++;
                    len++;
                }

                if (len == needle.Length)
                {
                    return result;
                }
                else
                {
                    i -= len - 1;
                    j -= len - 1;
                }
            }

            return -1;
        }
    }
}