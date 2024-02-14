namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
    // If target is not found in the array, return [-1, -1].

    // You must write an algorithm with O(log n) runtime complexity.

    // Example 1:
    // Input: nums = [5,7,7,8,8,10], target = 8
    // Output: [3,4]

    // Example 2:
    // Input: nums = [5,7,7,8,8,10], target = 6
    // Output: [-1,-1]

    // Example 3:
    // Input: nums = [], target = 0
    // Output: [-1,-1]

    // Constraints:
    // 0 <= nums.length <= 10^5
    // -10^9 <= nums[i] <= 10^9
    // nums is a non-decreasing array.
    // -10^9 <= target <= 10^9

    public class FindFirstAndLastPositionOfElementInSortedArray_34
    {
        public int[] SearchRange(int[] nums, int target)
        {
            int left = 0;
            int right = nums.Length - 1;
            int[] result = {-1, -1};

            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target)
                {
                    left = mid;
                    right = mid;

                    while (nums[left] == target)
                    {
                        result[0] = left;
                        left--;
                        if (left < 0) break;
                    }
                    while (nums[right] == target)
                    {
                        result[1] = right;
                        right++;
                        if (right > nums.Length - 1) break;
                    }

                    break;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            return result;
        }
    }

}
