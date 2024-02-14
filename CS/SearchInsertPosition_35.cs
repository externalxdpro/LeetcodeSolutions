namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
    // You must write an algorithm with O(log n) runtime complexity.

    // Example 1:
    // Input: nums = [1,3,5,6], target = 5
    // Output: 2

    // Example 2:
    // Input: nums = [1,3,5,6], target = 2
    // Output: 1

    // Example 3:
    // Input: nums = [1,3,5,6], target = 7
    // Output: 4

    // Constraints:
    // 1 <= nums.length <= 104
    // -104 <= nums[i] <= 104
    // nums contains distinct values sorted in ascending order.
    // -104 <= target <= 104

    public class SearchInsertPosition_35
    {
        // Recursive
        // int BinarySearch(int[] nums, int target, int left, int right)
        // {
        //     if (left > right) return left;
            
        //     int mid = (left + right) / 2;

        //     if (nums[mid] == target)
        //     {
        //         return mid;
        //     }
        //     else if (nums[mid] > target)
        //     {
        //         return BinarySearch(nums, target, left, mid - 1);
        //     }
        //     else
        //     {
        //         return BinarySearch(nums, target, mid + 1, right);
        //     }
        // }

        // public int SearchInsert(int[] nums, int target)
        // {
        //     return BinarySearch(nums, target, 0, nums.Length - 1);
        // }

        // Iterative
        public int SearchInsert(int[] nums, int target)
        {
            int left = 0;
            int right = nums.Length - 1;

            int mid;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }


            }

            return left;
        }
    }
}