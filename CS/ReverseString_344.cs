namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Write a function that reverses a string. The input string is given as an array of characters s.
    // You must do this by modifying the input array in-place with O(1) extra memory.

    // Example 1:
    // Input: s = ["h","e","l","l","o"]
    // Output: ["o","l","l","e","h"]

    // Example 2:
    // Input: s = ["H","a","n","n","a","h"]
    // Output: ["h","a","n","n","a","H"]

    // Constraints:
    // 1 <= s.length <= 10^5
    // s[i] is a printable ascii character.

    public class ReverseString_344
    {
        public void ReverseString(char[] s)
        {
            int left = 0;
            int right = s.Length - 1;

            while (left < right)
            {
                char temp = s[right];
                s[right] = s[left];
                s[left] = temp;

                left++;
                right--;
            }
        }
    }
}
