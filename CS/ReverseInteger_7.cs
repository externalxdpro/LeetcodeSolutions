namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    // Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    // Example 1:
    // Input: x = 123
    // Output: 321

    // Example 2:
    // Input: x = -123
    // Output: -321

    // Example 3:
    // Input: x = 120
    // Output: 21

    // Constraints:
    // -2^31 <= x <= 2^31 - 1

    public class ReverseInteger_7
    {
        public int Reverse(int x)
        {
            int sign = 1;
            int result = 0;

            if (x < 0)
            {
                sign = -1;
                x *= -1;
            }

            while (x > 0)
            {
                if (result * sign > int.MaxValue / 10 || result * sign < int.MinValue / 10)
                {
                    return 0;
                }

                result = result * 10 + x % 10;
                x /= 10;
            }

            result *= sign;
            if (result != Int32.MinValue)
            {
                return result;
            }
            else
            {
                return 0;
            }
        }
    }
}