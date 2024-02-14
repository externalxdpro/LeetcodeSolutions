#!/usr/bin/env python3

class Solution:
    def removeDuplicates(nums: list[int]) -> int:
        i = 0

        while i < len(nums) - 1:
            if nums[i] == nums[i + 1]:
                nums.pop(i)
                i = i - 1

            i = i + 1

        return nums

    print(removeDuplicates([0, 0, 1, 1, 1, 2, 2, 3, 3, 4]))
