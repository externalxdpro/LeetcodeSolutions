namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    // Notice that the solution set must not contain duplicate triplets.

    // Example 1:
    // Input: nums = [-1,0,1,2,-1,-4]
    // Output: [[-1,-1,2],[-1,0,1]]
    // Explanation: 
    // nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    // nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    // nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    // The distinct triplets are [-1,0,1] and [-1,-1,2].
    // Notice that the order of the output and the order of the triplets does not matter.

    // Example 2:
    // Input: nums = [0,1,1]
    // Output: []
    // Explanation: The only possible triplet does not sum up to 0.

    // Example 3:
    // Input: nums = [0,0,0]
    // Output: [[0,0,0]]
    // Explanation: The only possible triplet sums up to 0.

    // Constraints:
    // 3 <= nums.length <= 3000
    // -10^5 <= nums[i] <= 10^5

    public class ThreeSum_15
    {
        bool EqualArray(List<int> arr1, List<int> arr2)
        {
            if (arr1.Count != arr2.Count) return false;
            for (int i = 0; i < arr1.Count; i++)
            {
                if (arr1[i] != arr2[i]) return false;
            }

            return true;
        }

        public IList<IList<int>> ThreeSum(int[] nums)
        {
            Array.Sort(nums);
            List<IList<int>> result = new List<IList<int>>();

            for (int digit1 = 0; digit1 < nums.Length; digit1++)
            {
                for (int digit2 = digit1 + 1; digit2 < nums.Length; digit2++)
                {
                    int left = digit2 + 1;
                    int right = nums.Length - 1;

                    while (left <= right)
                    {
                        int mid = left + (right - left) / 2;
                        int sum = nums[digit1] + nums[digit2] + nums[mid];

                        if (sum == 0)
                        {
                            List<int> temp = new List<int> {nums[digit1], nums[digit2], nums[mid]};
                            bool found = false;

                            foreach (List<int> list in result)
                            {
                                if (EqualArray(list, temp))
                                {
                                    found = true;
                                    break;
                                }
                            }

                            if (!found) result.Add(temp);
                            break;
                        }
                        else if (sum > 0)
                        {
                            right = mid - 1;
                        }
                        else
                        {
                            left = mid + 1;
                        }
                    }
                }
            }

            return result;
        }
    }
}