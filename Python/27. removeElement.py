#!/usr/bin/env python3

class Solution:
    # def RemoveElement(nums: list[int], val: int) -> int:
    #     while val in nums:
    #         nums.remove(val)
    #     return nums

    def RemoveElement(nums: list[int], val: int) -> int:
        i = 0

        while i < len(nums):
            if nums[i] == val:
                nums.pop(i)
                i = i - 1
            i = i + 1

        return nums

    print(RemoveElement([3, 2, 2, 3], 3))
