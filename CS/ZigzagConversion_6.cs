namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    // P   A   H   N
    // A P L S I I G
    // Y   I   R
    // And then read line by line: "PAHNAPLSIIGYIR"

    // Write the code that will take a string and make this conversion given a number of rows:
    // string convert(string s, int numRows);
    
    // Example 1:
    // Input: s = "PAYPALISHIRING", numRows = 3
    // Output: "PAHNAPLSIIGYIR"

    // Example 2:
    // Input: s = "PAYPALISHIRING", numRows = 4
    // Output: "PINALSIGYAHRPI"
    // Explanation:
    // P     I    N
    // A   L S  I G
    // Y A   H R
    // P     I

    // Example 3:
    // Input: s = "A", numRows = 1
    // Output: "A"
    
    // Constraints:
    // 1 <= s.length <= 1000
    // s consists of English letters (lower-case and upper-case), ',' and '.'.
    // 1 <= numRows <= 1000

    public class ZigzagConversion_6
    {
        public string Convert(string s, int numRows) {
            // works, but unnecessary use of dictionary
            // Dictionary<int, string> dict = new Dictionary<int, string>();
            // bool reverse = false;

            // int dictIndex = 0;
            // for (int i = 0; i < s.Length; i++)
            // {
            //     if (dictIndex >= numRows)
            //     {
            //         reverse = true;
            //         dictIndex -= 2;
            //     }
            //     else if (dictIndex < 0)
            //     {
            //         reverse = false;
            //         dictIndex += 2;
            //     }
                
            //     if (dictIndex == -1)
            //     {
            //         dictIndex = 0;
            //     }
            //     else if (dictIndex == numRows)
            //     {
            //         dictIndex = numRows - 1;
            //     }

            //     if (!dict.ContainsKey(dictIndex))
            //     {
            //         dict.Add(dictIndex, char.ToString(s[i]));
            //     }
            //     else
            //     {
            //         dict[dictIndex] += char.ToString(s[i]);
            //     }

            //     if (reverse == false)
            //     {
            //         dictIndex++;
            //     }
            //     else
            //     {
            //         dictIndex--;
            //     }
            // }

            // string result = "";
            // for (int i = 0; i < dict.Count; i++)
            // {
            //     result += dict[i];
            // }
            // return result;

            string[] rows = new string[numRows];
            bool reverse = false;

            int rowIndex = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (rowIndex >= numRows)
                {
                    reverse = true;
                    rowIndex -= 2;
                }
                else if (rowIndex < 0)
                {
                    reverse = false;
                    rowIndex += 2;
                }

                if (rowIndex == -1)
                {
                    rowIndex = 0;
                }
                else if (rowIndex == numRows)
                {
                    rowIndex = numRows - 1;
                }

                if (rows[rowIndex] == "0")
                {
                    rows[rowIndex] = "" + s[i];
                }
                else
                {
                    rows[rowIndex] += char.ToString(s[i]);
                }

                if (reverse == false)
                {
                    rowIndex++;
                }
                else
                {
                    rowIndex--;
                }
            }

            string result = "";
            for (int i = 0; i < rows.Length; i++)
            {
                result += rows[i];
            }
            return result;
        }
    }
}
