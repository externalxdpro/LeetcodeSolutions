namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
    // Integers in each row are sorted from left to right.
    // The first integer of each row is greater than the last integer of the previous row.

    // Example 1:
    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    // Output: true

    // Example 2:
    // Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    // Output: false

    // Constraints:
    // m == matrix.length
    // n == matrix[i].length
    // 1 <= m, n <= 100
    // -10^4 <= matrix[i][j], target <= 10^4

    public class SearchA2DMatrix_74
    {
        public bool SearchMatrix(int[][] matrix, int target)
        {
            for (int i = 0; i < matrix.Length; i++)
            {
                if (matrix[i][matrix[i].Length - 1] < target) continue;

                int left = 0;
                int right = matrix[i].Length - 1;

                while (left <= right)
                {
                    int mid = left + (right - left) / 2;

                    if (matrix[i][mid] == target)
                    {
                        return true;
                    }
                    else if (matrix[i][mid] > target)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }

                break;
            }

            return false;
        }
    }
}
