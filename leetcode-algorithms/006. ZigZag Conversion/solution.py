#!/usr/bin/env python
# Created by BBruceyuan on 18-3-2.


class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or len(s) > numRows:
            return s

        ans = [''] * len(s)
        index = 0
        step = 1
        for x in s:
            ans[index] += x
            if index == 0:
                # 竖着走
                step = 1
            elif index == len(s) - 1:
                # 往回走
                step = -1
            index += step
        return ''.join(ans)

