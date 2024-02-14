namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given a positive integer num, write a function which returns True if num is a perfect square else False.
    // Follow up: Do not use any built-in library function such as sqrt.

    // Example 1:
    // Input: num = 16
    // Output: true

    // Example 2:
    // Input: num = 14
    // Output: false

    // Constraints:
    // 1 <= num <= 2^31 - 1

    public class ValidPerfectSquare_367
    {
        public bool IsPerfectSquare(int num)
        {
            if (num == 0) return true;

            int left = 1;
            int right = num;

            while (left <= right)
            {
                double mid = left + (right - left) / 2;
                double midSq = mid * mid;

                if (midSq == num)
                {
                    return true;
                }
                else if (midSq > num)
                {
                    right = Convert.ToInt32(mid - 1);
                }
                else if (midSq < num)
                {
                    left = Convert.ToInt32(mid + 1);
                }
            }

            return false;
        }
    }
}