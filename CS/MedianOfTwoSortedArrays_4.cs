namespace LeetcodeSolutions
{
    // Difficulty: Hard
    // Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    // The overall run time complexity should be O(log (m+n)).

    // Example 1:
    // Input: nums1 = [1,3], nums2 = [2]
    // Output: 2.00000
    // Explanation: merged array = [1,2,3] and median is 2.

    // Example 2:
    // Input: nums1 = [1,2], nums2 = [3,4]
    // Output: 2.50000
    // Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

    // Constraints:
    // nums1.length == m
    // nums2.length == n
    // 0 <= m <= 1000
    // 0 <= n <= 1000
    // 1 <= m + n <= 2000
    // -10^6 <= nums1[i], nums2[i] <= 10^6

    public class MedianOfTwoSortedArrays_4
    {
        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int[] merged = new int[nums1.Length + nums2.Length];
            int num1 = 0, num2 = 0, mergedIndex = 0;

            while (mergedIndex < merged.Length)
            {
                if (num1 == nums1.Length)
                {
                    merged[mergedIndex] = nums2[num2];
                    num2++;
                    mergedIndex++;
                }
                else if (num2 == nums2.Length)
                {
                    merged[mergedIndex] = nums1[num1];
                    num1++;
                    mergedIndex++;
                }
                else
                {
                    if (nums1[num1] < nums2[num2])
                    {
                        merged[mergedIndex] = nums1[num1];
                        num1++;
                        mergedIndex++;
                    }
                    else
                    {
                        merged[mergedIndex] = nums2[num2];
                        num2++;
                        mergedIndex++;
                    }
                }
            }

            double result;
            if (merged.Length % 2 == 0)
            {
                result = merged[(merged.Length - 1) / 2] + merged[(merged.Length - 1) / 2 + 1];
                result /= 2;
            }
            else
            {
                result = merged[(merged.Length - 1) / 2];
            }

            return result;
        }
    }
}