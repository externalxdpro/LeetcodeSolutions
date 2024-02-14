namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Given an array, rotate the array to the right by k steps, where k is non-negative.

    // Example 1:
    // Input: nums = [1,2,3,4,5,6,7], k = 3
    // Output: [5,6,7,1,2,3,4]
    // Explanation:
    // rotate 1 steps to the right: [7,1,2,3,4,5,6]
    // rotate 2 steps to the right: [6,7,1,2,3,4,5]
    // rotate 3 steps to the right: [5,6,7,1,2,3,4]

    // Example 2:
    // Input: nums = [-1,-100,3,99], k = 2
    // Output: [3,99,-1,-100]
    // Explanation:
    // rotate 1 steps to the right: [99,-1,-100,3]
    // rotate 2 steps to the right: [3,99,-1,-100]

    // Constraints:
    // 1 <= nums.length <= 105
    // -231 <= nums[i] <= 231 - 1
    // 0 <= k <= 105

    // Follow up:
    // Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
    // Could you do it in-place with O(1) extra space?

    public class RotateArray_189
    {
        public void Rotate(int[] nums, int k)
        {
            // Too slow for Leetcode
            // for (int i = 0; i < k; i++)
            // {
            //     int temp = nums[nums.Length - 1];

            //     for (int j = nums.Length - 1; j > 0; j--)
            //     {
            //         nums[j] = nums[j - 1];
            //     }

            //     nums[0] = temp;
            // }

            int[] temp = new int[nums.Length];
            int tempIndex = k;

            for (int i = 0; i < nums.Length; i++)
            {
                if (tempIndex > temp.Length - 1)
                {
                    if (i == 0)
                    {
                        tempIndex = 0;

                        for (int j = 0; j < k; j++)
                        {
                            tempIndex++;
                            if (tempIndex > temp.Length - 1) tempIndex = 0;
                        }
                    }
                    else
                    {
                        tempIndex = 0;
                    }
                }

                temp[tempIndex] = nums[i];
                tempIndex++;
            }

            for (int i = 0; i < temp.Length; i++)
            {
                nums[i] = temp[i];
            }
        }
    }
}
