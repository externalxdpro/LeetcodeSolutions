namespace LeetcodeSolutions
{
    // Difficulty: Easy
    // Given an array arr of integers, check if there exist two indices i and j such that :
    // i != j
    // 0 <= i, j < arr.length
    // arr[i] == 2 * arr[j]

    // Example 1:
    // Input: arr = [10,2,5,3]
    // Output: true
    // Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

    // Example 2:
    // Input: arr = [3,1,7,11]
    // Output: false
    // Explanation: There is no i and j that satisfy the conditions.

    // Constraints:
    // 2 <= arr.length <= 500
    // -10^3 <= arr[i] <= 10^3

    public class CheckIfNAndItsDoubleExist_1346
    {
        public bool CheckIfExist(int[] arr)
        {
            Array.Sort(arr);

            for (int i = 0; i < arr.Length; i++)
            {
                int left;
                int right;

                if (arr[i] < 0)
                {
                    left = 0;
                    right = i - 1;
                }
                else
                {
                    left = i + 1;
                    right = arr.Length - 1;
                }
                int iDoubled = arr[i] * 2;

                while (left <= right)
                {
                    int mid = left + (right - left) / 2;

                    if (arr[mid] == iDoubled)
                    {
                        return true;
                    }
                    else if (arr[mid] > iDoubled)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }

            return false;
        }
    }
}
