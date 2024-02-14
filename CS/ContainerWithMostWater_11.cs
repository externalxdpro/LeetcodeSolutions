namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    // Find two lines that together with the x-axis form a container, such that the container contains the most water.
    // Return the maximum amount of water a container can store.
    // Notice that you may not slant the container.

    // Example 1:
    // Input: height = [1,8,6,2,5,4,8,3,7]
    // Output: 49
    // Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

    // Example 2:
    // Input: height = [1,1]
    // Output: 1

    // Constraints:
    // n == height.length
    // 2 <= n <= 105
    // 0 <= height[i] <= 104

    public class ContainerWithMostWater_11
    {
        public int MaxArea(int[] height)
        {
            // works, but too slow
            // runtime: Time Limit Exceeded
            // if (height.Length == 1)
            // {
            //     return height[0];
            // }

            // int result = 0;

            // for (int i = 0; i < height.Length; i++)
            // {
            //     for (int j = i + 1; j < height.Length; j++)
            //     {
            //         int temp = (j - i) * Math.Min(height[i], height[j]);
            //         if (temp > result)
            //         {
            //             result = temp;
            //         }

            //     }
            // }

            // return result;

            int result = 0;
            int i = 0;
            int j = height.Length - 1;
            
            while (i < j)
            {
                int temp = (j - i) * Math.Min(height[i], height[j]);

                result = Math.Max(result, temp);

                if (height[i] < height[j])
                    i++;
                else
                    j--;
            }

            return result;
        }
    }
}