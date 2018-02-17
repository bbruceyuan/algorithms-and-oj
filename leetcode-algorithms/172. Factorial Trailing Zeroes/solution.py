#!/usr/bin/env python
# Created by Bruce yuan on 18-2-16.
"""
这个为啥我看不懂啊，这东西好难啊，感觉智商下降的好厉害啊,
先提交一下，以后慢慢想
"""


class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        r = 0
        while n > 0:
            n //= 5
            r += n
        return r
