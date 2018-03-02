#!/usr/bin/env python
# Created by BBruceyuan on 18-2-19.
"""
Assume we are dealing with an environment which could only hold
integers within the 32-bit signed integer range. 
For the purpose of this problem, assume that your function returns 0 
when the reversed integer overflows.
"""


class Solution(object):
    def reverse(self, x):
        """
        首先定义一下最大值
        :type x: int
        :rtype: int
        """
        # 这就是有32bit的最大数字 (其实有一个bit_length的方法)
        num_max = (1 << 31) - 1
        sum_ = 0
        flag = -1 if x < 0 else 1
        x = abs(x)
        while x != 0:
            sum_ = sum_ * 10 + x % 10
            x //= 10
        return 0 if sum_ > num_max else sum_ * flag


if __name__ == '__main__':
    s = Solution()
    print(s.reverse(-21))
