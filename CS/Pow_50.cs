namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

    // Example 1:
    // Input: x = 2.00000, n = 10
    // Output: 1024.00000

    // Example 2:
    // Input: x = 2.10000, n = 3
    // Output: 9.26100

    // Example 3:
    // Input: x = 2.00000, n = -2
    // Output: 0.25000
    // Explanation: 2-2 = 1/22 = 1/4 = 0.25

    // Constraints:
    // -100.0 < x < 100.0
    // -231 <= n <= 231-1
    // -104 <= xn <= 104

    public class Pow_50
    {
        // Works, but too slow for Leetcode
        // public double myPow(double x, int n)
        // {
        //     if (x == 1)
        //     {
        //         return 1;
        //     }
            
        //     double result = x;
            
        //     if (n > 0)
        //     {
        //         for (int i = 0; i < n - 1; i++)
        //         {
        //             result *= x;
        //         }   
        //     }
        //     else if (n < 0)
        //     {
        //         for (int i = 0; i > n + 1; i++)
        //         {
        //             result *= x;
        //         }

        //         result = 1 / result;
        //     }
        //     else if (n == 0)
        //     {
        //         return 1;
        //     }

        //     return result;
        // }

        public double MyPow(double x, int n)
        {
            if (n == 0 | x == 1) return 1;
            if (n == 1) return x;
            if (n < 0)
            {
                x = 1 / x;
                if (n % 2 == 0)
                    return MyPow(x * x, -(n / 2));
                else
                    return x * MyPow(x * x, -(n / 2));
            }

            if (n % 2 == 0)
                return MyPow(x * x, n / 2);
            else
                return x * MyPow(x * x, n / 2);
        }
    }
}
