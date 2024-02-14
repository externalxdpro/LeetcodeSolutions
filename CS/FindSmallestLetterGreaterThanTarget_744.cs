namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

    // Note that the letters wrap around.
    // For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.

    // Example 1:
    // Input: letters = ["c","f","j"], target = "a"
    // Output: "c"

    // Example 2:
    // Input: letters = ["c","f","j"], target = "c"
    // Output: "f"
    
    // Example 3:
    // Input: letters = ["c","f","j"], target = "d"
    // Output: "f"
    

    // Constraints:
    // 2 <= letters.length <= 104
    // letters[i] is a lowercase English letter.
    // letters is sorted in non-decreasing order.
    // letters contains at least two different characters.
    // target is a lowercase English letter.

    public class FindSmallestLetterGreaterThanTarget_744
    {
        public char NextGreatestLetter(char[] letters, char target)
        {
            int left = 0;
            int right = letters.Length - 1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                if (letters[mid] == target)
                {
                    left = mid + 1;
                    try
                    {
                        while (letters[left] == target) left++;
                    }
                    catch (System.IndexOutOfRangeException)
                    {
                        break;
                    }

                    if (letters[left] == target && left >= letters.Length - 1)
                        return letters[0];
                    break;
                }
                else if (letters[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            if (left > letters.Length - 1) return letters[0];
            return letters[left];
        }
    }
}