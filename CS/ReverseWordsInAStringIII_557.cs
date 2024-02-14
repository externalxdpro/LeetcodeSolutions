namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

    // Example 1:
    // Input: s = "Let's take LeetCode contest"
    // Output: "s'teL ekat edoCteeL tsetnoc"

    // Example 2:
    // Input: s = "God Ding"
    // Output: "doG gniD"

    // Constraints:
    // 1 <= s.length <= 5 * 104
    // s contains printable ASCII characters.
    // s does not contain any leading or trailing spaces.
    // There is at least one word in s.
    // All the words in s are separated by a single space.

    public class ReverseWordsInAStringIII_557
    {
        public string ReverseWords(string s)
        {
            string[] words = s.Split(" ");

            for (int i = 0; i < words.Length; i++)
            {
                char[] letters = words[i].ToCharArray();
                int left = 0;
                int right = letters.Length - 1;

                while (left < right)
                {
                    letters[right] = words[i][left];
                    letters[left] = words[i][right];

                    left++;
                    right--;
                }

                words[i] = String.Join("", letters);
            }

            return String.Join(" ", words);
        }
    }
}
