#!/usr/bin/env python
# Created by Bruce yuan on 18-1-28.


# TODO
# 这个还没有很好的理解？（差不多理解了？
# 好好理解！！！
class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(nums) - len(nums)*min(nums)

    @staticmethod
    def min_move_two(nums):
        """
        和上面那个其实是一样的，不过需要真的理解为什么要这么做
        :param nums: 
        :return: 
        """
        nums.sort()
        c = 0
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == nums[0]:
                break
            c += nums[i] - nums[0]
        return c
