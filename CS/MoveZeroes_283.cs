namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    // Note that you must do this in-place without making a copy of the array.

    // Example 1:
    // Input: nums = [0,1,0,3,12]
    // Output: [1,3,12,0,0]

    // Example 2:
    // Input: nums = [0]
    // Output: [0]

    // Constraints:
    // 1 <= nums.length <= 104
    // -2^31 <= nums[i] <= 2^31 - 1

    // Follow up: Could you minimize the total number of operations done?

    public class MoveZeroes_283
    {
        public void MoveZeroes(int[] nums)
        {
            int[] temp = new int[nums.Length];
            int tempIndex = 0;

            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] == 0) continue;

                temp[tempIndex] = nums[i];
                tempIndex++;
            }

            for (int i = 0; i < nums.Length; i++)
            {
                nums[i] = temp[i];
            }
        }
    }
}
