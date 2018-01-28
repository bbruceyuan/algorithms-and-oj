#!/usr/bin/env python
# Created by Bruce yuan on 18-1-23.


class Solution(object):
    def twoSum(self, nums, target):
        i = 0
        q = 0
        for i in range(0, len(nums)):
            m = target - nums[i]
            if m in nums:
                q = nums.index(m)
                if q != i:
                    break
        return [i, q]


class Solution2(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for index, item in enumerate(nums):
            if d.get(target - item, None) or d.get(target - item, None) == 0:
                return [d.get(target - item), index]
            else:
                d[item] = index

