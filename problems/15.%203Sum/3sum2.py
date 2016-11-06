#coding: utf-8

"""
想法都是一样的，不想写javascript版本了。
"""

class Solution(object):
    '''算法思路：
    同上，不过这次却巧妙去重
    '''
    def threeSum(self, nums):
        nums, n, r = sorted(nums), len(nums), []
        for i, target in enumerate(nums):
            if i and nums[i - 1] == target:
                continue

            j, k = i + 1, n - 1
            while j < k:
                sum = nums[j] + nums[k]
                if sum > -target:
                    k -= 1
                elif sum < -target:
                    j += 1
                else:
                    r.append([target, nums[j], nums[k]])
                    while j < k and nums[j + 1] == nums[j]:
                        j += 1
                    while j < k and nums[k - 1] == nums[k]:
                        k -= 1
                    j += 1
        return r