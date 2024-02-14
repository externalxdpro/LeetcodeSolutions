namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

    // Example 1:
    // Input: c = 5
    // Output: true
    // Explanation: 1 * 1 + 2 * 2 = 5

    // Example 2:
    // Input: c = 3
    // Output: false

    // Constraints:
    // 0 <= c <= 2^31 - 1

    public class SumOfSquareNumber_633
    {
        public bool JudgeSquareSum(int c)
        {
            int cSqrt = (int)Math.Sqrt(c);
            for (long a = 0; a * a <= c; a++)
            {
                int left = 0;
                int right = cSqrt;
                int b = c - (int)(a * a);

                while (left <= right)
                {
                    int mid = left + (right - left) / 2;
                    long midSq = (long)mid * (long)mid;

                    if (midSq == b)
                    {
                        return true;
                    }
                    else if (midSq > b)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }

            return false;
        }
    }
}
