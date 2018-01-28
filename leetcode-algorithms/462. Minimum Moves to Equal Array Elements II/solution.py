#!/usr/bin/env python
# Created by Bruce yuan on 18-1-28.


class Solution:
    """
    这是计算，经过多少步能够使得数字相等
    那意思很明显，我们只要找到中间值，
    大于它的就减去它，小于它的就被减，然后加起来就好了
    """
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)
        i, j = 0, len(nums) - 1
        count = 0
        while i < j:
            count += nums[j] - nums[i]
            i += 1
            j -= 1
        return count


if __name__ == '__main__':
    s = Solution()
    ans = s.minMoves2([1, 1, 1, 2, 2, 2])
    print(ans)
