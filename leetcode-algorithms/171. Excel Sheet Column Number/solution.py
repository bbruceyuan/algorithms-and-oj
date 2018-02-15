#!/usr/bin/env python
# Created by Bruce yuan on 18-2-15.


class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        sum_ = 0
        for index, item in enumerate(s[::-1]):
            sum_ += (ord(item) - 65 + 1) * (26 ** index)
        return sum_
