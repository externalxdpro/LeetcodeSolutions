namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
    // A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    // Example 1:
    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    // Example 2:
    // Input: digits = ""
    // Output: []

    // Example 3:
    // Input: digits = "2"
    // Output: ["a","b","c"]

    // Constraints:
    // 0 <= digits.length <= 4
    // digits[i] is a digit in the range ['2', '9'].

    public class LetterCombinationsOfAPhoneNumber_17
    {
        public IList<string> LetterCombinations(string digits)
        {
            // Works, but can be faster
            // Dictionary<string, string[]> map = new Dictionary<string, string[]>()
            // {
            //     {"2", new string[] {"a", "b", "c"}},
            //     {"3", new string[] {"d", "e", "f"}},
            //     {"4", new string[] {"g", "h", "i"}},
            //     {"5", new string[] {"j", "k", "l"}},
            //     {"6", new string[] {"m", "n", "o"}},
            //     {"7", new string[] {"p", "q", "r", "s"}},
            //     {"8", new string[] {"t", "u", "v"}},
            //     {"9", new string[] {"w", "x", "y", "z"}}
            // };
            // List<string> result = new List<string>();
            // int digitsLen = digits.Length;

            // if (digitsLen == 0) return result;
            // foreach (string letter in map[$"{digits[0]}"])
            // {
            //     if (digitsLen == 1)
            //     {
            //         result.Add(letter);
            //     }
            //     else
            //     {
            //         foreach (string letter2 in map[$"{digits[1]}"])
            //         {
            //             if (digitsLen == 2)
            //             {
            //                 result.Add(letter + letter2);
            //             }
            //             else
            //             {
            //                 foreach (string letter3 in map[$"{digits[2]}"])
            //                 {
            //                     if (digitsLen == 3)
            //                     {
            //                         result.Add(letter + letter2 + letter3);
            //                     }
            //                     else
            //                     {
            //                         foreach (string letter4 in map[$"{digits[3]}"])
            //                         {
            //                             result.Add(letter + letter2 + letter3 + letter4);
            //                         }
            //                     }
            //                 }
            //             }
            //         }
            //     }
            // }

            // return result;

            if (digits.Length == 0) return new List<string>();

            string[] pad = new string[] {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

            List<string> result = new List<string> {""};

            foreach (char digit in digits)
            {
                List<string> temp = new List<string>();
                foreach (char candidate in pad[digit - '0'])
                {
                    foreach (string s in result)
                    {
                        temp.Add(s + candidate);
                    }
                }

                result = temp;
            }

            return result;
        }
    }
}