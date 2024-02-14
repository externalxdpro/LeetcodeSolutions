namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given a non-negative integer x, compute and return the square root of x.
    // Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

    // Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

    // Example 1:
    // Input: x = 4
    // Output: 2

    // Example 2:
    // Input: x = 8
    // Output: 2
    // Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

    // Constraints:
    // 0 <= x <= 2^31 - 1

    public class Sqrt_69
    {
        public int MySqrt(int x)
        {
            int left = 0;
            int right = x;

            while (left <= right)
            {
                double mid = left + (right - left) / 2;
                double midSq = mid * mid;

                if (midSq == x)
                {
                    return Convert.ToInt32(mid);
                }
                else if (midSq > x)
                {
                    right = Convert.ToInt32(mid - 1);
                }
                else
                {
                    left = Convert.ToInt32(mid + 1);
                }
            }

            return right;
        }
    }
}