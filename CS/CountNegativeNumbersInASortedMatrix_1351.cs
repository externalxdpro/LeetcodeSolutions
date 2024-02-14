namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

    // Example 1:
    // Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    // Output: 8
    // Explanation: There are 8 negatives number in the matrix.

    // Example 2:
    // Input: grid = [[3,2],[1,0]]
    // Output: 0

    // Constraints:
    // m == grid.length
    // n == grid[i].length
    // 1 <= m, n <= 100
    // -100 <= grid[i][j] <= 100

    public class CountNegativeNumbersInASortedMatrix_1351
    {
        public int CountNegatives(int[][] grid)
        {
            int result = 0;

            for (int i = 0; i < grid.Length; i++)
            {
                int left = 0;
                int right = grid[i].Length - 1;

                while (left <= right)
                {
                    int mid = left + (right - left) / 2;

                    if (grid[i][mid] < 0)
                    {
                        left = mid;
                        right = mid;
                        result++;

                        while (left > 0)
                        {
                            left--;
                            if (grid[i][left] >= 0) break;
                            result++;
                        }
                        while (right < grid[i].Length - 1)
                        {
                            right++;
                            result++;
                        }

                        break;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }

            return result;
        }
    }
}
