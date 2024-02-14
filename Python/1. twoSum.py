#!/usr/bin/env python3

def twoSum(nums: list[int], target: int) -> list[int]:
    # works, will try while to see if its faster
    # runtime: 8078 ms
    # for i in range(len(nums) - 1):
    #     for j in range(i + 1, len(nums)):
    #         if nums[i] + nums[j] == target:
    #             return [i, j]

    # works, will try differences to optimize performance
    # runtime: 8671 ms
    # numsLen = len(nums)
    # i = 0
    # while i < numsLen  - 1:
    #     j = i + 1
    #     while j < numsLen :
    #         if nums[i] + nums[j] == target:
    #             return [i, j]
    #         j = j + 1
    #     i = i + 1

    # works, will try hashmaps and differences to optimize performance
    # for i in range(len(nums)):
    #     diff = target - nums[i]

    #     if diff in nums:
    #         if nums.index(diff) == i:
    #             continue
    #         return [i, nums.index(diff)]

    dictionary = {}
    for i, val in enumerate(nums):
        diff = target - val
        if diff in dictionary:
            return [i, dictionary[diff]]
        else:
            dictionary[val] = i


print(twoSum([2, 3, 2, 4], 6))
print("hello world")
